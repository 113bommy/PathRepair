#include<stdio.h>
int main(){
    int m, f, r;
    int TRUE=1;
    for(;;){
        scanf("%d %d %d", &m, &f, &r);
        if(m==-1&&f==-1&&r==-1)break;
        if(m==-1 || f==-1)printf("F\n");;
        else if(m+f>=80)printf("A\n");
        else if(m+f>=65)printf("B\n");
        else if(m+f>=50 || r>=50)printf("C\n");
        else if(m+f>=30)printf("D\n");
        else printf("F\n");
    }
    return 0;
}