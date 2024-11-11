#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T gi() {
  T f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return f * x;
}
const int INF = 0x3f3f3f3f, N = 300003, M = N << 1;
int n, m;
int tot, head[N], ver[M], nxt[M];
struct Node {
  int d, x;
};
vector<Node> v[N];
int dep[N];
long long ans[N];
inline void add(int u, int v) {
  ver[++tot] = v, nxt[tot] = head[u], head[u] = tot;
}
namespace BIT {
long long tr[N];
void add(int x, int val) {
  for (int i = x; i <= n; i += (i & (-i))) tr[i] += val;
}
long long query(int x) {
  long long res = 0;
  for (int i = x; i; i -= (i & (-i))) res += tr[i];
  return res;
}
}  // namespace BIT
void dfs(int u, int f) {
  dep[u] = dep[f] + 1;
  for (int i = 0; i < (int)v[u].size(); i += 1)
    BIT ::add(dep[u], v[u][i].x), BIT ::add(dep[u] + v[u][i].d + 1, -v[u][i].x);
  ans[u] = BIT ::query(dep[u]);
  for (int i = head[u]; i; i = nxt[i]) {
    int v = ver[i];
    if (v == f) continue;
    dfs(v, u);
  }
  for (int i = 0; i < (int)v[u].size(); i += 1)
    BIT ::add(dep[u], -v[u][i].x), BIT ::add(dep[u] + v[u][i].d + 1, v[u][i].x);
}
int main() {
  n = gi<int>();
  for (int i = 1; i < n; i += 1) {
    int u = gi<int>(), v = gi<int>();
    add(u, v), add(v, u);
  }
  m = gi<int>();
  while (m--) {
    int vv = gi<int>(), d = min(n, gi<int>()), x = gi<int>();
    v[vv].push_back((Node){d, x});
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i += 1) printf("%lld ", ans[i]);
  return 0;
}
