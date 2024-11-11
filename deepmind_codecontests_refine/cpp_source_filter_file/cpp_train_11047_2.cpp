#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 3, maxm = 13;
int n, m, c0, d0;
int a[maxm], b[maxm], c[maxm], d[maxm];
int dp[maxn][maxm];
int best(int ind, int dough) {
  if (ind > m) {
    return 0;
  }
  if (dp[ind][dough] > -1) {
    return dp[ind][dough];
  }
  for (int i = 0; i <= min(a[ind] / b[ind], dough / c[ind]); i++) {
    dp[ind][dough] =
        max(dp[ind][dough], i * d[ind] + best(ind + 1, dough - c[ind] * i));
  }
  return dp[ind][dough];
}
int main() {
  cin >> n >> m >> c0 >> d0;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  a[0] = 1e6, b[0] = 1, c[0] = c0, d[0] = d0;
  memset(dp, -1, sizeof dp);
  cout << best(0, n);
}
