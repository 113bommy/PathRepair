#include<bits/stdc++.h>
using namespace std;
#define ll long long;
LL ans1,ans2,sum;
int n;
int a[100010];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sum=0;
	for(int i=1,s=1;i<=n;i++,s*=-1){
		sum+=a[i];
		if(sum*s<=0) ans1+=abs(sum-s),sum=s;
	}
	sum=0;
	for(int i=1,s=-1;i<=n;i++,s*=-1){
		sum+=a[i];
		if(sum*s<=0) ans2+=abs(sum-s),sum=s;
	}
	printf("%lld\n",min(ans1,ans2));
	return 0;
} 
