#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10,p=924844033;
int inc(int x,int y){x+=y;return x>=p?x-p:x;}
int dec(int x,int y){x-=y;return x<0?x+p:x;}
int mul(int x,int y){return (ll)x*y%p;}
int power(int x,int y){
    int ans=1;
    for (;y;y>>=1,x=mul(x,x))
        if (y&1) ans=mul(ans,x);
    return ans;
}
int w[N],iw[N];
void init(int n){
    w[0]=1;w[1]=power(5,(p-1)/n);
    for (int i=2;i<=n;i++) w[i]=mul(w[i-1],w[1]);
    for (int i=0;i<=n;i++) iw[i]=w[n-i];
}
void fft(int n,int *a,int *w){
    for (int i=0,j=0;i<n;i++){
        if (i<j) swap(a[i],a[j]);
        for (int k=n>>1;(j^=k)<k;k>>=1);
    }
    for (int i=2;i<=n;i<<=1){
        int m=i>>1,step=n/i;
        for (int j=0;j<n;j+=i)
        for (int k=0,pos=0;k<m;k++,pos+=step){
            int t=mul(a[j+k+m],w[pos]);
            a[j+k+m]=dec(a[j+k],t);
            a[j+k]=inc(a[j+k],t);
        }
    }
    if (w==iw){
        int del=power(n,p-2);
        for (int i=0;i<n;i++) a[i]=mul(a[i],del);
    }
}
int n,e[N],head[N],next[N];
void add(int f,int t){
    static int cnt=0;
    e[++cnt]=t;
    next[cnt]=head[f];
    head[f]=cnt;
}
int size[N];
void dfs(int x,int fa){
    size[x]=1;
    for (int i=head[x];i;i=next[i]){
        int v=e[i];
        if (v==fa) continue;
        dfs(v,x);
        size[x]+=size[v];
    }
}
int cnt[N],fac[N],ifac[N],f[N],g[N];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    dfs(1,0);
    cnt[n]=n;
    for (int i=2;i<=n;i++)
        cnt[size[i]]--,cnt[n-size[i]]--;
    for (int i=1;i<=n;i++)
        if (cnt[i]<0) cnt[i]+=p;
    fac[0]=1;
    for (int i=1;i<=n;i++) fac[i]=mul(fac[i-1],i);
    ifac[n]=power(fac[n],p-2);
    for (int i=n;i;i--) ifac[i-1]=mul(ifac[i],i);
    for (int i=0;i<=n;i++) g[i]=mul(cnt[i],fac[i]),f[i]=ifac[n-i];
    int size=1;
    while (size<=n+n) size<<=1;
    init(size);
    fft(size,f,w);fft(size,g,w);
    for (int i=0;i<size;i++) f[i]=mul(f[i],g[i]);
    fft(size,f,iw);
    for (int i=1;i<=n;i++) printf("%d\n",mul(f[i+n],ifac[i]));
    return 0;
}