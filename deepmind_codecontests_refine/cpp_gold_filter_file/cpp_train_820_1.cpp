#include <cstdio>
#include <algorithm>
using namespace std;
#define EPS (1e-13)
double dp[100001];
int main() {
	dp[1]=1;
	for(int n=2;n<=100000;n++) {
		double p=1,win=0.5;
		int k=1;
		while(EPS<p&&k<n) {
			double Not=p*(1-win);
			dp[n]+=Not*(k+dp[max(n-k-1,0)]);
			p*=win; win/=2; k++;
		}
		dp[n]+=n*p;
	}
	int n;
	while(scanf("%d",&n),n) {
		printf("%lf\n",dp[n]);
	}
}