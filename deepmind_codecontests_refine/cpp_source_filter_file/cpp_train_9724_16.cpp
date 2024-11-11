#include <bits/stdc++.h>
using namespace std;
const int MAXV = 210;
const int MAXE = 1020;
const int INF = (int)1e9 + 10;
struct E {
  int to, co;
  E(int t = 0, int c = 0) : to(t), co(c) {}
} eg[2 * MAXE];
struct Flow {
  vector<int> e[MAXV];
  bool used[MAXV];
  int ei, v;
  void init(int n) {
    v = n;
    ei = 0;
    for (int i = 0; i < n; i++) e[i] = vector<int>();
  }
  void add(int a, int b, int c) {
    eg[ei] = E(b, c);
    e[a].push_back(ei);
    ei++;
    eg[ei] = E(a, 0);
    e[b].push_back(ei);
    ei++;
  }
  int d[MAXV], qu[MAXV], ql, qr;
  bool BFS(int s, int t) {
    memset(d, -1, v * sizeof(int));
    ql = qr = 0;
    qu[qr++] = s;
    d[s] = 0;
    while (ql < qr && d[t] == -1) {
      int n = qu[ql++];
      vector<int> &v = e[n];
      for (int i = v.size() - 1; i >= 0; i--) {
        int u = v[i];
        if (d[eg[u].to] == -1 && eg[u].co > 0) {
          d[eg[u].to] = d[n] + 1;
          qu[qr++] = eg[u].to;
        }
      }
    }
    return d[t] != -1;
  }
  int ptr[MAXV];
  int go(int n, int p, int t) {
    if (n == t) return p;
    vector<int> &u = e[n];
    int temp;
    for (int i = ptr[n]; i < ((int)(u).size()); i++) {
      if (d[n] + 1 != d[eg[u[i]].to] || eg[u[i]].co == 0) continue;
      if ((temp = go(eg[u[i]].to, min(p, eg[u[i]].co), t)) == 0) continue;
      eg[u[i]].co -= temp;
      eg[u[i] ^ 1].co += temp;
      ptr[n] = i;
      return temp;
    }
    ptr[n] = ((int)(u).size());
    return 0;
  }
  void dfs(int u) {
    used[u] = true;
    for (int i : e[u]) {
      if (!used[eg[i].to] && eg[i].co) dfs(eg[i].to);
    }
  }
  int max_flow(int s, int t) {
    int ans = 0, temp;
    while (BFS(s, t)) {
      for (int i = 0; i < v; i++) ptr[i] = 0;
      while ((temp = go(s, INF, t)) > 0) ans += temp;
    }
    memset(used, 0, sizeof(used));
    dfs(s);
    return ans;
  }
} flow;
struct Edge {
  int from, to, cost;
  Edge(int a, int b, int c) : from(a), to(b), cost(c) {}
};
vector<Edge> es;
int p[MAXV];
void init(int n) {
  flow.init(n);
  for (Edge tmp : es) {
    int a = tmp.from, b = tmp.to, c = tmp.cost;
    flow.add(a, b, c);
    flow.add(b, a, c);
  }
}
vector<int> vec;
int e[MAXV][MAXV];
void dfs(int u, int p, int n, vector<int> &V) {
  V.push_back(u);
  for (int v = 0; v < n; v++) {
    if (e[u][v] >= 0 && v != p) {
      dfs(v, u, n, V);
    }
  }
}
void solve(int n, vector<int> &V) {
  int k = ((int)(V).size());
  for (int i = 0; i < k; i++) (void)0;
  (void)0;
  if (k == 1) {
    vec.push_back(V[0]);
    return;
  }
  int mn = INF, a = -1, b = -1;
  for (int i = 0; i < k; i++) {
    for (int j = i + 1; j < k; j++) {
      int u = V[i], v = V[j];
      if (e[u][v] >= 0 && e[u][v] < mn) {
        mn = e[i][j];
        a = u;
        b = v;
      }
    }
  }
  e[a][b] = e[b][a] = -1;
  vector<int> V1, V2;
  dfs(a, -1, n, V1);
  dfs(b, -1, n, V2);
  solve(n, V1);
  solve(n, V2);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  flow.init(n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    a--;
    b--;
    es.push_back(Edge(a, b, c));
  }
  fill(p, p + n, 0);
  fill(e[0], e[n], -1);
  int ans = 0;
  for (int i = 1; i < n; i++) {
    init(n);
    int tmp = flow.max_flow(i, p[i]);
    ans += tmp;
    e[i][p[i]] = e[p[i]][i] = tmp;
    for (int j = i + 1; j < n; j++) {
      if (flow.used[j] && p[i] == p[j]) p[j] = i;
    }
  }
  vector<int> V;
  for (int i = 0; i < n; i++) V.push_back(i);
  solve(n, V);
  printf("%d\n", ans);
  for (int i = 0; i < ((int)(vec).size()); i++)
    printf("%d%c", vec[i] + 1, " \n"[i == ((int)(vec).size()) - 1]);
  return 0;
}
