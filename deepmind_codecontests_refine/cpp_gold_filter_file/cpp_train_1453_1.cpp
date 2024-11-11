#include<iostream>
#include<cstdio>

using namespace std;

int n,q;
int tree[100050];

int Find(int x)
{
    if(tree[x]==x)
        return x;
    return Find(tree[x]);
}

int main()
{
    while(scanf("%d %d",&n,&q)==2)
    {
        if(n==0&&q==0)
            break;
        tree[1]=1;
        for(int i=2;i<=n;i++)
            scanf("%d",&tree[i]);
        getchar();
        long long ans=0;
        for(int i=1;i<=q;i++)
        {
            int temp;
            char s[100];
            gets(s);
            sscanf(&s[2],"%d",&temp);
            if(s[0]=='M')
                tree[temp]=temp;
            else if(s[0]=='Q')
                ans+=Find(temp);
        }
        cout<<ans<<endl;
    }

    return 0;
}