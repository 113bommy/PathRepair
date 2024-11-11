#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
int main(){
	scanf("%lld%lld",&n,&k);
	if(!k){printf("%lld\n",n*n);return 0;}
	for(int i=k+1,x;i<=n;i++)
		{x=(n-i+1)/i,ans+=(i-k)*(x+1)+max(0,n-k-i*(x+1)+1);}
	printf("%lld\n",ans);
	return 0;
}
