#include <bits/stdc++.h>
const int N = 200005;
using namespace std;
int n, a[N], to[N * 2], hd[N * 2], ln[N * 2], lk[N], cnt, sz[N], fi;
double co[N], now, sum, upd, ans = 3e20, tp;
bool vis[N];
int u, v, w;
inline void add(int u, int v) {
  to[++cnt] = v, hd[cnt] = lk[u], ln[cnt] = w, lk[u] = cnt;
}
int get(int x, int y, int nn) {
  for (int s, i = lk[x]; i; i = hd[i])
    if (!vis[s = to[i]])
      if (s ^ y && sz[s] > nn) return get(s, x, nn);
  return x;
}
bool fl = 1;
void dfs(int x, int y, long long d) {
  tp = a[x] * sqrt((double)d);
  now += tp, upd += d * tp;
  sz[x] = 1;
  for (int s, i = lk[x]; i; i = hd[i])
    if ((s = to[i]) ^ y) dfs(s, x, d + ln[i]), sz[x] += sz[s];
  if (vis[x]) sz[x] = 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i < n; i++) scanf("%d%d%d", &u, &v, &w), add(u, v), add(v, u);
  dfs(1, 0, 0);
  for (int x = 1; fl;) {
    vis[x = get(x, 0, sz[x] >> 1)] = 1, sum = upd = fl = 0;
    for (int s, i = lk[x]; i; i = hd[i])
      now = 0, dfs(s = to[i], x, ln[i]), sum += now, co[s] = now;
    if (ans > upd) fi = x, ans = upd;
    for (int s, i = lk[x]; i; i = hd[i])
      if (!vis[s = to[i]])
        if (2 * co[s] > sum) {
          x = s;
          fl = 1;
          break;
        }
  }
  printf("%d %.8lf", fi, ans);
}
