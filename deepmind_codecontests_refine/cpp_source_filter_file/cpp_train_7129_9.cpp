#include <bits/stdc++.h>
inline int read() {
  char c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  int k = 0, kk = 1;
  if (c == '-') c = getchar(), kk = -1;
  while (c >= '0' && c <= '9') k = k * 10 + c - '0', c = getchar();
  return kk * k;
}
using namespace std;
void write(int x) {
  if (x < 0) x = -x, putchar('-');
  if (x) write(x / 10), putchar(x % 10 + '0');
}
void writeln(int x) {
  write(x);
  if (x == 0) putchar('0');
  puts("");
}
int n, m, f[1000000], ff[1000000], flag[1000000], a[1000000][2], last[1000000],
    kk, l, r, d[1000000], x, y, ans, z[1000000], dd;
void doit(int x, int y) {
  a[++kk][0] = last[x];
  a[kk][1] = y;
  last[x] = kk;
}
int fa(int x) { return f[x] == x ? x : f[x] = fa(f[x]); }
int bfs(int x) {
  l = 0;
  r = 1;
  d[r] = x;
  z[dd = 1] = x;
  flag[x] = 1;
  int ans = 0;
  while (l < r) {
    l++;
    for (int i = last[d[l]]; i; i = a[i][0])
      if (!flag[a[i][1]]) {
        d[++r] = a[i][1];
        flag[a[i][1]] = 1;
        z[++dd] = a[i][1];
      }
  }
  ans = 0;
  for (int k = 1; k <= dd; k++) {
    for (int i = 1; i <= dd; i++) ff[z[i]] = 1e9;
    x = d[r];
    l = 0;
    r = 1;
    d[r] = x;
    ff[x] = 0;
    while (l < r) {
      l++;
      for (int i = last[d[l]]; i; i = a[i][0])
        if (ff[a[i][1]] > ff[d[l]] + 1) {
          d[++r] = a[i][1];
          ff[a[i][1]] = ff[d[l]] + 1;
          flag[a[i][1]] = 1;
        }
    }
    ans = max(ans, ff[d[r]]);
  }
  return ans;
}
signed main() {
  n = read();
  m = read();
  for (int i = 1; i <= n * 2; i++) f[i] = i;
  for (int i = 1; i <= m; i++) {
    x = read();
    y = read();
    doit(x, y);
    doit(y, x);
    f[fa(x + n)] = fa(y);
    f[fa(y + n)] = fa(x);
  }
  for (int i = 1; i <= n; i++)
    if (fa(i) == fa(i + n)) return puts("-1"), 0;
  for (int i = 1; i <= n; i++)
    if (!flag[i]) ans += bfs(i);
  cout << ans << endl;
}
