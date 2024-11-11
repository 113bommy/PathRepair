#include <bits/stdc++.h>
const int N = 200005;
bool u[N][6];
int a[N], p[N], k, pre[N][6][2];
int main() {
  int n, i, j, h, z;
  scanf("%d", &n);
  u[0][5] = true;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i]) {
      p[++k] = i;
    }
  }
  for (i = 1; i <= k; i++) {
    if (a[p[i]] < a[p[i - 1]]) {
      puts("-1");
      return 0;
    }
    for (j = 1; j <= 5; j++)
      if (u[i - 1][j]) {
        if (a[p[i]] == a[p[i - 1]]) {
          if (j + p[i] - p[i - 1] <= 5) {
            u[i][j + p[i] - p[i - 1]] = true;
            pre[i][j + p[i] - p[i - 1]][0] = j;
            pre[i][j + p[i] - p[i - 1]][1] = 0;
          }
          continue;
        }
        for (h = 0; h + j <= 5; h++)
          if (h + j >= 2) {
            for (z = 1; z <= 5 && h + z <= p[i] - p[i - 1]; z++) {
              int x = p[i] - p[i - 1] - h - z, d = a[p[i]] - a[p[i - 1]] - 1;
              if (2 * d <= x && x <= 5 * d) {
                u[i][z] = true;
                pre[i][z][0] = j;
                pre[i][z][1] = h;
              }
            }
          }
      }
  }
  int ret = -1, pe;
  for (i = 1; i < 6; i++)
    if (u[k][i] && (i != 1 || p[k] < n)) {
      int tmp;
      if (i >= 2)
        tmp = (n - p[k]) / 2;
      else
        tmp = (n - p[k] - 1) / 2;
      if (ret < tmp) {
        ret = tmp;
        pe = i;
      }
    }
  if (ret != -1) ret += a[p[k]];
  printf("%d\n", ret);
  if (ret != -1) {
    if (pe == 1) {
      a[p[k] + 1] = a[p[k]];
      i = p[k] + 2;
    } else
      i = p[k] + 1;
    int v = a[p[k]] + 1;
    for (; i + 1 <= n; i += 2) {
      a[i] = a[i + 1] = v;
      v++;
    }
    if (i <= n) a[i] = a[i - 1];
    for (i = k; i > 0; i--) {
      for (j = 2; j <= pe; j++) {
        a[p[i] - j + 1] = a[p[i]];
      }
      if (a[p[i]] == a[p[i - 1]]) {
        for (j = p[i - 1] + 1; j < p[i]; j++) a[j] = a[p[i]];
        pe = pre[i][pe][0];
        continue;
      }
      for (j = 1; j <= pre[i][pe][1]; j++) {
        a[p[i - 1] + j] = a[p[i - 1]];
      }
      int x = p[i] - p[i - 1] - pre[i][pe][1] - pe,
          d = a[p[i]] - a[p[i - 1]] - 1, v = a[p[i - 1]] + 1, ct = 0;
      for (j = p[i - 1] + pre[i][pe][1] + 1; j <= p[i] - pe; j++) {
        x--;
        if (ct < 5 && 2 * (d - 1) <= x) {
          a[j] = v;
          ct++;
        } else {
          d--;
          v++;
          a[j] = v;
          ct = 1;
        }
      }
      pe = pre[i][pe][0];
    }
    for (i = 1; i <= n; i++) printf("%d ", a[i]);
  }
  return 0;
}
