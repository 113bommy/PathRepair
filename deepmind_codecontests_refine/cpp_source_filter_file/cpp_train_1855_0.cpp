#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 998244353
#define fastcin() cin.tie(0);ios::sync_with_stdio(false)

typedef long long ll;
typedef pair<ll,ll> P;

ll dp[4444][4444];

void modadd(ll &a, ll b){
	a += b;
	a % MOD;
}

int main(){
	
	string str;
	cin >> str;
	ll n = str.size();
	ll sum = 0;
	dp[0][0] = 1;
	REP(i,2 * n){
		if(i < n)sum += 2;
		REP(j, 2 * n)if(dp[i][j]){
			ll now = j;
			if(i < n)now += str[i] - '0';
			if(now)modadd(dp[i+1][now-1], dp[i][j]);
			if(sum - now - i)modadd(dp[i+1][now], dp[i][j]);
		}
	}
	
	//cerr << endl << endl;
	
	/SHOW2d(dp,2*n+1,2*n+1);
	
	cout << dp[2*n][0] << endl;
	
	return 0;
}
