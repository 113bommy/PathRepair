#include <bits/stdc++.h>
using namespace std;
const int N = 310;
const int mod = 1e9 + 7;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
int n, m, tt, u[N], v[N], siz[N], ans, sum;
map<int, int> id;
vector<int> E[N];
bool vis[N];
void add(int u) {
  if (!id.count(u)) id[u] = ++tt;
}
int getsiz(int u) {
  int d = 1;
  while ((1 << (d + 1)) - 1 < n) d <<= 1;
  int now = 0, x = u, y = u;
  while (x) ++now, x >>= 1;
  int ret = (1 << (d - now + 1)) - 1;
  x = u;
  while (now <= d) ++now, x <<= 1, y = (y << 1 | 1);
  ret += max(0, min(y - x + 1, n - x + 1));
  return ret;
}
void dfs(int u, int fa) {
  for (auto v : E[u])
    if (v != fa) siz[u] -= siz[v], dfs(v, u);
}
void adde(int u, int v) {
  E[u].push_back(v);
  E[v].push_back(u);
}
void search(int u) {
  sum = (sum + siz[u]) % mod;
  vis[u] = 1;
  for (auto v : E[u])
    if (!vis[v]) search(v);
  vis[u] = 0;
}
int main() {
  cin >> n >> m;
  add(1);
  for (int i = 1; i <= m; i++) {
    u[i] = gi();
    v[i] = gi();
    for (int x = u[i]; x; x >>= 1) add(x);
    for (int x = v[i]; x; x >>= 1) add(x);
  }
  for (auto t : id) {
    siz[t.second] = getsiz(t.first);
    if (t.first > 1) adde(id[t.first >> 1], t.second);
  }
  dfs(1, 0);
  for (int i = 1; i <= m; i++) adde(id[u[i]], id[v[i]]);
  for (int i = 1; i <= tt; i++) {
    sum = 0;
    search(i);
    ans = (ans + 1ll * siz[i] * sum) % mod;
  }
  cout << ans;
  return 0;
}
