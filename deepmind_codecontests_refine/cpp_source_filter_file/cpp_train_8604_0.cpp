#include <bits/stdc++.h>
using namespace std;
vector<int> e[300000];
int D[300000];
int P[300000];
int was[300000];
void bfs(int s, int forb) {
  queue<int> q;
  P[s] = -1;
  D[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    vector<int> &ee = e[x];
    for (int i = 0; i < ee.size(); ++i) {
      int v = ee[i];
      if (v == forb) continue;
      if (D[v] < 0) {
        D[v] = D[x] + 1;
        P[v] = x;
        q.push(v);
      }
    }
  }
}
int ecnt;
int vcnt;
void dfs(int x, int c) {
  was[x] = c;
  ++vcnt;
  vector<int> &ee = e[x];
  for (int i = 0; i < ee.size(); ++i) {
    int v = ee[i];
    if (v == 0) continue;
    ++ecnt;
    if (!was[v]) dfs(v, c);
  }
}
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) D[i] = -1;
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  bfs(0, -1);
  if (D[n - 1] >= 0 && D[n - 1] <= 4) {
    int v = n - 1;
    vector<int> res;
    while (v != -1) {
      res.push_back(v);
      v = P[v];
    }
    printf("%d\n", res.size() - 1);
    for (int i = res.size() - 1; i >= 0; --i) printf("%d ", res[i] + 1);
    return;
  }
  for (int v2 = 0; v2 < n; ++v2)
    if (D[v2] == 2) {
      int v = v2;
      vector<int> res;
      while (v != -1) {
        res.push_back(v);
        v = P[v];
      }
      printf("%d\n", res.size() + 1);
      for (int i = res.size() - 1; i >= 0; --i) printf("%d ", res[i] + 1);
      printf("1 %d", n);
      return;
    }
  for (int i = 0; i < n; ++i) was[i] = 0;
  for (int i = 0; i < e[0].size(); ++i) {
    vcnt = 0;
    ecnt = 0;
    int v1 = e[0][i];
    if (was[v1]) continue;
    dfs(v1, v1);
    if (vcnt >= 46340 || ecnt != vcnt * (vcnt - 1)) {
      for (int i = 0; i < n; ++i) D[i] = -1;
      int v3 = -1;
      for (int i = 0; i < n; ++i)
        if (was[i] == v1 && e[i].size() < vcnt) {
          if (v3 == -1 || e[v3].size() > e[i].size()) v3 = i;
        }
      bfs(v1, 0);
      for (int v2 = 0; v2 < n; ++v2)
        if (D[v2] == 2) {
          int v = v2;
          vector<int> res;
          while (v != -1) {
            res.push_back(v);
            v = P[v];
          }
          printf("%d\n", res.size() + 2);
          printf("1 ");
          for (int i = res.size() - 1; i >= 0; --i) printf("%d ", res[i] + 1);
          printf("%d %d", v1 + 1, n);
          return;
        }
    }
  }
  printf("-1");
}
int main() {
  solve();
  return 0;
}
