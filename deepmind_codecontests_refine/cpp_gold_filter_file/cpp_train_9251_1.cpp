#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int main(){

	long long int*** dp = new long long int**[10];
	for(int i = 1; i <= 9; i++){
		dp[i] = new long long int*[101];
		for(int k = 0; k <= 100; k++){
			dp[i][k] = new long long int[1001];
			for(int p = 0; p <= 1000; p++)dp[i][k][p] = 0;
		}
	}

	for(int i = 0; i <= 100; i++){
		dp[1][i][i] = 1;
	}

	for(int i = 2; i <= 9; i++){
		for(int k = 0; k <= 100; k++){
			for(int a = 0; a <= k-1; a++){
				for(int p = k; p <= 1000; p++){
					dp[i][k][p] += dp[i-1][a][p-k];
				}
			}
		}
	}

	long long int ans;
	int n,s;

	while(true){
		scanf("%d %d",&n,&s);
		if(n == 0 && s == 0)break;

		ans = 0;
		for(int i = 0; i <= 100; i++)ans += dp[n][i][s];

		printf("%lld\n",ans);

	}

    return 0;
}