#include <bits/stdc++.h>
template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}
using namespace std;
long long cases, ct = 0, dist[300005], pre[300005], vis[300005], leaf[300005],
                 n, m, k;
vector<long long> G[300005];
void dfs(long long node) {
  vis[node] = 1;
  for (long long i = 0; i < G[node].size(); i++) {
    long long v = G[node][i];
    if (vis[v]) continue;
    pre[v] = node;
    dist[v] = dist[node] + 1;
    leaf[node]++;
    dfs(v);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  ;
  long long a, b;
  while (cin >> n >> m >> k) {
    long long i, j;
    for (i = 0; i < m; i++) {
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    dfs(1);
    for (i = 1; i <= n; i++) {
      if (dist[i] >= n / k) {
        cout << "PATH" << endl;
        cout << dist[i] + 1 << endl;
        for (j = i; j; j = pre[j]) {
          cout << j << " ";
        }
        cout << endl;
        return 0;
      }
    }
    cout << "CYCLES" << endl;
    for (i = 1; i <= n; i++) {
      if (!leaf[i]) {
        vector<long long> V;
        for (j = 0; j < G[i].size(); j++) {
          if (G[i][j] != pre[i]) V.push_back(G[i][j]);
        }
        long long x = V[0], y = V[1];
        if (dist[y] > dist[x]) swap(x, y);
        if ((dist[i] - dist[x] + 1) % 3 != 0 && (dist[i] - dist[x] + 1) > 3) {
          cout << dist[i] - dist[x] + 1 << endl;
          for (j = i; j != x; j = pre[j]) {
            cout << j << " ";
          }
          cout << x << endl;
        } else if ((dist[i] - dist[y] + 1) % 3 != 0 &&
                   (dist[i] - dist[y] + 1) > 3) {
          cout << dist[i] - dist[y] + 1 << endl;
          for (j = i; j != y; j = pre[j]) {
            cout << j << " ";
          }
          cout << y << endl;
        } else if ((dist[x] - dist[y] + 2) % 3 != 0 &&
                   (dist[x] - dist[y] + 2) > 3) {
          cout << dist[x] - dist[y] + 2 << endl;
          cout << i << " ";
          for (j = x; j != y; j = pre[j]) {
            cout << j << " ";
          }
          cout << y << endl;
        }
        k--;
        if (k == 0) break;
      }
    }
    if (k != 0) {
      cout << "-1" << endl;
    }
  }
}
