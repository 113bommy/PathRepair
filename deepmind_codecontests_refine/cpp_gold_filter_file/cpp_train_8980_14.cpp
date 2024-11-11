#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
const int mod = 1e9 + 7;
int sum[N][N], x[N], y[N], b[N], n, m, r;
int C[N][N];
void init() {
  C[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  }
}
int cal(int l1, int r1, int l2, int r2) {
  if (l1 > l2 || r1 > r2) return 0;
  l1 = max(l1, 1);
  r1 = max(r1, 1);
  l2 = min(l2, 1000);
  r2 = min(r2, 1000);
  return sum[l2][r2] - sum[l2][r1 - 1] - sum[l1 - 1][r2] + sum[l1 - 1][r1 - 1];
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(3);
  cin >> n >> m >> r;
  init();
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i] >> b[i];
    sum[x[i]][y[i]]++;
  }
  for (int i = 1; i <= 1000; i++) {
    for (int j = 1; j <= 1000; j++) {
      sum[i][j] =
          (sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + sum[i][j]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int v = 1ll * b[i] * b[j] % mod;
      int XIL = x[i] - r;
      int XIR = x[i] + r;
      int YIL = y[i] - r;
      int YIR = y[i] + r;
      int XJL = x[j] - r;
      int XJR = x[j] + r;
      int YJL = y[j] - r;
      int YJR = y[j] + r;
      int ni = C[n - cal(XIL, YIL, XIR, YIR)][m];
      int nj = C[n - cal(XJL, YJL, XJR, YJR)][m];
      int inter =
          n - cal(XIL, YIL, XIR, YIR) - cal(XJL, YJL, XJR, YJR) +
          cal(max(XIL, XJL), max(YIL, YJL), min(XIR, XJR), min(YIR, YJR));
      int nij = C[inter][m];
      int nn = ni + nj - nij;
      ans = (ans + 1ll * (C[n][m] - nn) * v % mod) % mod;
    }
  }
  cout << (ans + mod) % mod << '\n';
  return 0;
}
