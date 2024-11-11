#include<stdio.h>
int main(){
        int a,b;
        scanf("%d %d",&a,&b);
        if(a+b == 15)putchar('+');
        else if(a*b == 15)putchar('*');
        else putchar('x');
        return 0;
}
