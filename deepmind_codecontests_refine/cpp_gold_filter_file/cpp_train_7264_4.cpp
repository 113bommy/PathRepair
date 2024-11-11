#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int n;
ll p, a[10005];
string s;
vector<array<ll, 2>> v;
int mod = 998244353;
int main(){
	cin >> n;
	v.resize(n);
	for(int i=0;i<n;++i){
		cin >> v[i][0] >> v[i][1] ;
	}
	sort(v.begin(), v.end());
	vector<ll>dp(n+1, 0);
	dp[n] = 1;
	vector<pair<ll,ll>> p;
	p.push_back({n, 2e9});
	for(int i = n - 1; i >= 0;--i){
		while(v[i][0]+v[i][1] > p.back().second){
			p.pop_back();
		}

		int take = p.back().first;
		dp[i] = dp[take];
		dp[i] += dp[i+1];
		dp[i] %= mod;
		p.push_back({i, v[i][0]});
	}
	dp[0] += mod;
	dp[0] = dp[0]%mod;
	cout << dp[0];
}
