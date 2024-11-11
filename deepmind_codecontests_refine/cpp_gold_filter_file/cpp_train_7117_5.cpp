#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
const int N = 1e5 + 10;
const long long mod = 1e9 + 7;
const long long mod2 = 998244353;
const long long inf = 8e18;
const int LOG = 22;
long long pw(long long a, long long b, long long M) {
  return (!b ? 1
             : (b & 1 ? (a * pw(a * a % M, b / 2, M)) % M
                      : pw(a * a % M, b / 2, M)));
}
int v[N];
vector<int> D[N], I;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  for (int i = 1; i < N; i++) {
    for (long long j = 1; i * j < N; j++) {
      D[i * j].push_back(i);
    }
  }
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  v[n + 1] = 2e9;
  sort(v + 1, v + n + 1);
  long long ans = 1;
  for (int i = 2; i < N; i++) {
    I.clear();
    long long last = n, cnt = (int)D[i].size();
    for (auto x : D[i]) {
      int id = lower_bound(v + 1, v + n + 2, x) - v - 1;
      I.push_back(id);
    }
    long long cu =
        (pw(cnt, n - I.back(), mod) - pw(cnt - 1, n - I.back(), mod) + mod) %
        mod;
    last = I.back();
    I.pop_back();
    reverse((I).begin(), (I).end());
    for (auto x : I) {
      cnt--;
      cu = (cu * pw(cnt, last - x, mod)) % mod;
      last = x;
    }
    ans = (ans + cu) % mod;
  }
  cout << ans;
  return 0;
}
