#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
char ch;
bool fs;
void re(int& x) {
  while (ch = getchar(), ch < 33)
    ;
  if (ch == '-')
    fs = 1, x = 0;
  else
    fs = 0, x = ch - 48;
  while (ch = getchar(), ch > 33) x = x * 10 + ch - 48;
  if (fs) x = -x;
}
using namespace std;
long long ans;
int n, rt, a[500001], p[500001][19], dep[500001];
int cnt, head[500001], nxt[500001 + 500001], to[500001 + 500001];
void dfs(int u) {
  for (int i = 1; (1 << i) <= dep[u]; ++i) p[u][i] = p[p[u][i - 1]][i - 1];
  if (u != rt) {
    long long mn = 1ll << 60;
    for (int i = 0; i <= 18; ++i) {
      if (!p[u][i]) p[u][i] = rt;
      mn = min(mn, (i + 1ll) * a[p[u][i]] + a[u]);
    }
    ans += mn;
  }
  for (int i = head[u], v; i; i = nxt[i])
    if ((v = to[i]) != p[u][0]) {
      p[v][0] = u;
      dep[v] = dep[u] + 1;
      dfs(v);
    }
}
int main() {
  re(n);
  for (int i = 1; i <= n; ++i) re(a[i]);
  for (int i = 1, u, v; i < n; ++i) {
    re(u), re(v);
    nxt[++cnt] = head[u], head[u] = cnt, to[cnt] = v;
    nxt[++cnt] = head[v], head[v] = cnt, to[cnt] = u;
  }
  rt = min_element(a + 1, a + n + 1) - a;
  dfs(rt);
  printf("%lld\n", ans);
}
