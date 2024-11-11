#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
const int INF = 0x3f3f3f3f, MOD = 1000000007;
const long long LINF = LONG_LONG_MAX;
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
istream& operator>>(istream& is, pair<int, int>& p) {
  return is >> p.first >> p.second;
}
signed main() {
  cin.tie(0);
  cout.sync_with_stdio(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << min(1, n / 2) << '\n';
  }
}
