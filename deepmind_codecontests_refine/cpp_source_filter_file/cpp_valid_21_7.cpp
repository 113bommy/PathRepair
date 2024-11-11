#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int x[n], y[n];
  bool s[n];
  const int MOD = 998244353;
  int ta[n], pta[n + 1];
  int ans = 0;
  pta[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> s[i];
    ta[i] = x[i] - y[i];
    int l = lower_bound(x, x + i, y[i]) - x;
    ta[i] = (0ll + ta[i] + pta[i] - pta[l]) % MOD;
    pta[i + 1] = (0ll + pta[i] + ta[i]) % MOD;
    if (s[i]) ans = (0ll + ans + ta[i]) % MOD;
  }
  ans = (0ll + ans + x[n - 1] + 1) % MOD;
  cout << ans;
}
