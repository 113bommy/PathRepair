#include <bits/stdc++.h>
using namespace std;
const int N = 300000 + 10;
int n, m;
namespace BXJ {
int fa[N];
int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
}  // namespace BXJ
int C[N];
void update(int x, int s) {
  for (int i = x; i <= n; i += i & -i) C[i] += s;
}
int query(int x) {
  int s = 0;
  for (int i = x; i; i -= i & -i) s += C[i];
  return s;
}
struct Edge {
  int u, v, w;
  bool mark;
} e[N];
vector<pair<int, int>> g[N];
int dep[N], fa[N], val[N];
int in[N], out[N], dfn;
int oula[2 * N], bin[2 * N], odfn;
int fir[N];
void dfs(int u) {
  in[u] = ++dfn;
  oula[++odfn] = u;
  fir[u] = odfn;
  for (auto p : g[u]) {
    int v = p.first, w = p.second;
    if (in[v]) continue;
    dep[v] = dep[u] + 1;
    fa[v] = u;
    val[v] = val[u] ^ w;
    dfs(v);
    oula[++odfn] = u;
  }
  out[u] = dfn;
}
int mx(int x, int y) { return dep[x] < dep[y] ? x : y; }
int st[25][2 * N];
void st_init() {
  bin[0] = -1;
  for (int i = 1; i <= odfn; i++) {
    if (i == (i & -i))
      bin[i] = bin[i - 1] + 1;
    else
      bin[i] = bin[i - 1];
  }
  for (int i = 1; i <= odfn; i++) st[0][i] = oula[i];
  for (int t = 1; t < 25; t++) {
    for (int i = 1; i + (1 << t) - 1 <= odfn; i++) {
      st[t][i] = mx(st[t - 1][i], st[t - 1][i + (1 << t - 1)]);
    }
  }
}
int st_query(int L, int R) {
  if (L > R) swap(L, R);
  int k = bin[R - L + 1];
  return mx(st[k][L], st[k][R - (1 << k) + 1]);
}
int Lca(int x, int y) { return st_query(fir[x], fir[y]); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) BXJ::fa[i] = i;
  for (int i = 1; i <= m; i++) {
    cin >> e[i].u >> e[i].v >> e[i].w;
    int fu = BXJ::get(e[i].u), fv = BXJ::get(e[i].v);
    e[i].mark = fu == fv;
    if (!e[i].mark) {
      g[e[i].u].emplace_back(e[i].v, e[i].w);
      g[e[i].v].emplace_back(e[i].u, e[i].w);
      BXJ::fa[fu] = fv;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!in[i]) dfs(i);
  }
  st_init();
  for (int i = 1; i <= m; i++) {
    if (e[i].mark) {
      if (val[e[i].u] ^ val[e[i].v] ^ e[i].w != 1)
        cout << "NO" << endl;
      else {
        int x = e[i].u, y = e[i].v;
        int lca = Lca(x, y);
        int sum = query(in[x]) + query(in[y]) - 2 * query(in[lca]);
        if (sum)
          cout << "NO" << endl;
        else {
          while (x != lca) {
            update(in[x], 1);
            update(out[x] + 1, -1);
            x = fa[x];
          }
          while (y != lca) {
            update(in[y], 1);
            update(out[y] + 1, -1);
            y = fa[y];
          }
          cout << "YES" << endl;
        }
      }
    } else
      cout << "YES" << endl;
  }
  return 0;
}
