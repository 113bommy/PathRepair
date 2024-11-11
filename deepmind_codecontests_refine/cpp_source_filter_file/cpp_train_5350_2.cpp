#include <bits/stdc++.h>
using namespace std;
int n, l[85], r[85], ls[85];
double f[85][85], ans[85][85], pre[85], cur[85], suf[85], tmp[85][85],
    tmp2[85][85], tag[85][85];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &l[i], &r[i]), ls[i * 2 - 1] = l[i], ls[i * 2] = r[i];
  sort(ls + 1, ls + 2 * n + 1);
  int pend = unique(ls + 1, ls + 2 * n + 1) - ls;
  for (int i = 1; i <= n; i++) {
    l[i] = lower_bound(ls + 1, ls + pend, l[i]) - ls;
    r[i] = lower_bound(ls + 1, ls + pend, r[i]) - ls - 1;
  }
  for (int i = 1; i < pend - 1; i++) {
    for (int j = 1; j <= n; j++) {
      if (l[j] > i) {
        pre[j] = 0;
        cur[j] = 0;
        suf[j] = 1;
      } else if (l[j] <= i && i <= r[j]) {
        pre[j] = (double)(ls[i] - ls[l[j]]) / (ls[r[j] + 1] - ls[l[j]]);
        cur[j] = (double)(ls[i + 1] - ls[i]) / (ls[r[j] + 1] - ls[l[j]]);
        suf[j] = (double)(ls[r[j] + 1] - ls[i + 1]) / (ls[r[j] + 1] - ls[l[j]]);
      } else {
        pre[j] = 1;
        cur[j] = 0;
        suf[j] = 0;
      }
    }
    for (int j = 1; j <= n; j++) {
      if (l[j] <= i && i <= r[j]) {
        f[0][0] = 1;
        int cnt = 0;
        for (int p = 1; p <= n; p++) {
          if (j == p) continue;
          for (int k = cnt; k >= 0; k--) {
            for (int l = cnt - k; l >= 0; l--) {
              f[k][l + 1] += f[k][l] * cur[p];
              f[k + 1][l] += f[k][l] * pre[p];
              f[k][l] *= suf[p];
            }
          }
          ++cnt;
        }
        for (int k = 0; k < n; k++) {
          for (int l = 0; l + k < n; l++) {
            double c = f[k][l] / (l + 1);
            tag[j][k + 1] += c * cur[j];
            tag[j][k + l + 2] -= c * cur[j];
          }
        }
        memset(f, 0, sizeof(f));
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      tag[i][j] += tag[i][j - 1];
      printf("%.10lf ", tag[i][j]);
    }
    puts("");
  }
  return 0;
}
