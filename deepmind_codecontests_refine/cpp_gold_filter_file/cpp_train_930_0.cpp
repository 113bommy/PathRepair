#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,w;
int a[201];
int dp[201][10001];
int mod=1000000007;

int main(void){
	scanf("%d%d",&n,&w);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n);
	reverse(a,a+n);
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		memcpy(dp[i+1],dp[i],sizeof(dp[i]));
		for(int j=w-a[i];j>=0;j--){
			dp[i+1][j+a[i]]=(dp[i+1][j+a[i]]+dp[i][j])%mod;
		}
	}
	reverse(a,a+n);
	int all,res;
	all=res=0;
	for(int i=0;i<n;i++){
		for(int j=max(0,w-all-a[i]+1);j<=w-all-(i?a[i-1]:0);j++){
			res=(res+dp[n-i][j])%mod;
		}
		all+=a[i];
	}
	printf("%d\n",res);
	return 0;
}