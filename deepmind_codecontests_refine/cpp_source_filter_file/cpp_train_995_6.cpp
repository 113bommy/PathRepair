#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int inf = 2e5;
int read() {
  int x = 0, f = 1, ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
  return x * f;
}
struct edge {
  int to, nxt;
} e[200005];
int head[200005], k = 1;
void add(int u, int v) {
  e[k] = {v, head[u]};
  head[u] = k++;
}
int n, ans1, ans2, tot = 0;
map<int, int> mp;
void ist(int x) {
  if (!mp[x]) ++tot;
  ++mp[x];
}
void dlt(int x) {
  --mp[x];
  if (!mp[x]) --tot;
}
int hs[200005], size[200005];
void dfs1(int u, int fa, int eg) {
  size[eg] = 1;
  for (int i = head[u], v; ~i; i = e[i].nxt) {
    v = e[i].to;
    if (v == fa) continue;
    dfs1(v, u, i);
    hs[eg] = (1ll * hs[eg] + hs[i]) % mod;
    size[eg] += size[i];
  }
  hs[eg] =
      (1ll * hs[eg] * size[eg] % mod + 1ll * size[eg] * size[eg] % mod) % mod;
  ist(hs[eg]);
}
void dfs2(int u, int fa) {
  register int sum = 0;
  for (int i = head[u], v; ~i; i = e[i].nxt) sum = (1ll * sum + hs[i]) % mod;
  for (int i = head[u], v; ~i; i = e[i].nxt) {
    v = e[i].to;
    size[i ^ 1] = n - size[i];
    hs[i ^ 1] = (1ll * size[i ^ 1] * (sum - hs[i] + mod) % mod +
                 1ll * size[i ^ 1] * size[i ^ 1]) %
                mod;
    if (v != fa) dfs2(v, u);
  }
}
void slv(int u, int fa) {
  for (int i = head[u], v; ~i; i = e[i].nxt) {
    v = e[i].to;
    if (v == fa) continue;
    dlt(hs[i]), ist(hs[i ^ 1]);
    if (tot > ans1) ans1 = tot, ans2 = v;
    slv(v, u);
    dlt(hs[i ^ 1]), ist(hs[i]);
  }
}
signed main() {
  n = read();
  memset(head, -1, sizeof head);
  for (int i = 1, u, v; i < n; ++i)
    u = read(), v = read(), add(u, v), add(v, u);
  dfs1(1, 0, inf);
  dfs2(1, 0);
  ans1 = tot, ans2 = 1;
  slv(1, 0);
  printf("%d\n", ans2);
  return 0;
}
