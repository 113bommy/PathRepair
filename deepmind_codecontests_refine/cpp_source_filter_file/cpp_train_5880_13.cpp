#include <bits/stdc++.h>
using namespace std;
template <class P, class Q>
inline void smin(P &a, Q b) {
  if (b < a) a = b;
}
template <class P, class Q>
inline void smax(P &a, Q b) {
  if (a < b) a = b;
}
const int maxn = 100 + 2;
int n, k;
int a[maxn];
double dp[maxn][maxn], odp[maxn][maxn];
double t[maxn][maxn];
inline int bino(int k) { return k * (k + 1) / 2; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0, _n = (int)(n); i < _n; i++) cin >> a[i];
  smin(k, 1000);
  double tot = bino(n);
  for (int z = 0, _n = (int)(k); z < _n; z++) {
    memcpy(odp, dp, sizeof odp);
    for (int j = 0, _n = (int)(n); j < _n; j++)
      for (int i = 0, _n = (int)(j); i < _n; i++) {
        double &c = dp[i][j];
        c = (bino(i) + bino(j - i - 1) + bino(n - j - 1)) * odp[i][j];
        for (int k = 0, _n = (int)(n - (j - i)); k < _n; k++) {
          int L = (k < i ? k : i) + 1;
          int R = n - (j < k + j - i ? j : k + j - i);
          c += (L < R ? L : R) * (1 - odp[k][k + (j - i)]);
        }
        for (int k = 0, _n = (int)(i); k < _n; k++)
          c += (k + 1 < j - i ? k + 1 : j - i) * odp[k][j];
        for (int k = (int)(i), _n = (int)(j); k < _n; k++)
          c += (i + 1 < j - k ? i + 1 : j - k) * odp[k][j];
        for (int k = (int)(i + 1), _n = (int)(j); k < _n; k++)
          c += (k - i < n - j ? k - i : n - j) * odp[i][k];
        for (int k = (int)(j), _n = (int)(n); k < _n; k++)
          c += (j - i < n - k ? j - i : n - k) * odp[i][k];
        c /= tot;
      }
  }
  double ans = 0;
  for (int j = 0, _n = (int)(n); j < _n; j++)
    for (int i = 0, _n = (int)(j); i < _n; i++)
      ans += dp[i][j] * (a[i] < a[j]) + (1 - dp[i][j]) * (a[i] > a[j]);
  cout.setf(ios::fixed);
  cout.precision(12);
  cout << ans << endl;
  return 0;
}
