#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 100005;
typedef long long ll;
int n,q,top;
ll a[MAXN],op[MAXN],t[MAXN],d[MAXN];
inline int getnext(ll k,int r)
{
	int l=1,mid,ret=-1;
	while(l<=r){
		mid=(l+r)>>1;
		if(op[mid]<=k)l=mid+1,ret=mid;
		else r=mid-1;
	}
	return ret;
}
int main()
{
	scanf("%d%d",&n,&q);
	stk[++top]=n;
	for(int i=1;i<=q;++i){
		scanf("%lld",a+i);
		while(top && op[top]>=a[i])--top;
		op[++top]=a[i];
	}
	ll k;
	t[top]=1;
	for(int i=top;i;--i){
		k=op[i];
		while(k){
			int p=getnext(k,i-1);
			if(p==-1)break;
			t[p]+=k/op[p]*t[i];
			k%=op[p];
		}
		d[1]+=t[i],d[k+1]-=t[i];
	}
	for(int i=1;i<=n;++i)
		printf("%lld\n",d[i]+=d[i-1]);
	return 0;
}
