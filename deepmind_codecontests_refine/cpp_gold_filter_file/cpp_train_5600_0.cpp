#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

void chmin(int &a, int b){a = min(a, b);}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n, a = 1e9;
    cin >> n;
    vector<vector<int> > v(n, vector<int> (2));
    for(int i=0;i<n;i++) cin >> v[i][0];
    for(int i=0;i<n;i++) cin >> v[i][1];
    int maki = 1 << n;
    vector<vector<int> > dp(maki, vector<int> (51, a));
    dp[0][0] = 0;
    for(int bit=0;bit<maki;bit++){
    	int cnt = 0;
    	vector<int> d(n);
    	for(int i=0;i<n;i++) if(!(bit>>i&1)) d[i] = cnt++;
    	for(int i=0;i<n;i++){
    		int k = abs(i - n + cnt);
    		for(int j=0;j<=v[i][k&1];j++)
    			chmin(dp[bit|(1<<i)][v[i][k&1]], dp[bit][j] + d[i]);
    	}
    }
    for(int i=0;i<=50;i++) chmin(a, dp[maki-1][i]);
    cout << (a==1e9? -1: a) << endl;
    return 0;
}
