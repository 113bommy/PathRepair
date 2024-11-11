#include<cstdio>
char s[100005];
int ans;
int main(){
    scanf("%s",s);
    for(int i=1;s[i];i++)
    if(s[i]!=s[i-1])ans++;
    printf("%d\n",ans);
}