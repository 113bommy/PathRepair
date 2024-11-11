#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 5;
double p[2][N][N];
int n, k, a[N];
int C(int x) { return x * (x + 1) / 2; }
int main() {
  cin >> n >> k;
  k = min(k, 850);
  for (int j = 0; j < n; j++) {
    cin >> a[j];
    for (int i = 0; i < j; i++) p[0][i][j] = a[i] > a[j];
  }
  for (int t = 0; t < k; t++) {
    auto &prv = p[t & 1], &cur = p[~t & 1];
    for (int j = 0; j < n; j++)
      for (int i = 0; i < j; i++) {
        cur[i][j] = prv[i][j] * (C(j - i - 1) + C(i) + C(n - j - 1)) / C(n);
        for (int p = 0; p < j; p++)
          cur[i][j] += prv[p][j] * min({i + 1, p + 1, j - i, j - p}) / C(n);
        for (int p = i + 1; p < n; p++)
          cur[i][j] += prv[i][p] * min({n - j, n - p, j - i, p - i}) / C(n);
        for (int p = j - i; p < n; p++)
          cur[i][j] += (1 - prv[i + p - j][p]) *
                       min({i + 1, i + p - j + 1, n - j, n - p}) / C(n);
      }
  }
  double ans = 0;
  for (int j = 0; j < n; j++)
    for (int i = 0; i < j; i++) ans += p[k & 1][i][j];
  cout << fixed << setprecision(9) << ans;
}
