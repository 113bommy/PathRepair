#include<bits/stdc++.h>

using namespace std;

const int N = 3e3 + 3;
double dp[N];

int main()
{
	int n;
	cin >> n;

	dp[0] = 1;
	double p;
	for(int i = 1; i <= n; i++){
		cin >> p;
		for(int j = i; j >= 0; j--)
			dp[j] = (j == 0 ? 0 : dp[j - 1] * p) + dp[j] * (1 - p);
	}

	double ans = 0;
	for(int i = 0; i <= n; i++)
		if(i > n - i)
			ans += dp[i];

	cout << fixed << setprecision(10);	
	cout << ans << "\n";
}