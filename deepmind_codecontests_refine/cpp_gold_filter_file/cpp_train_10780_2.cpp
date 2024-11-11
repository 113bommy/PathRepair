#include <bits/stdc++.h>
using namespace std;
inline int ckmax(int &a, int b) { return a < b ? a = b, 1 : 0; }
inline int ckmin(int &a, int b) { return a > b ? a = b, 1 : 0; }
int ans;
const int oo = 1e9, maxn = 510, maxe = 10000000;
int e = 1, to[maxe], ne[maxe], he[maxn], cap[maxe], cost[maxe];
int d[maxn], vis[maxn], ln[maxn * 1000], l, r, S, T, fl[maxn], inx, from[maxn];
void link(int x, int y, int v, int c) {
  to[++e] = y, ne[e] = he[x], he[x] = e, cap[e] = 0, cost[e] = c;
  to[++e] = x, ne[e] = he[y], he[y] = e, cap[e] = v, cost[e] = -c;
}
bool spfa() {
  memset(d, 127, sizeof(d));
  d[S] = 0, fl[S] = oo;
  for (vis[ln[l = r = 1] = S] = ++inx; l <= r; vis[ln[l++]] = 0) {
    for (int j = he[ln[l]]; j; j = ne[j])
      if (cap[j ^ 1] && d[to[j]] > d[ln[l]] + cost[j]) {
        d[to[j]] = d[ln[l]] + cost[j];
        fl[to[j]] = min(fl[ln[l]], cap[j ^ 1]);
        from[to[j]] = j;
        if (vis[to[j]] < inx) {
          vis[to[j]] = inx;
          ln[++r] = to[j];
        }
      }
  }
  if (d[T] > oo) return 0;
  int f = fl[T];
  ans += f * d[T];
  for (int t = T; t != S; t = to[from[t] ^ 1])
    cap[from[t]] += f, cap[from[t] ^ 1] -= f;
  return 1;
}
void init() {
  e = 1;
  memset(he, 0, sizeof(he));
}
char s[520], str[520];
int n, m, v, x;
int main() {
  init();
  scanf("%d", &n);
  scanf("%s", s);
  scanf("%d", &m);
  S = 0, T = n + 1;
  for (int i = 1; i <= m; ++i) {
    scanf("%s", str);
    int l = strlen(str);
    scanf("%d", &v);
    for (int j = 0; j + l <= n; ++j) {
      int p = 0;
      while (p < l && s[p + j] == str[p]) ++p;
      if (p == l) link(j + 1, p + j + 1, 1, -v);
    }
  }
  scanf("%d", &x);
  for (int i = 0; i <= n; ++i) link(i, i + 1, x, 0);
  while (spfa())
    ;
  printf("%d\n", -ans);
  return 0;
}
