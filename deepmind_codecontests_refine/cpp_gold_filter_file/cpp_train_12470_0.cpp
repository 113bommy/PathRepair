#include<bits/stdc++.h>
#define LL long long
using namespace std;

const LL N=2e5+5;

LL n,T,b[N],ans,f[N],tot1,tot2;

struct node{
	LL x;
	LL y;
}a[N];

bool mycmp(node x,node y){
	return x.x*(y.y+1)>y.x*(x.y+1);
}

int main(){
	scanf("%lld%lld",&n,&T);
	for (int i=1;i<=n;i++){
		LL x,y;
		scanf("%lld%lld",&x,&y);
		if (x==0) b[++tot2]=y+1;
		else a[++tot1]={x,y};
	}
	sort(a+1,a+tot1+1,mycmp);
	sort(b+1,b+tot2+1);
	for (int i=1;i<=35;i++) f[i]=T+1;
	for (int i=1;i<=tot1;i++)
		for (int j=35;j>=1;j--)
			f[j]=min(f[j],(f[j-1]+1)*(a[i].x+1)+a[i].y);
	for (int i=1;i<=tot2;i++) b[i]+=b[i-1];
	for (int i=0;i<=35;i++){
		if (f[i]>T) continue;
		LL x=0;
		if (tot2) x=upper_bound(b+1,b+tot2+1,T-f[i])-(b+1);
		ans=max(ans,i+x);
	}
	printf("%lld\n",ans);
	return 0;
}