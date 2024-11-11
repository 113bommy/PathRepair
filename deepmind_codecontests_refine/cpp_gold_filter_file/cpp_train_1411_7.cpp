#include <bits/stdc++.h>
using namespace std;
double p[(1 << 20) + 666], a[22], s[(1 << 20) + 666];
vector<int> V;
int n, k, ss;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(15);
  cout << fixed;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i], ss += (a[i] > 1e-5);
  if (ss <= k)
    for (int i = 0; i < n; i++) cout << (a[i] > 1e-5 ? 1 : 0) << ' ';
  else {
    for (int i = 0; i < (1 << n); i++)
      if (__builtin_popcount(i) == k) V.push_back(i);
    for (int i = 0; i < (1 << n); i++)
      for (int j = 0; j < n; j++)
        if ((i >> j) & 1) s[i] += a[j];
    p[0] = 1;
    for (int i = 0; i < (1 << n); i++)
      for (int j = 0; j < n; j++)
        if (!((i >> j) & 1)) p[i | (1 << j)] += p[i] * a[j] / (1 - s[i]);
    for (int i = 0; i < n; i++) {
      double res = 0;
      for (auto j : V)
        if ((j >> i) & 1) res += p[j];
      cout << res << ' ';
    }
  }
  return 0;
}
