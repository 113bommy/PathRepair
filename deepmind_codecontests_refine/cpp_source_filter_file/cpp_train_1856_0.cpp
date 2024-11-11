//problem:arc101F
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define lob lower_bound
#define upb upper_bound
#define fst first
#define scd second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

inline int read(){
	int f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline ll readll(){
	ll f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=1e5+5,MOD=1e9+7;
int n,m,a[MAXN],b[MAXN];
pii p[MAXN];
inline mod(int x){return x<MOD?x:x-MOD;}
struct BIT{
	int c[MAXN];
	inline int lb(int x){return x&(-x);}
	void add(int p,int v){for(;p<=n;p+=lb(p))c[p]=mod(c[p]+v);}
	int ask(int p){int r=1;for(;p;p-=lb(p))r=mod(r+c[p]);return r;}
	BIT(){}
}T;
int main() {
	n=read();m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=m;++i)b[i]=read();
	int cnt=0;vector<int>vec;
	for(int i=1;i<=n;++i){
		if(a[i]<b[1]||a[i]>b[m])continue;
		int t=lob(b+1,b+n+1,a[i])-b;
		assert(t>1&&t<=m);
		p[++cnt]=mk(a[i]-b[t-1],b[t]-a[i]);
		vec.pb(p[cnt].scd);
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	n=cnt;sort(p+1,p+n+1);
	for(int i=1,j=1;i<=n;i=j){
		int L=p[i].fst;
		while(j<=n&&p[j].fst==L)++j;
		for(int k=j-1;k>=i;--k){
			int R=lob(vec.begin(),vec.end(),p[k].scd)-vec.begin()+1;
			if(k!=j-1&&p[k].scd==p[k+1].scd)continue;
			T.add(R,T.ask(R-1));
		}
	}
	cout<<T.ask(vec.size())<<endl;
	return 0;
}