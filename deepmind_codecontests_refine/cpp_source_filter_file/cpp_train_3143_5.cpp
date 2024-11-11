#include <bits/stdc++.h>
using namespace std;
namespace TYC {
const int N = 30010;
int n, top, sz, sta[N], vis[N], mark[N], size[N];
long long sum[N], F[N], val[N];
vector<int> E[N], cir;
bool find_cir(const int u, const int f) {
  vis[u] = 1, sta[++top] = u;
  for (int v : E[u]) {
    if (v == f) continue;
    if (vis[v]) {
      int x;
      do {
        mark[x = sta[top--]] = 1;
        cir.push_back(x);
      } while (x != v);
      return true;
    } else if (find_cir(v, u))
      return true;
  }
  vis[u] = 0, --top;
  return false;
}
void dfs1(const int u, const int f) {
  size[u] = 1;
  for (int v : E[u])
    if (v != f && !mark[v]) {
      dfs1(v, u);
      size[u] += size[v];
      sum[u] += sum[v] + size[v];
    }
}
long long dfs2(const int u, const int f, const int tot, const long long now) {
  long long ans = now;
  for (int v : E[u])
    if (v != f && !mark[v])
      ans = max(ans, dfs2(v, u, tot, now + tot - (size[v] << 1)));
  return ans;
}
void getans() {
  static int p[N];
  for (int i = 0; i < sz; i++) p[i] = p[i + sz] = cir[i];
  for (int i = (sz << 1) - 1; i >= 0; i--) {
    int t = F[i] = size[p[i]];
    for (int j = i + 1, lim = min(sz << 1, i + sz); j < lim; j++)
      F[j] = max(F[j], F[j - 1]) + (t += size[p[j]]);
    val[p[(i - 1 + sz) % sz]] = F[i + sz - 2];
  }
}
void work() {
  scanf("%d", &n);
  for (int i = 1, u, v; i <= n; i++) {
    scanf("%d%d", &u, &v);
    E[u].push_back(v);
    E[v].push_back(u);
  }
  find_cir(1, 0);
  long long tmp = 0, ans = 0;
  for (int o : cir) dfs1(o, 0), tmp += sum[o];
  sz = cir.size();
  getans();
  for (int i = 0; i < sz; i++) {
    int o = cir[i];
    ans = max(ans, tmp - sum[o] + val[o] + dfs2(o, 0, n, sum[o] + n));
  }
  printf("%lld\n", ans);
}
}  // namespace TYC
int main() {
  TYC::work();
  return 0;
}
