#include <bits/stdc++.h>
using namespace std;
namespace TYC {
const int N = 45, S = 1 << 20 | 5;
bool dep[N];
int n, m, lim, all, vis[N], fa[N], F[S], bin[N];
long long G[N];
vector<int> E[N], V;
int find(const int x) {
  if (x == fa[x]) return x;
  int f = find(fa[x]);
  dep[x] ^= dep[fa[x]];
  return fa[x] = f;
}
bool check(const int s) {
  static queue<int> q;
  q.push(s);
  vis[s] = 1;
  V.clear();
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    V.push_back(u);
    for (int v : E[u])
      if (!vis[v]) vis[v] = 1, q.push(v);
  }
  for (int u : V)
    for (int v : E[u])
      if (u < v) {
        int fu = find(u), fv = find(v);
        if (fu != fv)
          fa[fu] = fv, dep[fu] = dep[v] ^ dep[u] ^ 1;
        else if (dep[u] == dep[v])
          return false;
      }
  return true;
}
long long dfs1(const int i, const long long e) {
  if (i > lim) return F[all ^ (e >> lim)];
  long long ans = dfs1(i + 1, e);
  if (!(e & bin[i])) ans += dfs1(i + 1, e | G[i]);
  return ans;
}
void dfs2(const int i, const int s, const int e) {
  if (i > n) return void(++F[s]);
  dfs2(i + 1, s, e);
  if (!(e & bin[i])) dfs2(i + 1, s | bin[i], e | (G[i] >> lim));
}
long long solve() {
  all = (1 << (lim = n >> 1)) - 1;
  for (int i = 1; i <= lim; i++) bin[i] = bin[i + lim] = 1 << (i - 1);
  dfs2(lim + 1, 0, 0);
  for (int i = 0; i < lim; i++)
    for (int j = all; ~j; j--)
      if (j & (1 << i)) F[j] += F[j ^ (1 << i)];
  return dfs1(1, 0);
}
void work() {
  scanf("%d%d", &n, &m);
  if (!m) return void(puts("0"));
  for (int i = 1, u, v; i <= m; i++) {
    scanf("%d%d", &u, &v);
    E[u].push_back(v);
    E[v].push_back(u);
    G[u] |= 1 << (v - 1);
    G[v] |= 1 << (u - 1);
  }
  for (int i = 1; i <= n; i++) fa[i] = i;
  int tot = 0, flag = 1, cnt = 0;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      ++tot;
      flag &= check(i);
      cnt += V.size() == 1;
    }
  long long ans = (1LL << n) - (tot == n);
  ans += (1LL << cnt) << 1;
  ans += flag ? 1LL << tot : 0;
  ans -= 1LL << tot;
  ans -= solve() << 1;
  printf("%lld\n", ans);
}
}  // namespace TYC
int main() {
  TYC::work();
  return 0;
}
