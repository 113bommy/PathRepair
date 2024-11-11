#include <bits/stdc++.h>
using namespace std;
double PI = 3.141592653589793238462643383279;
const double EPS = 1e-9;
const long long MOD = 998244353;
const int inf = 1 << 30;
const long long linf = 1LL << 60;
class SCC {
 public:
  int V, K;
  vector<vector<int>> G, rG, E;
  vector<int> vs;
  vector<bool> used;
  vector<int> cmp;
  void init(int _n) {
    V = _n;
    G.assign(V, vector<int>());
    rG.assign(V, vector<int>());
    used.assign(V, false);
    cmp.assign(V, 0);
    E.assign(V, vector<int>());
  }
  void add_edge(int from, int to) {
    G[from].push_back(to);
    rG[to].push_back(from);
  }
  void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < (int)G[v].size(); i++) {
      if (!used[G[v][i]]) dfs(G[v][i]);
    }
    vs.push_back(v);
  }
  void rdfs(int v, int k) {
    used[v] = true;
    cmp[v] = k;
    for (int i = 0; i < (int)rG[v].size(); i++) {
      if (!used[rG[v][i]]) rdfs(rG[v][i], k);
    }
  }
  int scc() {
    for (int i = 0; i < (int)V; i++) used[i] = false;
    vs.clear();
    for (int v = 0; v < V; v++) {
      if (!used[v]) dfs(v);
    }
    for (int i = 0; i < (int)V; i++) used[i] = false;
    int k = 0;
    for (int i = (int)vs.size() - 1; i >= 0; i--) {
      if (!used[vs[i]]) rdfs(vs[i], k++);
    }
    K = k;
    return k;
  }
  void make_graph() {
    for (int v = 0; v < V; v++) {
      for (int e : G[v]) {
        if (cmp[v] < cmp[e]) {
          E[cmp[v]].push_back(cmp[e]);
        }
      }
    }
    for (int i = 0; i < K; i++) {
      sort(E[i].begin(), E[i].end());
      E[i].erase(unique(E[i].begin(), E[i].end()), E[i].end());
    }
  }
};
int n;
char buf[2001];
bool e[2001][2001];
int deg[2001], deg2[2001];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < (int)n; i++) {
    scanf(" %s", buf);
    for (int j = 0; j < (int)n; j++) e[i][j] = buf[j] - '0';
  }
  if (n <= 6) {
    vector<int> cnt(n, 0);
    for (int i = 0; i < (int)(1 << n); i++) {
      int x = 0;
      for (int j = 0; j < (int)n; j++)
        if (i & (1 << j)) x++;
      SCC scc;
      scc.init(n);
      for (int j = 0; j < (int)n; j++) {
        for (int k = 0; k < (int)n; k++) {
          if (!e[j][k]) continue;
          if (i & (1 << j)) {
            if (i & (1 << k))
              scc.add_edge(j, k);
            else
              scc.add_edge(k, j);
          } else {
            if (!(i & (1 << k)))
              scc.add_edge(j, k);
            else
              scc.add_edge(k, j);
          }
        }
      }
      int y = scc.scc();
      if (y == 1) {
        cnt[x]++;
      }
    }
    for (int i = 0; i < (int)n; i++) {
      if (cnt[i]) {
        long long ans = cnt[i];
        for (long long j = 1; j <= i; j++) ans = ans * j % MOD;
        printf("%d %lld\n", i, ans);
        return 0;
      }
    }
    puts("-1");
    return 0;
  }
  {
    SCC scc;
    scc.init(n);
    for (int i = 0; i < (int)n; i++)
      for (int j = 0; j < (int)n; j++) {
        if (!e[i][j]) continue;
        scc.add_edge(i, j);
      }
    if (scc.scc() == 1) {
      puts("0 1");
      return 0;
    }
  }
  for (int i = 0; i < (int)n; i++) {
    for (int j = 0; j < (int)n; j++)
      if (e[i][j]) deg[i]++;
  }
  int cnt = 0;
  for (int i = 0; i < (int)n; i++) {
    for (int j = 0; j < (int)n; j++) deg2[j] = deg[j];
    deg2[i] = n - 1 - deg2[i];
    for (int j = 0; j < (int)n; j++) {
      if (j == i) continue;
      if (e[j][i])
        deg2[j]--;
      else
        deg2[j]++;
    }
    sort(deg2, deg2 + n);
    int sum = 0;
    for (int j = 0; j < (int)n - 1; j++) {
      sum += deg2[j];
      int tmp = (j + 1) * j / 2;
      if (sum == tmp) {
        cnt++;
        break;
      }
    }
  }
  printf("1 %d\n", cnt);
}
