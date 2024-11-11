#include <bits/stdc++.h>
using namespace std;
const int MaxN(200003);
const int Mod(1e9 + 7);
bool p[MaxN], Vis[MaxN];
int K, root, n, cnt, ans, Index;
int Deep[MaxN], h[MaxN], Size[MaxN];
int a[MaxN], Pr[MaxN], phi[MaxN], s[MaxN];
int dfn[MaxN], mu[MaxN], F[MaxN], fa[21][MaxN];
vector<int> G[MaxN], nG[MaxN];
inline void upd(int &x, int y) { (x += y) >= Mod ? x -= Mod : x; }
inline void add(int u, int v) {
  nG[u].push_back(v);
  nG[v].push_back(u);
}
int fexp(int x, int k) {
  int res = 1;
  for (; k; k >>= 1, x = (long long)x * x % Mod)
    if (k & 1) res = (long long)res * x % Mod;
  return res;
}
void getprime(int n) {
  mu[1] = phi[1] = 1;
  for (int i = 2, tot = 0; i <= n; i++) {
    if (!p[i]) {
      Pr[++tot] = i;
      phi[i] = i - 1, mu[i] = Mod - 1;
    }
    for (int j = 1; j <= tot && Pr[j] * i <= n; j++) {
      p[Pr[j] * i] = 1;
      if (i % Pr[j]) {
        phi[i * Pr[j]] = phi[i] * phi[Pr[j]];
        mu[i * Pr[j]] = Mod - mu[i];
      } else {
        phi[i * Pr[j]] = phi[i] * Pr[j];
        break;
      }
    }
  }
}
void dfs(int u) {
  dfn[u] = ++Index;
  Deep[u] = Deep[fa[0][u]] + 1;
  for (auto v : G[u])
    if (v != fa[0][u]) fa[0][v] = u, dfs(v);
}
void Init() {
  dfs(1);
  for (int j = 1; (1 << j) <= n; j++)
    for (int i = 1; i <= n; i++) fa[j][i] = fa[j - 1][fa[j - 1][i]];
}
int lca(int u, int v) {
  if (Deep[u] < Deep[v]) swap(u, v);
  for (int j = 19; ~j; j--)
    if (Deep[fa[j][u]] >= Deep[v]) u = fa[j][u];
  if (u == v) return u;
  for (int j = 19; ~j; j--)
    if (fa[j][u] ^ fa[j][v]) u = fa[j][u], v = fa[j][v];
  return fa[0][u];
}
void Build() {
  int top;
  static int S[MaxN];
  sort(h + 1, h + 1 + K, [](int x, int y) { return dfn[x] < dfn[y]; });
  S[top = 1] = h[1];
  for (int i = 2; i <= K; i++) {
    int f = lca(h[i], S[top]);
    while (top > 2 && dfn[f] <= dfn[S[top - 1]]) add(S[top], S[top - 1]), --top;
    if (f != S[top]) add(f, S[top]), S[top] = f;
    S[++top] = h[i];
  }
  while (top > 1) add(S[top], S[top - 1]), --top;
  root = S[top];
}
void dp(int u, int f) {
  Size[u] = Vis[u] ? phi[a[u]] : 0;
  for (auto v : nG[u])
    if (v != f) {
      dp(v, u);
      upd(cnt, (long long)Size[u] * Size[v] % Mod * Deep[u] % Mod);
      Size[u] += Size[v];
    }
  nG[u].clear();
}
int solve(int d) {
  K = 0;
  for (int i = d; i <= n; i += d) Vis[h[++K] = s[i]] = true;
  cnt = 0, Build(), dp(root, 0);
  int res = 0, tmp = 0;
  for (int i = 1; i <= K; i++) upd(res, phi[a[h[i]]]);
  for (int i = 1; i <= K; i++) {
    int w = phi[a[h[i]]];
    upd(tmp, (long long)w * (res - w + Mod) % Mod * Deep[h[i]] % Mod);
    Vis[h[i]] = false;
  }
  return tmp = (tmp - 2ll * cnt % Mod + Mod) % Mod;
}
int main() {
  scanf("%d", &n);
  getprime(n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s[a[i]] = i;
  }
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  Init();
  for (int i = 1; i <= n; i++) F[i] = solve(i);
  for (int i = 1; i <= n; i++) {
    int tmp = 0;
    for (int j = 1; i * j <= n; j++)
      upd(tmp, (long long)mu[j] * F[i * j] % Mod);
    upd(ans, (long long)tmp * i % Mod * fexp(phi[i], Mod - 2) % Mod);
  }
  ans = 2ll * ans % Mod * fexp(n, Mod - 2) % Mod * fexp(n - 1, Mod - 2) % Mod;
  printf("%d\n", ans);
  return 0;
}
