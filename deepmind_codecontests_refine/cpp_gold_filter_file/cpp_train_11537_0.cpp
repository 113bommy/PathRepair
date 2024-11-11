#include<bits/stdc++.h>
using namespace std;
long long s[100007],t[100007];
int main(){
    long long n,m,q;
    scanf("%lld%lld%lld",&n,&m,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&s[i]);
    s[n+1]=1e18;
    s[0]=-1e18;
    sort(s,s+n+2);
    for(int i=1;i<=m;i++)
        scanf("%lld",&t[i]);
    t[m+1]=1e18;
    t[0]=-1e18;
    sort(t,t+m+2);
    long long x=0;
    long long tmp1=0,tmp2=0;
    long long ans=0;
    for(int i=1;i<=q;i++){
        scanf("%lld",&x);
        tmp1=lower_bound(s,s+n+2,x)-s;
        tmp2=lower_bound(t,t+m+2,x)-t;
        ans=1e18;
        for(int j=tmp1-1;j<tmp1+1;j++){
            for(int k=tmp2-1;k<tmp2+1;k++){
                ans=min(ans,abs(x-s[j])+abs(s[j]-t[k]));
                ans=min(ans,abs(x-t[k])+abs(s[j]-t[k]));
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
