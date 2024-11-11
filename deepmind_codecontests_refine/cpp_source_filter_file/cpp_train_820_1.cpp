#include <cstdio>
#include <cstring>
#define EPS (1e-13)
#define MAX(A,B)((A)>=(B)?(A):(B))
double dp[1000001];
int main() {
	int n;
	while(scanf("%d",&n),n) {
		for(int i=0;i<=1000000;i++) dp[i]=0;
		dp[1]=1;
		for(int i=2;i<=n;i++) {
			double p=1.0,win=0.5;
			for(int j=1;j<i && EPS<p;j++) {
				double not=p*(1-win);
				dp[i]+=not*(j+dp[MAX(0,n-1-j)]);
				p*=win; win/=2;
			}
			dp[i]+=p*i;
		}
		printf("%lf\n",dp[n]);
	}
}