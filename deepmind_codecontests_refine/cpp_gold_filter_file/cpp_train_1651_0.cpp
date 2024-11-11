#include<bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
int fact[200010],ifact[200010],c[200010],w[200010],mnw[200010],cnt[200010],p[200010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),X=gi(),Y=gi(),ans=1;
	fact[0]=1;for(int i=1;i<=n;++i)fact[i]=1ll*fact[i-1]*i%mod;
	ifact[n]=pow(fact[n],mod-2);for(int i=n;i;--i)ifact[i-1]=1ll*ifact[i]*i%mod;
	for(int i=0;i<=n;++i)mnw[i]=1e9;
	for(int i=1;i<=n;++i)c[i]=gi(),w[i]=gi(),mnw[c[i]]=std::min(mnw[c[i]],w[i]);
	for(int i=1;i<=n;++i)
		if(mnw[c[i]]+w[i]<=X)w[i]=mnw[c[i]],++cnt[c[i]];
		else if(w[i]==mnw[c[i]])++cnt[c[i]];
	int mn=0,cmn=0;
	for(int i=1;i<=n;++i){
		if(mnw[mn]>mnw[i])cmn=mn,mn=i;
		else if(mnw[cmn]>mnw[i])cmn=i;
	}
	int sz=cnt[mn];
	for(int i=1;i<=n;++i)if(c[i]!=mn&&mnw[mn]+w[i]<=Y)++sz,++p[c[i]];
	if(sz==cnt[mn])return puts("1"),0;
	for(int i=1;i<=n;++i)if(c[i]==mn&&w[i]!=mnw[mn]&&mnw[cmn]+w[i]<=Y)++sz,++p[c[i]];
	p[mn]+=cnt[mn];
	ans=fact[sz];
	for(int i=1;i<=n;++i)ans=1ll*ans*ifact[p[i]]%mod;
	printf("%d\n",ans);
	return 0;
}
