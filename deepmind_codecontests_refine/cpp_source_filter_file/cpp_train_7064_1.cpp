#include<bits/stdc++.h>
char str[256],*c,*f;
int main(void){
    scanf("%s",str);
    c=strchr(str,'c');
    if(c!=NULL)f=strchr(c+1,'f');
    printf("%s",c!=NULL&&f!=NULL?"Yes":"No");
    reutrn 0;
}