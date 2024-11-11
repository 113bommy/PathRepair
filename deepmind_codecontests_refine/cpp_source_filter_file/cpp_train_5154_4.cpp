#include <bits/stdc++.h>
const long long MOD = (long long)1e9 + 7;
using namespace std;
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 0) {
    long long f = 1LL * power(a, b / 2);
    return 1LL * f * f;
  }
  b--;
  return 1LL * power(a, b) * a;
}
int left(int i) { return 2 * i; }
int right(int i) { return 2 * i + 1; }
vector<vector<pair<int, int> > > graph(100005);
struct Node {
 private:
  int x, prev;
  long long dist;

 public:
  Node(int a, long long b, int c) { x = a, dist = b, prev = c; }
  Node(int a) { x = a, dist = 0, prev = a; }
  Node(int a, long long b) { x = a, dist = b; }
  long long getDist() { return dist; }
  int getX() { return x; }
  int getPrev() { return prev; }
};
struct cmp {
  bool operator()(Node &a, Node &b) { return a.getDist() > b.getDist(); }
};
void addEdge(int u, int v, int w) {
  graph[u].push_back(make_pair(v, w));
  graph[v].push_back(make_pair(u, w));
}
void direcEdge(int u, int v, int w) { graph[u].push_back(make_pair(v, w)); }
struct Node2 {
  int a[11];
  Node2() {
    for (int i = 0; i < 11; i++) a[i] = 1e9;
  }
  void insert(int v) {
    a[10] = v;
    sort(a, a + 11);
  }
};
Node2 dp[100005][17];
int lvl[100005];
int root[100005][17];
int pi[100005];
void dfs(int par, int node) {
  root[node][0] = par;
  pi[node] = par;
  for (int i = 0; i < graph[node].size(); i++) {
    int v = graph[node][i].first;
    if (v != par) {
      lvl[v] = lvl[node] + 1;
      dfs(node, v);
    }
  }
}
Node2 merge(Node2 x, Node2 y) {
  Node2 res = x;
  for (int i = 0; i <= 10; i++) res.insert(y.a[i]);
  return res;
}
void calcRoot(int n) {
  for (int j = 1; j < 17; j++)
    for (int i = (1 << j); i <= n; i++) {
      root[i][j] = root[root[i][j - 1]][j - 1];
      dp[i][j] = merge(dp[i][j - 1], dp[root[i][j - 1]][j - 1]);
    }
}
int lca(int p, int q) {
  if (lvl[p] < lvl[q]) swap(p, q);
  int stp;
  for (stp = 0; (1 << stp) <= lvl[p]; stp++)
    ;
  stp--;
  for (int i = stp; i >= 0; i--)
    if (lvl[p] - (1 << i) >= lvl[q]) p = root[p][i];
  if (p == q) return p;
  for (int i = stp; i >= 0; i--)
    if (root[p][i] != 1e9 && root[p][i] != root[q][i]) {
      p = root[p][i];
      q = root[q][i];
    }
  return pi[p];
}
Node2 get(int v, int k) {
  Node2 res;
  int stp;
  for (stp = 0; (1 << stp) <= lvl[v]; stp++)
    ;
  for (int i = stp; i >= 0; i--) {
    if ((1 << i) & k) {
      res = merge(res, dp[v][i]);
      v = root[v][i];
    }
  }
  return res;
}
int main() {
  int n, m, q, k, u, v, c;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", &u, &v);
    addEdge(u, v, 1);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &c);
    dp[c][0].insert(i + 1);
  }
  dfs(0, 1);
  calcRoot(n);
  while (q--) {
    scanf("%d %d %d", &u, &v, &k);
    int lc = lca(u, v);
    Node2 x = get(u, lvl[u] - lvl[lc]);
    Node2 y = get(v, lvl[v] - lvl[lc] + 1);
    Node2 res = merge(x, y);
    int sz = 0;
    while (sz < k && res.a[sz] < 1e9) {
      sz++;
    }
    cout << sz << " ";
    for (int i = 0; i < sz; i++) cout << res.a[i] << " ";
    cout << "\n";
  }
}
