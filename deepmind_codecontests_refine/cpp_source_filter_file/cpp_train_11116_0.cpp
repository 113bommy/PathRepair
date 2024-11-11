#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define db double
#define pint pair<int,int>
#define mk(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define fi first
#define se second
#define Rep(x,y,z) for(int x=y;x<=z;x++)
#define Red(x,y,z) for(int x=y;x>=z;x--)
using namespace std;
char buf[1<<12],*pp1=buf,*pp2=buf,nc;int ny;
inline char gc() {return pp1==pp2&&(pp2=(pp1=buf)+fread(buf,1,1<<12,stdin),pp1==pp2)?EOF:*pp1++;}
//inline char gc(){return getchar();}
inline ll read(){
	ll x=0;for(ny=1;nc=gc(),(nc<48||nc>57)&&nc!=EOF;)if(nc==45)ny=-1;if(nc<0)return nc;
	for(x=nc-48;nc=gc(),47<nc&&nc<58&&nc!=EOF;x=(x<<3)+(x<<1)+(nc^48));return x*ny;
}
const int table[6][20] = {{},
  {1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 4, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 36, 108, 220, 334, 384, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 976, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001}};
int G[105];
inline void Init(){G[1]=0;Rep(n,2,100)for(int k=1;k<n;k++)if((1<<k)>=n&&(1<<k)-n>=G[k]){G[n]=k;break;}}
inline int g(ll n){
	if(n<=100)return G[n];
	for(int k=1;;k++)if((1ll<<k)>=n&&(1ll<<k)-n>=g(k))
		return k;
}
ll n;
inline int Solve(ll n,int k){
	if(n<k)swap(n,k);
	if(k<63&&(1ll<<k)-n<n)return Solve((1ll<<k)-n,k);
	if(k>5)return 1001;return k==0?1:table[k][n];
}
int main(){
//	freopen("std.in","r",stdin);
//	freopen("std.out","w",stdout);
	n=read(),Init();
	int ans=Solve(n,g(n));ans+=(n==4)+(n==7)*2;
	cout<<(ans>1000?-1:ans);
	return 0;
}


