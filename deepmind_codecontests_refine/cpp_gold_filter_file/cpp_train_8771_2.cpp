#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct Edge {
  int u, v, nxt, w;
} edge[maxn << 1];
int head[maxn], cnt = -1;
inline void add_edge(int u, int v, int w) {
  edge[++cnt] = {u, v, head[u], w};
  head[u] = cnt;
}
int son[maxn];
long long sum;
struct Node {
  long long son, w;
  bool operator<(const Node &rhs) const {
    return son * w - son * (w / 2) < rhs.son * rhs.w - rhs.son * (rhs.w / 2);
  }
};
priority_queue<Node> pq;
int dfs(int u, int fa) {
  bool isleaf = true;
  for (int i = head[u]; ~i; i = edge[i].nxt) {
    Edge &e = edge[i];
    if (e.v != fa) {
      isleaf = false;
      int s = dfs(e.v, u);
      pq.push(Node{s, e.w});
      sum += 1ll * s * e.w;
      son[u] += s;
    }
  }
  if (isleaf) son[u] = 1;
  return son[u];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    sum = 0;
    long long n, S;
    cin >> n >> S;
    for (int i = 1; i <= n; ++i) head[i] = -1, son[i] = 0;
    cnt = -1;
    for (int i = 1; i < n; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      add_edge(u, v, w);
      add_edge(v, u, w);
    }
    dfs(1, -1);
    long long ans = 0;
    while (!pq.empty() && sum > S) {
      Node u = pq.top();
      pq.pop();
      long long pc = u.son * u.w - u.son * (u.w / 2);
      sum -= pc;
      ++ans;
      pq.push(Node{u.son, u.w / 2});
    }
    cout << ans << endl;
    while (!pq.empty()) pq.pop();
  }
  return 0;
}
