#include <bits/stdc++.h>
using namespace std;
int n, m;
long long djx[2 * 1005][2 * 1005], lk[1005][1005], ks[1005][1005],
    flow[1005][1005], sum[1005][1005];
struct Worker {
  long long a[1005][1005];
  long long f[1005][1005];
  int k;
  void init() {
    memset(djx, 0, sizeof djx);
    memset(lk, 0, sizeof lk);
    memset(ks, 0, sizeof ks);
    memset(flow, 0, sizeof flow);
    memset(f, 0, sizeof f);
    memset(sum, 0, sizeof sum);
  }
  void getdjx() {
    for (int i = 1; i <= n + m; i++)
      for (int j = 1; j < i && j <= n; j++)
        if (i - j <= m && i - j > 0) djx[i][j] = djx[i][j - 1] + a[j][i - j];
  }
  void getks() {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= k; j++) ks[i][k] += a[i][j];
      for (int j = k + 1; j <= m; j++)
        ks[i][j] = ks[i][j - 1] + a[i][j] - a[i][j - k];
    }
  }
  void getlk() {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= k; j++) lk[i][k] += j * 1ll * a[i][j];
      for (int j = k + 1; j <= m; j++)
        lk[i][j] = lk[i][j - 1] - ks[i][j - 1] + k * 1ll * a[i][j];
    }
  }
  void getsum() {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) sum[i][j] = sum[i][j - 1] + a[i][j];
  }
  void getflow() {
    for (int j = k; j <= m; j++) {
      for (int i = 1; i <= k; i++) flow[k][j] += sum[i][j] - sum[i][j - i];
      for (int i = k + 1; i <= n; i++)
        flow[i][j] = flow[i - 1][j] -
                     (djx[i - k + j][i - 1] - djx[i - k + j][i - k - 1]) +
                     ks[i][j];
    }
  }
  void getf() {
    for (int j = k; j <= m; j++) {
      for (int i = 1; i <= k; i++)
        f[k][j] += i * 1ll * (djx[i + j][k] - djx[i + j][i - 1]);
      for (int i = k + 1; i <= n; i++)
        f[i][j] = f[i - 1][j] - flow[i - 1][j] + lk[i][j];
    }
  }
  void work() {
    init();
    getdjx();
    getks();
    getlk();
    getsum();
    getflow();
    getf();
  }
} dp1, dp2, dp3, dp4;
int k;
long long a[1005][1005];
void tp1() {
  int x, y;
  long long ans;
  ans = -1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (a[i][j] > ans) {
        ans = a[i][j];
        x = i;
        y = j;
      }
  printf("%d %d\n", x, y);
}
void tp2() {
  int x, y;
  long long ans;
  ans = -1;
  for (int i = 2; i <= n - 1; i++)
    for (int j = 2; j <= m - 1; j++)
      if (a[i][j] * 2 + a[i - 1][j] + a[i][j - 1] + a[i + 1][j] + a[i][j + 1] >
          ans) {
        ans =
            a[i][j] * 2 + a[i - 1][j] + a[i][j - 1] + a[i + 1][j] + a[i][j + 1];
        x = i;
        y = j;
      }
  printf("%d %d\n", x, y);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%I64d", &a[i][j]);
  if (k == 1) {
    tp1();
    return 0;
  }
  if (k == 2) {
    tp2();
    return 0;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) dp1.a[i][j] = a[i][j];
  dp1.k = k;
  dp1.work();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) dp2.a[i][m + 1 - j] = a[i][j];
  dp2.k = k - 1;
  dp2.work();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) dp3.a[n - i + 1][m + 1 - j] = a[i][j];
  dp3.k = k - 2;
  dp3.work();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) dp4.a[n - i + 1][j] = a[i][j];
  dp4.k = k - 1;
  dp4.work();
  long long ans = -1;
  int x, y;
  for (int i = k; i <= n - k + 1; i++)
    for (int j = k; j <= m - k + 1; j++) {
      long long res = 0;
      res += dp1.f[i][j];
      res += dp2.f[i][m + 1 - (j + 1)];
      res += dp3.f[n + 1 - (i + 1)][m + 1 - (j + 1)];
      res += dp4.f[n + 1 - (i + 1)][j];
      if (res > ans) ans = res, x = i, y = j;
    }
  printf("%d %d\n", x, y);
  return 0;
}
