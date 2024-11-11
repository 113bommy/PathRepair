#include<cstdio>
int main(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a+b>c+d) puts("Left");
    else if(a+b<c+d) puts("Right")
    else puts("Balanced");
}