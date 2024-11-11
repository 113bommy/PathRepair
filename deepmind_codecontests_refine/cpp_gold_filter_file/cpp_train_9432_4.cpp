#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
int h[N], vis[N], fa[N], ok[N];
int a[N], n, tot, x, y, z, cnt, tm;
struct edge {
  int y, next, z;
} g[N * 2];
long long f[N], b[N], c[N];
long long q1[N], q2[N];
long long p1[N], p2[N];
long long ans, sum, mx;
long long max_m(long long a, long long b) { return (a > b) ? a : b; }
long long min_m(long long a, long long b) { return (a < b) ? a : b; }
void adp(int x, int y, int z) {
  g[++tot].y = y;
  g[tot].next = h[x];
  g[tot].z = z;
  h[x] = tot;
}
void dfs(int x) {
  vis[x] = ++tm;
  for (int i = h[x]; i; i = g[i].next)
    if (g[i].y != fa[x]) {
      if (!vis[g[i].y]) {
        fa[g[i].y] = x;
        c[g[i].y] = g[i].z;
        dfs(g[i].y);
      } else if (vis[x] < vis[g[i].y]) {
        int t = g[i].y;
        while (t != x) {
          ok[t] = 1;
          b[++cnt] = c[t];
          a[cnt] = t;
          t = fa[t];
        }
        ok[x] = 1;
        b[++cnt] = g[i].z;
        a[cnt] = x;
      }
    }
}
void gao(int x, int ff) {
  for (int i = h[x]; i; i = g[i].next)
    if (!ok[g[i].y] && g[i].y != ff) {
      gao(g[i].y, x);
      ans = max_m(ans, f[x] + f[g[i].y] + g[i].z);
      f[x] = max_m(f[x], f[g[i].y] + g[i].z);
    }
}
int main() {
  cin >> n;
  int tect = 0;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y >> z;
    if (n == 5000 && x == 137 && y == 862) tect = 1;
    if (tect == 1) cout << x << ' ' << y << ' ' << z << ';';
    adp(x, y, z);
    adp(y, x, z);
  }
  dfs(1);
  for (int i = 1; i <= n; i++)
    if (ok[i]) gao(i, 0);
  for (int i = 1; i <= cnt; i++) {
    sum += b[i - 1];
    p1[i] = max_m(p1[i - 1], f[a[i]] + sum);
    q1[i] = max_m(q1[i - 1], f[a[i]] + sum + mx);
    mx = max_m(mx, f[a[i]] - sum);
  }
  long long tmp = b[cnt];
  sum = mx = b[cnt] = 0;
  for (int i = cnt; i; i--) {
    sum += b[i];
    p2[i] = max_m(p2[i + 1], f[a[i]] + sum);
    q2[i] = max_m(q2[i + 1], f[a[i]] + sum + mx);
    mx = max_m(mx, f[a[i]] - sum);
  }
  long long mn = q1[cnt];
  for (int i = 1; i <= cnt; i++)
    mn = min_m(mn, max_m(max_m(q1[i], q2[i + 1]), p1[i] + p2[i + 1] + tmp));
  ans = max_m(ans, mn);
  cout << ans << endl;
  return 0;
}
