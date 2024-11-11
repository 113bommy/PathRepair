#include <bits/stdc++.h>
using namespace std;
const long long mod1 = 998244353;
const long long mod2 = 1e9 + 9;
const int INF = 0x7f7f7f7f;
template <typename _T>
_T Fabs(_T x) {
  return x < 0 ? -x : x;
}
template <typename _T>
void read(_T &x) {
  _T f = 1;
  x = 0;
  char s = getchar();
  while (s > '9' || s < '0') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while ('0' <= s && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ 48);
    s = getchar();
  }
  x *= f;
}
int n, m, k, tot, head[100005], cap;
int dis[100005], si, sum;
long long ans = 1;
bool vis[100005];
vector<int> G[100005], vec;
char str[100005];
struct edge {
  int to, nxt;
} e[100005 << 1];
void addEdge(int u, int v) {
  e[++tot] = (edge){v, head[u]};
  head[u] = tot;
}
struct ming {
  int index, dis;
  bool operator<(const ming &x) const { return dis > x.dis; }
};
priority_queue<ming> q;
void Dijkstra(int eu) {
  while (!q.empty()) q.pop();
  for (int i = 1; i <= n; i++) dis[i] = INF, vis[i] = 0;
  dis[eu] = 0;
  q.push((ming){eu, 0});
  while (!q.empty()) {
    ming t = q.top();
    q.pop();
    int u = t.index;
    if (vis[u]) continue;
    vis[u] = 1;
    for (int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      if (dis[v] > dis[u] + 1) dis[v] = dis[u] + 1, G[v].clear();
      q.push((ming){v, dis[v]});
      if (dis[v] == dis[u] + 1) G[v].push_back(i >> 1);
    }
  }
}
void dfs(int x) {
  if (x == si) {
    puts(str + 1);
    sum++;
    if (sum == k) exit(0);
    return;
  }
  int siz = G[vec[x]].size();
  for (int i = 0; i < siz; i++)
    str[G[vec[x]][i]] = '1', dfs(x + 1), str[G[vec[x]][i]] = '0';
}
signed main() {
  read(n);
  read(m);
  read(k);
  tot = 1;
  for (int i = 1; i <= m; i++) {
    int u, v;
    read(u);
    read(v);
    addEdge(u, v);
    addEdge(v, u);
  }
  Dijkstra(1);
  for (int i = 2; i <= n; i++) {
    ans *= (long long)G[i].size();
    if (ans > k) ans = k;
  }
  printf("%lld\n", min(ans, 1ll * k));
  for (int i = 0; i < m; i++) str[i] = '0';
  for (int i = 2; i <= n; i++) {
    if (G[i].size() == 1)
      str[G[i][0]] = '1';
    else
      vec.push_back(i);
  }
  si = vec.size();
  dfs(0);
  return 0;
}
