#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
#define pii pair<int , int>
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
const int INF = 1000 * 1000 * 1000 + 7;
const ll LINF = INF * (ll)INF;
const int mod = INF;
const int MAX = 1 << 25;
ll dp[200005][35];
int main()
{
	ios_base::sync_with_stdio(0);
	int n , t;
	cin >> n >> t;
	vector<pair<ll , ll> > p;
	vector<int> zh;
	for(int i = 0; i < n; i++)
	{
		int a , b;
		cin >> a >> b;
		if(a == 0)
			zh.pb(b);
		else
			p.pb({a , b});
	}
	sort(p.begin() , p.end() , [](pair<ll, ll> p1, pair<ll, ll> p2){return (p1.x * (p2.y + 1)) >
			(p2.x * (p1.y + 1));});
	sort(zh.begin() , zh.end());
	ll sum = 0;
	for(auto &x : zh)
	{
		sum += x + 1;
		x = sum;
	}
	for(int i = 0; i <= n; i++)
		for(int j = 0; j < 35; j++)
			dp[i][j] = INF;
	
	dp[0][0] = 0;
	n = sz(p);
	for(int j = 0; j < 34; j++)
	{
		for(int i = 0; i < n; i++)
		{
			
			dp[i + 1][j] = min(dp[i + 1][j] , dp[i][j]);
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1] , (dp[i][j] + 1) * (p[i].x + 1) + p[i].y);
			
		}
	}
			
	int ans = 0;
	for(int j = 0; j < 34; j++)
		if(dp[n][j] <= t)
		{
			int v = (upper_bound(zh.begin() , zh.end() , t - dp[n][j]) - zh.begin());
			ans = max(ans , j + v);
		}
	cout << ans;
}
