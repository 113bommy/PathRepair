a#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

#define fo(i,j,l) for(int i=j;i<=l;++i)
#define fd(i,j,l) for(int i=j;i>=l;--i)

using namespace std;
typedef long long ll;
const ll N=10010;

int n,oo;
ll a[N],b[N];

int ss[N];
bool bz[N];

inline ll gcd(ll a,ll b)
{return (b==0)?a:(gcd(b,a%b));}

int main()
{
	scanf("%d",&n);
	ll gg=0;
	fd(i,n,0)scanf("%lld",&a[i]),gg=gcd(gg,(a[i]>0)?(a[i]):(-a[i]));
	fo(i,2,n){
		if(!bz[i])ss[++oo]=i;
		fo(j,1,oo)if(i*ss[j]<=n){
			bz[i*ss[j]]=true;
			if(i%ss[j]==0)break;
		}else break;
	}
	fo(i,1,oo)if(a[0]%ss[i]==0){
		int t=ss[i]-1,mo=ss[i];
		fo(l,0,n-1)b[l]=a[l+1]%mo;
		fd(l,n-1,t)b[l-t]=(b[l-t]+b[l])%mo;
		int ok=1;
		fo(l,0,t-1)ok=ok&(b[l]==0)%mo;
		if(ok)printf("%d\n",mo);
	}
	int sr=sqrt(gg);
	int lef=gg;
	fo(i,2,sr)if(lef%i==0){
		while(lef%i==0)lef/=i;
		if(i>n)printf("%d\n",i);
	}
	if(lef>n)printf("%d\n",lef);
}