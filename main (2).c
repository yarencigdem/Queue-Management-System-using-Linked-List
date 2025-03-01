#include <stdio.h>
#include <stdlib.h>


struct Musteri {
    int id;
    struct Musteri* next;
};


struct Musteri* bas = NULL;

void kuyrugaEkle(int id) {
   
    struct Musteri* yeniMusteri = (struct Musteri*)malloc(sizeof(struct Musteri));
    yeniMusteri->id = id;
    yeniMusteri->next = NULL;

   
    if (bas == NULL || id == 1) {
        if (bas == NULL) {
            bas = yeniMusteri;
        } else {
            struct Musteri* temp = bas;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = yeniMusteri;
        }
    }
  
    else if (id == 2) {
        if (bas->next != NULL) {
            struct Musteri* temp = bas->next;
            while (temp->next != NULL && temp->next->next->next != NULL) {
                temp = temp->next;
            }
            yeniMusteri->next = temp->next;
            temp->next = yeniMusteri;
        } else {
            yeniMusteri->next = bas->next;
            bas->next = yeniMusteri;
        }
    }
   
    else if (id == 3) {
        yeniMusteri->next = bas;
        bas = yeniMusteri;
    }
}


void kuyruktanCikar() {
    if (bas == NULL) {
        printf("Kuyruk bos.\n");
    } else {
        struct Musteri* temp = bas;
        bas = bas->next;
        free(temp);
    }
}


void kuyrukuYazdir() {
    struct Musteri* temp = bas;
    while (temp != NULL) {
        printf("ID: %d\n", temp->id);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int idNo,i,n;
    printf("Musteri sayisini giriniz:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("id no giriniz 1,2 veya 3: \n");
        scanf("%d",&idNo);
        kuyrugaEkle(idNo);
        
    }

    printf("Kuyruk Baslangici:\n");
    kuyrukuYazdir();

    printf("Musteri cikarildi:\n");
    kuyruktanCikar();
    kuyrukuYazdir();

    return 0;
}
