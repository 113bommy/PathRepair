#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const long long int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};
const long long int INF = 1e18;
template <typename T>
T gcd(T a, T b) {
  return (b ? __gcd(a, b) : a);
}
template <typename T>
T lcm(T a, T b) {
  return (a * b) / gcd(a, b);
}
long long int n, r1, r2, r3, d;
vector<long long int> a;
void solve() {
  cin >> n >> r1 >> r2 >> r3 >> d;
  a.resize(n);
  for (long long int i = 0; i < (n); ++i) {
    cin >> a[i];
  }
  long long int ans = 0;
  long long int dp0 = 0, dp1 = INF;
  for (long long int i = 0; i < (n); ++i) {
    long long int cost1 = a[i] * r1 + r3;
    long long int cost2 = min({cost1, a[i] * r1 + r1 + r1, r2 + r1});
    long long int ndp0 = INF;
    long long int ndp1 = INF;
    ndp0 = min({ndp0, dp0 + cost1, dp1 + cost2 + d});
    ndp1 = min({ndp1, dp0 + cost2 + d});
    if (i == n - 1) {
      ndp0 = min(ndp0, dp1 + cost1);
    }
    dp0 = ndp0;
    dp1 = ndp1;
  }
  ans = min(dp0, dp1 + d) + (n - 1) * d;
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
