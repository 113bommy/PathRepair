#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
template <typename T>
inline void getint(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <typename T>
inline void print(T first) {
  if (first < 0) {
    putchar('-');
    return print(-first);
  }
  if (first < 10) {
    putchar('0' + first);
    return;
  }
  print(first / 10);
  putchar(first % 10 + '0');
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
int E, head[200200], nxt[200200 << 1], to[200200 << 1];
set<int> adj[200200 << 1];
int vst[200200], id[200200 << 1], dp[200200 << 1], p[200200], nn;
bool flag[200200 << 1];
void add_edge(int u, int v) {
  nxt[E] = head[u];
  to[E] = v;
  head[u] = E++;
  nxt[E] = head[v];
  to[E] = u;
  head[v] = E++;
}
priority_queue<pair<int, int> > q;
void dfs(int u, int fa = 0) {
  vst[u] = 1;
  p[u] = fa;
  dp[u] = dp[fa] + 1;
  q.push(pair<int, int>(dp[u], u));
  for (int e = head[u]; ~e; e = nxt[e]) {
    int v = to[e];
    if (v == fa) continue;
    if (vst[v]) {
      if (dp[v] < dp[u]) {
        adj[v].insert(++nn);
        dp[nn] = dp[v] + 1;
        id[nn] = u;
        p[nn] = v;
        q.push(pair<int, int>(dp[nn], nn));
      }
      continue;
    }
    adj[u].insert(v);
    dfs(v, u);
  }
}
vector<int> ans;
void solve() {
  int u, v;
  while (!q.empty()) {
    pair<int, int> tp = q.top();
    q.pop();
    if (flag[tp.second]) continue;
    u = tp.second;
    v = p[u];
    if (!v) return;
    adj[v].erase(u);
    if (adj[v].empty()) {
      flag[v] = true;
      if (p[v]) {
        adj[p[v]].erase(v);
        ans.push_back(id[p[v]]);
        ans.push_back(id[v]);
        ans.push_back(id[u]);
        continue;
      }
    } else {
      ans.push_back(id[u]);
      ans.push_back(id[v]);
      flag[*adj[v].begin()] = true;
      ans.push_back(id[*adj[v].begin()]);
      adj[v].erase(adj[v].begin());
    }
  }
}
int main() {
  int n, m, u, v;
  cin >> n >> m;
  nn = n;
  E = 0;
  for (int i = 1; i <= n; i++) head[i] = -1, id[i] = i;
  for (int i = 0; i < m; i++) {
    getint(u);
    getint(v);
    add_edge(u, v);
  }
  for (int i = 1; i <= n; i++)
    if (!vst[i]) {
      dfs(i);
      solve();
    }
  printf("%d\n", m = ans.size() / 3);
  for (int i = 0, j = 0; i < m; i++, j += 3) {
    printf("%d %d %d\n", ans[j], ans[j + 1], ans[j + 2]);
  }
  return 0;
}
