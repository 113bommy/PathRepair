#include<stdio.h>
int main()
{
    char s[20];
    int x=0;
    int i=0;
    scanf("%s",s);
    for(;i<20;i++) x+=s[i]=='x';
    if(x>7) printf("NO\n");
    else printf("YES\n");
    return 0;
}