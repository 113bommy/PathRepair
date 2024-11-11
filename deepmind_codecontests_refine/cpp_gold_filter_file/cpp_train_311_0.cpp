#include <stdio.h>
int main(){
    int H,W,i,j;
    
    while(scanf("%d%d",&H,&W),H|W){    
        for(i=0;i<H;i++){
            for(j=0;j<W;j++) printf("%c",(i+j)%2?'.':'#');
            printf("\n");    
        }
    printf("\n");       
    }
    return 0;
}