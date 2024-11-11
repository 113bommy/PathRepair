#include<cstdio>
#include<<cstring>

int main(){
    char s[201],p[101],s1[101];
    scanf("%s %s",s,p);
    strcpy(s1,s);
    strcat(s,s1);
    if(strstr(s,p)==NULL) printf("No\n");
    else printf("Yes\n")
    return 0;
}
