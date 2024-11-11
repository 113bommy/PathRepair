#include <bits/stdc++.h>
using namespace std;
int B[105], dp[105], ans;
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n-1; ++i) cin >> B[i];
	ans += B[0];
	for (int i = 0; i < n-1; ++i)
	{
		ans += min(B[i], B[i+1]);
	}
	ans += B[n-2];
	cout << ans;
}
