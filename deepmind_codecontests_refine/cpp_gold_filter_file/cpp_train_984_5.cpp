#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
const double pi = acos(-1.0);
int G[105][105][105], cc[105][105], vis[105];
int n, m;
void DFS(int c, int u, int ctr) {
  vis[u] = 1;
  cc[c][u] = ctr;
  for (int i = 1; i < n + 1; i++) {
    if (!vis[i] && (G[c][u][i] == 1)) {
      DFS(c, i, ctr);
    }
  }
}
int main() {
  ios_base ::sync_with_stdio(false);
  while (cin >> n >> m) {
    memset(G, 0, sizeof(G));
    memset(cc, 0, sizeof(cc));
    int a, b, c;
    for (int i = 0; i < m; i++) {
      cin >> a >> b >> c;
      G[c][a][b] = 1;
      G[c][b][a] = 1;
    }
    for (int i = 1; i < m + 1; i++) {
      memset(vis, 0, sizeof(vis));
      int ct = 1;
      for (int j = 1; j < n + 1; j++) {
        if (!vis[j]) {
          DFS(i, j, ct);
          ct++;
        }
      }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
      cin >> a >> b;
      int ans = 0;
      for (int j = 1; j < m + 1; j++)
        if ((cc[j][a] == cc[j][b]) && (cc[j][a] >= 1)) ans++;
      cout << ans << endl;
    }
  }
  return 0;
}
