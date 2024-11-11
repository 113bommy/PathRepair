#include <bits/stdc++.h>
using namespace std;
const long long int N = 3e5 + 500;
const long long mod = 1e9 + 7;
const long long cmod = 998244353;
const long long inf = 1LL << 61;
const long long int M = 1e6 + 500;
const long long int ths = 1LL << 40;
const long long int NN = 5e3 + 6;
const long long int maxN = 10000007;
void solve() {
  long long int n;
  cin >> n;
  vector<pair<long long int, long long int>> v;
  for (long long int i = 0; i < n; i++) {
    long long int a, b;
    cin >> a >> b;
    v.push_back({a, 1});
    v.push_back({b, -1});
  }
  sort(v.begin(), v.end());
  long long int mx = 0, cur = 0, y;
  for (long long int i = 0; i < v.size(); i++) {
    cur += v[i].second;
    if (cur > mx) {
      mx = cur;
      y = v[i].first;
    }
  }
  cout << y << ' ' << mx;
  cout << "\n";
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
