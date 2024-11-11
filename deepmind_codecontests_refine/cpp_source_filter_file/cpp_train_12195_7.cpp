#include <bits/stdc++.h>
using namespace std;
struct EDGE {
  long long u, v;
};
EDGE edge[100000 + 1];
long long n, R[100000 + 1], B[100000 + 1], cnt = 0;
vector<long long> G[100000 + 1];
long long par[100000 + 1];
bool visited[100000 + 1];
void dfs(long long u) {
  if (visited[u]) return;
  visited[u] = 1;
  for (auto v : G[u]) {
    if (!visited[v]) {
      dfs(v);
      R[u] += R[v];
      B[u] += B[v];
      par[v] = u;
    }
  }
}
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long color;
    cin >> color;
    if (color == 1) {
      R[i] = 1;
      B[i] = 0;
    } else if (color == 2) {
      R[i] = 0;
      B[i] = 1;
    }
  }
  for (long long i = 1; i <= n - 1; i++) {
    cin >> edge[i].u >> edge[i].v;
    long long u = edge[i].u;
    long long v = edge[i].v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  long long root = 1;
  par[root] = -1;
  dfs(root);
  for (long long i = 1; i <= n - 1; i++) {
    long long u = edge[i].u, v = edge[i].v;
    if (par[v] == u) {
      long long red = R[root] - R[v];
      long long blu = B[root] - B[v];
      if (red == 0 && B[v] == 0)
        cnt++;
      else if (blu == 0 && R[v] == 0)
        cnt++;
    } else {
      long long red = R[root] - R[u];
      long long blu = B[root] - B[u];
      if (red == 0 && B[u] == 0)
        cnt++;
      else if (blu == 0 && R[u] == 0)
        cnt++;
    }
  }
  cout << cnt;
}
