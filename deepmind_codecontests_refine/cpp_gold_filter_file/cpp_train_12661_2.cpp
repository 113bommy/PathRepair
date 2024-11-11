#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool umx(T& A, const T& B) {
  return A < B ? A = B, 1 : 0;
}
template <class T>
inline bool umn(T& A, const T& B) {
  return A > B ? A = B, 1 : 0;
}
const int mo = 1000000007;
const int maxn = 1 << 8;
int n, m, D;
map<int, int> id;
int idn;
int getid(int u) {
  if (id.find(u) != id.end()) return id[u];
  id[u] = ++idn;
  return idn;
}
int getsz(int u) {
  int d = 32 - __builtin_clz(u);
  for (int i = (d), i_end_ = (D); i < i_end_; ++i) u = u << 1 | 1;
  return (1 << (D - d + 1)) - 1 - (max(min(u - n, 1 << (D - d)), 0));
}
vector<int> G[maxn];
void adde2(int u, int v) { G[u].push_back(v), G[v].push_back(u); }
int e0[10][2];
int sz[maxn];
bool vis[maxn];
void dfs0(int u, int fa) {
  for (auto v : G[u])
    if (v != fa) {
      sz[u] -= sz[v];
      dfs0(v, u);
    }
}
void dfs(int u, int& cnt) {
  (cnt += sz[u]) %= mo;
  vis[u] = 1;
  for (auto v : G[u])
    if (!vis[v]) dfs(v, cnt);
  vis[u] = 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (D = 1; (1 << D) - 1 < n; ++D)
    ;
  id.clear();
  idn = 0;
  getid(1);
  for (int i = (0), i_end_ = (m); i < i_end_; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    e0[i][0] = u, e0[i][1] = v;
    for (; u; u >>= 1) getid(u);
    for (; v; v >>= 1) getid(v);
  }
  for (int i = (1), i_end_ = (id.size() + 1); i < i_end_; ++i) G[i].clear();
  for (auto x : id) {
    int u0 = x.first, u = x.second;
    sz[u] = getsz(u0);
    if (u0 > 1) adde2(getid(u0 >> 1), u);
  }
  dfs0(1, 0);
  for (int i = (0), i_end_ = (m); i < i_end_; ++i)
    adde2(getid(e0[i][0]), getid(e0[i][1]));
  int res = 0;
  for (auto x : id) {
    int u = x.second;
    int cnt = 0;
    dfs(u, cnt);
    (res += 1ll * sz[u] * cnt % mo) %= mo;
  }
  printf("%d\n", res);
  return 0;
}
