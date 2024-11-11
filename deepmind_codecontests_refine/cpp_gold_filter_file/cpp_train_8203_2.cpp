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
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

bool passNum[666];
bool writed[666];
int dp[666][333][333];

void mod_add(int &a, int b){
	a += b;
	a %= MOD;
}

int main(){
	
	int n;cin >> n;
	int cou = 0;
	vector<int> v(2*n);
	REP(i,2*n){
		cin >> v[i];
		if(v[i] != -1)writed[v[i]] = true;
	}
	
	REP(i,n){
		if(v[2*i] != -1 && v[2*i+1] != -1){
			passNum[v[2*i]] = passNum[v[2*i+1]] = true;
		}
		if(v[2*i] == -1 && v[2*i+1] == -1)cou++;
	}
	
	dp[2*n][0][0] = 1;
	for(int i = 2*n;i > 0;i--){
		REP(j,n+1){
			REP(k,n+1){
				if(passNum[i]){
					mod_add(dp[i-1][j][k],dp[i][j][k]);
					continue;
				}
				if(writed[i]){
					if(j > 0)mod_add(dp[i-1][j-1][k], dp[i][j][k]);
					mod_add(dp[i-1][j][k+1], dp[i][j][k]);
				}
				else{
					if(j > 0)mod_add(dp[i-1][j-1][k], dp[i][j][k]);
					if(k > 0)mod_add(dp[i-1][j][k-1], k * (ll)dp[i][j][k] % MOD);
					mod_add(dp[i-1][j+1][k], dp[i][j][k]);
				}
			}
		}
	}
		
	ll ans = dp[0][0][0];
	REP(i,cou){
		ans *= (i + 1);
		ans %= MOD;
	}
	
	cout << ans << endl;
				
	
	return 0;
}
