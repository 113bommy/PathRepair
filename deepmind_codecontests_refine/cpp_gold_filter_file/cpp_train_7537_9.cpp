#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
int sum[maxn][maxn];
int pre[maxn][maxn];
int pn[maxn][maxn];
int suf[maxn][maxn];
int sn[maxn][maxn];
int pl[maxn], sl[maxn];
int a[maxn][maxn];
int lim[maxn];
int n, m, r;
inline int abs(int x) { return x > 0 ? x : -x; }
inline int max(int a, int b) { return a > b ? a : b; }
void solve() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &a[i][j]);
      sum[i][j] = sum[i][j - 1] + a[i][j];
    }
  }
  lim[0] = r;
  for (int i = 1; i <= r; ++i) {
    lim[i] = lim[i - 1];
    while (i * i + lim[i] * lim[i] > r * r) lim[i]--;
  }
  memset(a, 0, sizeof(a));
  for (int i = r + 1; i <= n - r; ++i) {
    for (int j = r + 1; j <= m - r; ++j) {
      for (int k = -r; k <= r; ++k) {
        a[i][j] +=
            sum[i + k][j + lim[abs(k)]] - sum[i + k][j - lim[abs(k)] - 1];
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] > pre[i][j - 1]) {
        pre[i][j] = a[i][j];
        pn[i][j] = 1;
      } else if (a[i][j] == pre[i][j - 1]) {
        pre[i][j] = a[i][j];
        pn[i][j] = pn[i][j - 1] + 1;
      } else {
        pre[i][j] = pre[i][j - 1];
        pn[i][j] = pn[i][j - 1];
      }
    }
    for (int j = m; j >= 1; --j) {
      if (a[i][j] > suf[i][j + 1]) {
        suf[i][j] = a[i][j];
        sn[i][j] = 1;
      } else if (a[i][j] == suf[i][j + 1]) {
        suf[i][j] = a[i][j];
        sn[i][j] = sn[i][j + 1] + 1;
      } else {
        suf[i][j] = suf[i][j + 1];
        sn[i][j] = sn[i][j + 1];
      }
    }
  }
  for (int i = 0; i <= 2 * r; ++i) {
    for (int j = i - r; j <= r; ++j) {
      int dis1 = j, dis2 = j - i;
      pl[i] = max(pl[i], lim[abs(dis1)] + lim[abs(dis2)] + 1);
    }
  }
  int ans1 = 0;
  long long ans2 = 0;
  for (int i = r + 1; i <= n - r; ++i) {
    for (int j = r + 1; j <= m - r; ++j) {
      for (int k = r + 1; k <= n - r; ++k) {
        int dis = abs(i - k);
        if (dis > 2 * r) {
          if (pre[k][m] > 0) {
            if (pre[k][m] + a[i][j] > ans1) {
              ans1 = pre[k][m] + a[i][j];
              ans2 = pn[k][m];
            } else if (pre[k][m] + a[i][j] == ans1) {
              ans2 += pn[k][m];
            }
          }
          continue;
        }
        if (j - pl[dis] >= r + 1) {
          if (pre[k][j - pl[dis]] + a[i][j] > ans1) {
            ans1 = pre[k][j - pl[dis]] + a[i][j];
            ans2 = pn[k][j - pl[dis]];
          } else if (pre[k][j - pl[dis]] + a[i][j] == ans1) {
            ans2 += pn[k][j - pl[dis]];
          }
        }
        if (j + pl[dis] <= m - r) {
          if (suf[k][j + pl[dis]] + a[i][j] > ans1) {
            ans1 = suf[k][j + pl[dis]] + a[i][j];
            ans2 = sn[k][j + pl[dis]];
          } else if (suf[k][j + pl[dis]] + a[i][j] == ans1) {
            ans2 += sn[k][j + pl[dis]];
          }
        }
      }
    }
  }
  ans2 /= 2;
  printf("%d %I64d\n", ans1, ans2);
}
int main() {
  scanf("%d%d%d", &n, &m, &r);
  solve();
  return 0;
}
