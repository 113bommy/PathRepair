#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
int n, m, k, u[N], v[N];
int deg[N], ans[N];
vector<int> G[N], id[N];
bool ok[N];
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &u[i], &v[i]);
    G[u[i]].push_back(v[i]);
    G[v[i]].push_back(u[i]);
    deg[u[i]]++;
    deg[v[i]]++;
    id[u[i]].push_back(i);
    id[v[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    ok[i] = 1;
  }
  int c = 0;
  queue<int> que;
  for (int i = 1; i <= n; i++) {
    if (deg[i] < k) {
      ok[i] = 0;
      que.push(i);
      c++;
    }
  }
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      deg[v]--;
      if (ok[v] && deg[v] < k) {
        ok[v] = 0;
        que.push(v);
        c++;
      }
    }
  }
  ans[m] = n - c;
  for (int i = m - 1; i > 0; i--) {
    c = 0;
    int x = u[i + 1], y = v[i + 1];
    if (ok[x] && ok[y]) {
      deg[x]--;
      deg[y]--;
      if (deg[x] < k) {
        ok[x] = 0;
        c++;
        que.push(x);
      }
      if (deg[y] < k) {
        ok[y] = 0;
        c++;
        que.push(y);
      }
    }
    while (!que.empty()) {
      int z = que.front();
      que.pop();
      for (int j = 0; j < G[z].size(); j++) {
        int w = G[z][j];
        if (id[z][j] >= i + 1) continue;
        deg[w]--;
        if (ok[w] && deg[w] < k) {
          ok[w] = 0;
          que.push(w);
          c++;
        }
      }
    }
    ans[i] = ans[i + 1] - c;
  }
  for (int i = 1; i <= m; i++) {
    printf("%d\n", ans[i]);
  }
}
