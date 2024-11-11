#include <bits/stdc++.h>
using namespace std;
int read() {
  int s = 0, f = 1;
  char ch = getchar();
  while (!('0' <= ch && ch <= '9')) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    s = (s << 3) + (s << 1) + ch - '0';
    ch = getchar();
  }
  return s * f;
}
int n, K, m, sss;
int a[105], b[25];
int g[10005], ans[1 << 20];
int d[22][22];
int main() {
  n = read();
  K = read();
  m = read();
  for (int i = 1; i <= K; i++) {
    int ss = read();
    b[sss++] = ss;
    b[sss++] = ss + 1;
  }
  for (int i = 1; i <= m; i++) a[i] = read();
  sort(&b[0], &b[sss]);
  for (int j = 0; j < sss; j++) {
    queue<int> q;
    for (int i = 0; i <= n; i++) g[i] = 100000000;
    q.push(b[j]);
    g[b[j]] = 0;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int i = 1; i <= m; i++) {
        if (x + a[i] <= n) {
          if (g[x + a[i]] > g[x] + 1) {
            g[x + a[i]] = g[x] + 1;
            q.push(x + a[i]);
          }
        }
        if (x - a[i] >= 0) {
          if (g[x - a[i]] > g[x] + 1) {
            g[x - a[i]] = g[x] + 1;
            q.push(x - a[i]);
          }
        }
      }
    }
    for (int i = 0; i < sss; i++) d[j][i] = g[b[i]];
  }
  for (int i = 1; i < (1 << (sss)); i++) {
    ans[i] = 100000000;
    int j = sss - 1;
    while (!((i >> j) & 1)) j--;
    for (int k = j - 1; k >= 0; k--)
      if ((i >> k) & 1)
        ans[i] = min(ans[i], ans[i ^ (1 << j) ^ (1 << k)] + d[j][k]);
  }
  printf("%d\n",
         (ans[(1 << (sss)) - 1] == 100000000 ? -1 : ans[(1 << (sss)) - 1]));
  return 0;
}
