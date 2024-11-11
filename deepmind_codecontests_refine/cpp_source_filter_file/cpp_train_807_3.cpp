#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<pair<ll, ll> > v(n);
    for(int i=0;i<n;i++){
        cin >> a[i].first;
        a[i].second = -i;
    }
    sort(be(v));
    vector<vector<ll> > dp(n+1,vector<ll> (n+1,0));
    for (int i=0;i<n;i++)for (int j=0;j<n;j++){
        ll id = -a[i].second;
        dp[i+1][j] = max(dp[i][j]+a[i].first*(i-id+j), dp[i][j+1] + a[i].first*(id-j));
    }
    cout << dp[n][0] << endl;
    return 0;
}
