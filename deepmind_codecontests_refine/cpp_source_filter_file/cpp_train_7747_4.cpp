#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e5 + 10;
struct Tree {
  int n, h[MAXN];
  long long SumDist, MaxDist, sDis[MAXN], dis[MAXN], cnt[MAXN];
  vector<int> adj[MAXN], c[MAXN];
  bool fre[MAXN];
  long long n1, n3, ans, f[MAXN], g[MAXN];
  void AddEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  void Read() {
    for (int i = 1; i <= n - 1; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    memset(fre, true, sizeof fre);
  }
  void DFS(int u) {
    fre[u] = false;
    cnt[u] = 1;
    dis[u] = h[u];
    for (int i = 0; i < (int)adj[u].size(); ++i) {
      int v = adj[u][i];
      if (fre[v]) {
        c[u].push_back(v);
        h[v] = h[u] + 1;
        DFS(v);
        dis[u] += dis[v];
        cnt[u] += cnt[v];
      }
    }
  }
  void Cal(int u, long long s) {
    sDis[u] = s + dis[u] - h[u] * cnt[u] + h[u] * (n - cnt[u]);
    SumDist += sDis[u];
    MaxDist = max(sDis[u], MaxDist);
    for (int i = 0; i < (int)c[u].size(); ++i) {
      int v = c[u][i];
      s += dis[v] - 2 * h[u] * cnt[v];
    }
    for (int i = 0; i < (int)c[u].size(); ++i) {
      int v = c[u][i];
      Cal(v, s - h[u] - (dis[v] - 2 * h[u] * cnt[v]));
    }
  }
  void DP(int u) {
    f[u] = sDis[u] * n1 + n1 * n3 * h[u];
    g[u] = sDis[u] * n3 + n1 * n3 * h[u];
    ans = max(ans, f[u] + g[u] - 2 * n1 * n3 * h[u]);
    for (int i = 0; i < (int)c[u].size(); ++i) {
      int v = c[u][i];
      DP(v);
      ans = max(ans, max(f[v] + g[u], g[v] + f[u]) - 2 * n1 * n3 * h[u]);
      f[u] = max(f[u], f[v]);
      g[u] = max(g[u], g[v]);
    }
  }
} T[3];
int main() {
  scanf("%d%d%d", &T[0].n, &T[1].n, &T[2].n);
  for (int i = 0; i < 3; ++i) {
    T[i].Read();
    T[i].DFS(1);
    T[i].Cal(1, 0);
  }
  int p[3] = {0, 1, 2};
  long long ans = 0;
  do {
    T[p[1]].n1 = T[p[0]].n;
    T[p[1]].n3 = T[p[2]].n;
    T[p[1]].ans = 0;
    T[p[1]].DP(1);
    int n1 = T[p[0]].n, n2 = T[p[1]].n, n3 = T[p[2]].n;
    ans = max(ans, T[p[0]].MaxDist * (n2 + n3) + T[p[2]].MaxDist * (n1 + n2) +
                       n1 * (n2 + n3) + n3 * (n1 + n2) + T[p[1]].ans);
  } while (next_permutation(p, p + 3));
  cout << ans + (T[0].SumDist + T[1].SumDist + T[2].SumDist) / 2;
  return 0;
}
