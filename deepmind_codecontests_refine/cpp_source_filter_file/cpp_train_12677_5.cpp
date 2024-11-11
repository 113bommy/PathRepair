#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 5;
typedef long long ll;
ll a[maxn], b[maxn];
int main()
{
	ios::sync_with_stdio(false);
	ll n, m, k;
	int ans = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}
	for (int j = 1; j <= m; j++)
	{
		cin >> b[j];
		b[j] += b[j - 1];
	}
	for (int i = 0; i <= n; i++)
	{
		if (k >= a[i])
		{
			ans = max(ans, upper_bound(b + 1, b + m + 1, k - a[i]) - b - 1 + i);
		}
	}
	cout << ans;
	return 0;
}