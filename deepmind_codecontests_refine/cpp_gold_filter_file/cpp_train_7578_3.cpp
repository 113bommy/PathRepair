#include<bits/stdc++.h>
#define maxn 10010
using namespace std;
template<typename T> inline void read(T &x)
{
    x=0;char c=getchar();bool flag=false;
    while(!isdigit(c)){if(c=='-')flag=true;c=getchar();}
    while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    if(flag)x=-x;
}
int n,g,d_cnt;
int a[maxn],b[maxn],d[maxn];
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
bool pri(int x)
{
    int lim=sqrt(x);
    for(int i=2;i<=lim;++i)
        if(x%i==0)
            return false;
    return true;
}
void work(int x)
{
    int lim=sqrt(x);
    for(int i=2;i<=lim;++i)
    {
        if(x%i) continue;
        d[++d_cnt]=i;
        while(x%i==0) x/=i;
    }
    if(x>1) d[++d_cnt]=x;
}
bool check(int p)
{
    if(a[0]%p) return false;
    memcpy(b,a,sizeof(a));
    for(int i=n;i>=p-1;--i)
        b[i-(p-1)]=(b[i-(p-1)]+b[i])%p,b[i]=0;
    for(int i=0;i<=n;++i)
        if(b[i]%p)
            return false;
    return true;
}
int main()
{
    read(n);
    for(int i=n;i>=0;--i)
        read(a[i]),g=gcd(g,abs(a[i]));
    work(g);
    for(int i=2;i<=n;++i)
        if(pri(i)&&check(i))
            d[++d_cnt]=i;
    sort(d+1,d+d_cnt+1);
    for(int i=1;i<=d_cnt;++i)
        if(d[i]!=d[i-1])
            printf("%d\n",d[i]);
    return 0;
}