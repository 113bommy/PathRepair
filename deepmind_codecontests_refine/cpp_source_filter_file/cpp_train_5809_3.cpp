#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define maxn 100010
ll n,a[maxn],b[maxn],m;

ll cmp(const void *x,const void *y){
	return (*(ll*)x-*(ll*)y);
}

int chk_id(ll x){
	int l=1,r=n,mid,ans=n+1;
	for(;l<=r;){
		mid=l+r>>1;
		if(x<=a[mid])r=(ans=mid)-1;
		else l=mid+1;
	}
	return ans;
}

int chk(ll mid){
	ll cnt=0;
	int i;
	for(i=1;i<=n;++i)
		cnt+=n+1-chk_id(mid-a[i]);
	if(cnt>=m)return 1;
	else return 0;
}

void solve(){
	int i;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%lld",a+i);
	qsort(a+1,n,sizeof(ll),cmp);
	
	for(i=1;i<=n;++i)
		fprintf(stderr,"%d ",a[i]);
	fprintf(stderr,"\n");
	for(i=1;i<=n;++i)
		b[i]=b[i-1]+a[i];
	ll mid,l=0,r=(ll)1e15,res=-1;
	for(;l<=r;){
		mid=l+r>>1;
		if(chk(mid))l=(res=mid)+1;
		else r=mid-1;
	}
	
	ll ans=0;
	for(i=1,r;i<=n;++i,m-=r){
		r=n+1-chk_id(res-a[i]);
		ans+=(b[n]-b[n-r])+a[i]*r;
	}
	printf("%lld\n",ans+m*res);
} 
int main(){
	solve();
	
	return 0;
}