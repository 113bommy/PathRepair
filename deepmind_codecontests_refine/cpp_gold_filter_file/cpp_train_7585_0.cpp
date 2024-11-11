#include<stdio.h>
int way[200];
int a,b;
int cou=0;
int main()
{
    while(scanf("%d%d",&a,&b)!=-1)
    {
        for(int i=0;i<200;i++)
        {
            way[i]=0;
        }
        cou=0;
        way[a]++;
        way[b]++;
        while(1)
        {
            scanf("%d%d",&a,&b);
            if(a==0&&b==0)break;
            way[a]++;
            way[b]++;
        }
        if(way[1]%2==1&&way[2]%2==1)
        {
            cou=0;
            for(int i=3;i<200;i++)
            {
                if(way[i]%2!=0)break;
                cou++;
            }
            if(cou==197)printf("OK\n");
            else printf("NG\n");
        }
        else printf("NG\n");
    }
    return 0;
}