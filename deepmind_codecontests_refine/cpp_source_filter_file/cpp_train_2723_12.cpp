#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
int modExp(int a, int n) {
  long long ret = 1, tp = a;
  while (n) {
    if (n & 1) ret = ret * tp % P;
    tp = tp * tp % P;
    n >>= 1;
  }
  return ret;
}
int inv(int x) { return modExp(x, P - 2); }
int sum[2];
int pr[3005][3005];
int mul[2][3005];
int a[223005], w[3005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    cin >> w[i];
    if (a[i] == 1)
      sum[0] += w[i];
    else
      sum[1] += w[i];
  }
  pr[0][0] = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= i; j++) {
      int k = i - j;
      if (k <= sum[1])
        pr[j + 1][k] = (pr[j + 1][k] + 1LL * pr[j][k] * (sum[0] + j) % P *
                                           inv(sum[0] + sum[1] + j - k)) %
                       P;
      if (sum[1] - k > 0)
        pr[j][k + 1] = (pr[j][k + 1] + 1LL * pr[j][k] * (sum[1] - k) % P *
                                           inv(sum[0] + sum[1] + j - k)) %
                       P;
    }
  }
  mul[0][0] = sum[0], mul[1][0] = sum[1];
  for (int i = 1; i < m; i++) {
    mul[0][i] = 1LL * mul[0][i - 1] * (sum[0] + i) % P;
    mul[1][i] = 1LL * mul[1][i - 1] * (sum[1] - i) % P;
  }
  int ret0 = 0, ret1 = 0;
  for (int i = 1; i <= m; i++) {
    if (m - i <= sum[1])
      ret0 = (ret0 + 1LL * pr[i][m - i] * i % P * inv(sum[0])) % P;
    if (sum[1] >= i)
      ret1 = (ret1 + 1LL * pr[m - i][i] * i % P * inv(sum[1])) % P;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      cout << (w[i] + 1LL * ret0 * w[i]) % P << '\n';
    } else {
      cout << (w[i] - 1LL * ret1 * w[i] % P + P) % P << '\n';
    }
  }
  return 0;
}
