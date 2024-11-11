#include<bits/stdc++.h>
char s[100007];
int g[128];
int main()
{
    g['b'] = 0 , g['p'] = 1 , g['d'] = 2 , g['q'] = 3;
    scanf("%s",s+1);
    for(int l = strlen(s+1),i=1;i<=(l>>1)+1;i++)
    {
        if(get[s[i]]^((get[s[l-i+1]]+2)%4)) return printf("No\n"),0;
    }  
    return printf("Yes\n"),0;
}