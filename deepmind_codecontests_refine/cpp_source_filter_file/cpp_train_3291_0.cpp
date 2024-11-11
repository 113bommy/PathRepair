#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
int a[35], pre[35][65][1800], cnt[35], ans[65][65], p[35], ud[35];
bool f[35][65][1800];
int main() {
  int n = read(), tot;
  for (int i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + n + 1);
  tot = a[n] * 2;
  f[0][0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = i - 1; j + n - i + 1 <= tot; j++) {
      int limit = tot * (tot - 1) / 2;
      for (int k = 0; k <= limit; k++) {
        if (f[i - 1][j][k] == false) continue;
        for (int ad = 1; j + ad <= tot && k + ad * a[i] <= limit; ad++) {
          int ul = j + ad, wy = k + ad * a[i];
          if (wy < ul * (ul - 1) / 2) continue;
          pre[i][j + ad][wy] = ad;
          f[i][j + ad][wy] = true;
        }
      }
    }
  }
  int uf = n;
  n = -1;
  for (int i = uf; i <= tot; i++) {
    int ul = i * (i - 1) / 2;
    if (f[uf][i][ul] == true) {
      n = i;
      break;
    }
  }
  if (n == -1)
    printf("=(\n");
  else {
    printf("%d\n", n);
    int wn = uf, wt = n, ws = n * (n - 1) / 2;
    while (wn) {
      int he = pre[wn][wt][ws];
      ud[wn] = he;
      wt -= he, ws -= he * a[wn];
      wn--;
    }
    int now = 0;
    for (int i = 1; i <= uf; i++) {
      for (int j = 1; j <= ud[i]; j++) cnt[++now] = a[i];
    }
    int d = 0;
    for (int i = 1; i <= n; i++) {
      p[i] = i - 1;
      d += abs(p[i] - cnt[i]);
      for (int j = 1; j < i; j++) ans[i][j] = 1;
    }
    while (d) {
      int he = -1, P;
      bool bk = false;
      for (int i = 1; i <= n; i++) {
        if (p[i] < cnt[i] && bk == false) he = p[i], bk = true;
        if (he == -1) continue;
        if (p[i] == he)
          P = i;
        else {
          if (p[i] > cnt[i]) {
            for (int j = 1; j <= n; j++) {
              if (j == i || j == P) continue;
              if (ans[i][j] == 1 && ans[P][j] == 0) {
                swap(ans[i][j], ans[j][i]);
                swap(ans[P][j], ans[j][P]);
                break;
              }
            }
            p[i]--, p[P]++;
            break;
          }
        }
      }
      d -= 2;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) printf("%d", ans[i][j]);
      printf("\n");
    }
  }
  return 0;
}
