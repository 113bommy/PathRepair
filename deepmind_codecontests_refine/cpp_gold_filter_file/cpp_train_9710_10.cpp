#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0', ch = getchar();
  }
  return x * f;
}
struct node {
  int x, y;
} a[N], c[N];
int n, m, f[1000005];
void solve() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) {
    a[i].x = read();
    a[i].y = read();
  }
  for (int i = 1; i <= m; i++) {
    c[i].x = read();
    c[i].y = read();
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i].y > c[j].y) continue;
      int d = c[j].y - a[i].y;
      f[d] = max(f[d], c[j].x - a[i].x + 1);
    }
  }
  for (int i = 1000000; i >= 0; i--) f[i] = max(f[i], f[i + 1]);
  int ans = 1e9;
  for (int i = 0; i <= 1000000; i++) {
    ans = min(ans, i + f[i]);
  }
  printf("%d\n", ans);
}
int main() {
  int T = 1;
  while (T--) solve();
}
