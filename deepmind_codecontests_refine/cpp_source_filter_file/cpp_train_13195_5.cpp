#include <bits/stdc++.h>
using namespace std;
inline int readInt() {
  char c;
  int tmp = 0, x = 1;
  c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') x = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    tmp = tmp * 10 + c - '0';
    c = getchar();
  }
  return tmp * x;
}
const int maxN = 200000 + 10;
int a[maxN], n;
vector<int> g[maxN];
void addEdge(int u, int v) {
  g[u].push_back(v);
  g[v].push_back(u);
}
bool vis[maxN];
int pri[maxN], tot = 0, mu[maxN];
void sieve() {
  mu[1] = 1;
  for (int i = 2; i * i < maxN; i++) {
    if (!vis[i]) pri[++tot] = i, mu[i] = -1;
    for (int j = 1; j <= tot && pri[j] * i < maxN; j++) {
      vis[pri[j] * i] = true;
      if (i % pri[j] == 0) {
        mu[pri[j] * i] = 0;
        break;
      }
      mu[pri[j] * i] = -mu[i];
    }
  }
}
int Fa[maxN];
void dfs(int v, int fa) {
  Fa[v] = fa;
  for (int i = 0; i < (int)g[v].size(); i++) {
    int u = g[v][i];
    if (u != fa) dfs(u, v);
  }
}
int siz[maxN], f[maxN];
int getFather(int x) { return x == f[x] ? f[x] : f[x] = getFather(f[x]); }
void mergeUnion(int u, int v) {
  int fu = getFather(u), fv = getFather(v);
  if (fu == fv)
    return;
  else {
    if (siz[fu] > siz[fv]) swap(fu, fv);
    siz[fv] += siz[fu];
    f[fu] = fv;
  }
}
vector<int> hav[maxN], all;
long long h[maxN], ans[maxN];
int main() {
  sieve();
  memset(vis, 0, sizeof(vis));
  n = readInt();
  for (int i = 1; i <= n; i++) a[i] = readInt(), hav[a[i]].push_back(i);
  int u, v;
  for (int i = 1; i <= n - 1; i++) {
    u = readInt(), v = readInt();
    addEdge(u, v);
  }
  dfs(1, -1);
  for (int i = 1; i <= 200000; i++) {
    for (int k = 0; k < (int)all.size(); k++)
      siz[all[k]] = 0, f[all[k]] = 0, vis[all[k]] = false;
    all.clear();
    for (int j = i; j <= 200000; j += i) {
      for (int k = 0; k < (int)hav[j].size(); k++) {
        siz[hav[j][k]] = 1, f[hav[j][k]] = hav[j][k];
        all.push_back(hav[j][k]);
      }
    }
    for (int k = 0; k < (int)all.size(); k++) {
      v = all[k];
      if (Fa[v] != -1 && a[Fa[v]] % i == 0) mergeUnion(Fa[v], v);
    }
    for (int k = 0; k < (int)all.size(); k++) {
      v = all[k];
      if (!vis[u = getFather(v)])
        h[i] += 1ll * siz[u] * (siz[u] + 1) / 2, vis[u] = true;
    }
  }
  for (int i = 1; i <= 200000; i++) {
    for (int j = 1; j <= (200000 / i); j++) {
      ans[i] += h[j * i] * 1ll * mu[j];
    }
  }
  for (int i = 1; i <= 200000; i++) {
    if (ans[i]) printf("%d %I64d\n", i, ans[i]);
  }
  return 0;
}
