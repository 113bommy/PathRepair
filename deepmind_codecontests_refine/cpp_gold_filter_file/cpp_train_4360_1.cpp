#include<cstdio>
#include<cmath>
using namespace std;
int dp[10010];

int prime(int n) {
	int i, j,d;
	if (n == 1) { return dp[1] = 2; };
	d = dp[n - 1];
	for (i = d+1;; i++) {
		for (j = 2;; j++) {
			if (i%j == 0)break;
			if (j == (int)sqrt(i)+1) { return dp[n] = i; }
		}
	}
}

int main() {
	int n, i;
	long long sum = 0;
	while (scanf("%d", &n) && n){
		if (n == 0)break;
		for (i = 1; i <= n; i++)sum += prime(i);
		printf("%d\n", sum);
		sum = 0;
	}
	return 0;
}