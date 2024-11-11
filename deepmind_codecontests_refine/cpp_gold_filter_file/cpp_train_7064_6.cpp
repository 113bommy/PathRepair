#include<bits/stdc++.h>
char str[256],*c,*f;
int main(void){
    scanf("%s",str);
    c=strchr(str,'C');
    if(c!=NULL) f=strchr(c+1,'F');
    printf("%s",c!=NULL&&f!=NULL?"Yes":"No");
    return 0;
}