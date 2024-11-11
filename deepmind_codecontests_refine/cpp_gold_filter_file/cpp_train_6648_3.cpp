#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> cnt(26, 0);
	rep(i, n) 
	{
		string p;
		cin >> p;
		cnt[p[0] - 'A']++;
	}
	sort(cnt.rbegin(), cnt.rend());
	int ans = 0;
	while(true)
	{
		rep(i, k)
		{
			if (cnt[i] == 0)
			{
				cout << ans << endl;
				return 0;
			}
			cnt[i]--;
		}
		ans++;
		sort(cnt.rbegin(), cnt.rend());
	}
	cout << ans << endl;
	return 0;
}
