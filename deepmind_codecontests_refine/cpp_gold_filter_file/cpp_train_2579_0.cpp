#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
const int M=1000000007;
typedef long long ll;
int p[maxn],n,ans,f[maxn],cc,dp[maxn],pre[maxn],sz[maxn],cy[maxn],a[maxn],jc[maxn];
void sub(int &x,int y){x-=y;if (x<0) x+=M;}
void add(int &x,int y){x+=y;if (x>=M)x-=M;}
int ffind(int x){
    if (pre[x]==x) return x;
    return pre[x]=ffind(pre[x]);
}
void _union(int x,int y){
    x=ffind(x); y=ffind(y);
    if (x==y) {cy[x]=1;return;}
    pre[y]=x; sz[x]+=sz[y]; cy[x]|=cy[y];
}
int main(){
    cin >> n;
    jc[0]=1; for (int i=1;i<=n;i++) jc[i]=1ll*jc[i-1]*i%M;
    for (int i=1;i<=n;i++) cin >> p[i];
    for (int i=1;i<=n;i++) pre[i]=i,cy[i]=0,sz[i]=1;
    for (int i=1;i<=n;i++) if (p[i]!=-1) _union(i,p[i]);
    f[0]=1; for (int i=1;i<=n;i++) f[i]=1ll*f[i-1]*(n-1)%M;
    int zt=0;
    for (int i=1;i<=n;i++) if (ffind(i)==i){
        if (cy[i]) {++zt;continue;}
        a[++cc]=sz[i];
    }
    ans=1ll*f[cc]*(n-zt)%M;
    dp[0]=1;
    for (int i=1;i<=cc;i++){
        for (int j=i;j;j--) add(dp[j],1ll*dp[j-1]*a[i]%M);
    }
    for (int i=2;i<=cc;i++) sub(ans,1ll*f[cc-i]*jc[i-1]%M*dp[i]%M);
    for (int i=1;i<=cc;i++) sub(ans,1ll*f[cc-1]*(a[i]-1)%M);
    cout << ans << endl;
    return 0;
}
