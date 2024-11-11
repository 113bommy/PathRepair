#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=35;
ll f[N];
ll dis(ll x1,ll y1,ll x2,ll y2){return abs(x1-x2)+abs(y1-y2);}
ll solve(ll x1,ll y1,ll x2,ll y2,ll level)
{
    if(level==0) return return abs(y1-y2);
    ll w=f[level-1];
    if(x1/w!=x2/w) return dis(x1,y1,x2,y2);
    if(x1/w==1&&abs(y1/w-y2/w)>=2)
        return abs(y1-y2)+min(x1%w+x2%w+2,(w-x1%w)+(w-x2%w));
    return solve(x1%w,y1,x2%w,y2,level-1);
}
int main()
{
    f[0]=1;for(int i=1;i<N;i++) f[i]=f[i-1]*3;
    int q;scanf("%d",&q);
    while(q--)
    {
        ll x1,y1,x2,y2;
        scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
        x1--;y1--;x2--;y2--;
        if(abs(x1-x2)>abs(y1-y2)) swap(x1,y1),swap(x2,y2);
        printf("%lld\n",solve(x1,y1,x2,y2,30));
    }
}
