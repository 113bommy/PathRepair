#include<cstdio>
char s[1e5+5];
int ans;
int main(){
    scanf("%s",s);
    for(int i=1;s[i];i++)
    if(s[i]!=s[i-1])ans++;
    printf("%d\n",ans);
}