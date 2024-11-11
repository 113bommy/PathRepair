#include <bits/stdc++.h>
using namespace std;
void read(long long &x) {
  char ch = getchar();
  x = 0;
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
}
const long long N = 2e5 + 5, M = 5e5 + 5;
long long n, dfn, st[N], tag[N], to[N], f[N], vis[N], id[N];
char a[M];
vector<long long> g[N];
void build() {
  long long num = 0, tp = 0;
  for (long long i = 1; i <= n; ++i) {
    if (a[i] == '(') {
      g[++num].clear();
      if (tp) g[st[tp]].push_back(num);
      st[++tp] = num;
      to[num] = vis[num] = f[num] = 0;
    } else if (a[i] == '*') {
      g[++num].clear();
      if (tp) g[st[tp]].push_back(num);
      to[num] = vis[num] = f[num] = 0;
    } else if (a[i] == 'S')
      tag[st[tp]] = 0;
    else if (a[i] == 'P')
      tag[st[tp]] = 1;
    else if (a[i] == '(')
      --tp;
  }
}
void dfs(long long u) {
  if (!g[u].size()) {
    f[u] = 1, id[u] = ++dfn;
    return;
  }
  for (long long v : g[u]) dfs(v);
  if (tag[u] == 0) {
    long long mn = 0;
    for (long long v : g[u])
      if (f[mn] > f[v]) mn = v;
    to[u] = mn, f[u] = f[mn];
  } else {
    for (long long v : g[u]) f[u] += f[v];
  }
}
long long cnt;
void getcnt(long long u) {
  if (!g[u].size()) {
    vis[id[u]] = 1, ++cnt;
    return;
  }
  if (!tag[u] && to[u])
    getcnt(to[u]);
  else
    for (long long v : g[u]) getcnt(v);
}
signed main() {
  long long T;
  read(T);
  while (T--) {
    long long R;
    scanf("%lld", &R);
    cin.getline(a, 5e5);
    n = strlen(a + 1);
    build();
    f[0] = 2e9;
    dfn = 0, dfs(1);
    cnt = 0;
    getcnt(1);
    printf("REVOLTING ");
    for (long long i = 1; i <= dfn; ++i)
      printf("%lld ", vis[i] ? cnt * R : 0ll);
    putchar('\n');
  }
  return 0;
}
