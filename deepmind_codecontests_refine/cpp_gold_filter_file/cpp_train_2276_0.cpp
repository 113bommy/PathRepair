#include <stdio.h>
int main()
{
    int a,b,c,i,ans=0;
    scanf("%d %d %d",&a,&b,&c);
    int s[a];
    for(i=0;i<a;i++)
    {
        scanf("%d",&s[i]);
        if(s[i]<b||s[i]>=c)
            ans++;
    }
    printf("%d\n",ans);
}