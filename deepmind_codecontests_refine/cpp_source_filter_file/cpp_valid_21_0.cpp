#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e16;
const int mod = 998244353;
void solve() {
  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  vector<int> s(n);
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> s[i];
  vector<long long> ans(n, 0);
  vector<long long> f(n, 0);
  ans[0] = x[0] % mod;
  f[0] = (x[0] - y[0]) % mod;
  if (s[0] == 1) ans[0] = (ans[0] + f[0]) % mod;
  vector<long long> pref(n + 1, 0);
  pref[1] = f[0];
  for (int i = 1; i < n; i++) {
    int l = 0, r = i - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (x[mid] < y[i])
        l = mid + 1;
      else
        r = mid;
    }
    if (x[l] > y[i]) f[i] = (pref[i] - pref[l] + mod) % mod;
    f[i] = (f[i] + x[i] - y[i]) % mod;
    pref[i + 1] = (pref[i] + f[i]) % mod;
    ans[i] = (ans[i - 1] + x[i] - x[i - 1]) % mod;
    if (s[i] == 1) ans[i] = (ans[i] + f[i]) % mod;
  }
  cout << ans[n - 1] + 1 << "\n";
  return;
}
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test_cnt = 1;
  for (int test = 1; test <= test_cnt; test++) {
    solve();
  }
  return 0;
}
