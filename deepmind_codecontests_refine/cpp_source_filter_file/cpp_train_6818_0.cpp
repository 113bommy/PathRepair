#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const int N = 1e5 + 5, inf = 1e9;
int n, m;
int a[N], b[N], l[N], g[N], f[N], p[N], ans[N];
bool vis[N];
inline void get(int i, int k, int &x) {
  int j = lower_bound(b + 1, b + 1 + m, k) - b - 1;
  vis[j] = 1;
  x = ans[i] = b[j];
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read(), f[i] = inf;
  f[++n] = inf;
  a[n] = inf;
  m = read();
  for (int i = 1; i <= m; i++) b[i] = read();
  sort(b + 1, b + 1 + m);
  for (int i = 1; i <= n; i++) {
    if (~a[i]) {
      int j = lower_bound(f + 1, f + n + 1, a[i]) - f - 1;
      l[i] = j + 1;
      p[i] = j;
      f[j + 1] = a[i];
      g[j + 1] = i;
    } else {
      for (int j = n, o = m; o >= 1; o--) {
        while (f[j] >= b[o]) j--;
        f[j + 1] = b[o];
        g[j + 1] = i;
      }
    }
  }
  int i = l[n], j = n, x = a[n];
  while (i-- > 0) {
    if (~a[j]) {
      if (!~a[p[j]])
        get(p[j], a[j], x);
      else
        x = a[p[j]];
      j = p[j];
    } else {
      bool flag = 0;
      for (int s = j - 1; s; s--)
        if (~a[s] && l[s] == i && a[s] < x) {
          x = a[j = s];
          flag = 1;
          break;
        }
      if (flag) continue;
      for (int s = j - 1; s; s--)
        if (!~a[s]) {
          get(s, x, x);
          j = s;
          break;
        }
    }
  }
  for (int i = 1, j = 1; i <= n; i++) {
    if (!~a[i]) {
      if (ans[i]) continue;
      while (vis[j]) j++;
      vis[j] = 1;
      ans[i] = b[j];
    } else
      ans[i] = a[i];
  }
  for (int i = 1; i < n; i++) printf("%d ", ans[i]);
  return 0;
}
