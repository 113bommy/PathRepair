#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 7;
const int inf = INT_MAX;
const long long inff = 1e18;
const long long mod = 1e9 + 7;
vector<int> depth[maxn];
vector<int> G[maxn];
int used[maxn], dist[maxn];
int pp[maxn];
void dfs(int now, int p, int d) {
  used[now] = 1;
  pp[now] = p;
  depth[d].push_back(now);
  dist[now] = d;
  for (int i : G[now])
    if (!used[i]) dfs(i, now, d + 1);
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) G[i].clear(), depth[i].clear(), used[i] = 0;
    for (int i = 1; i <= m; i++) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
      if (!used[i]) dfs(i, -1, 1);
    int tar = -1;
    for (int i = 1; i <= n; i++)
      if (dist[i] >= (n + 1) / 2) {
        tar = i;
        break;
      }
    if (tar != -1) {
      cout << "PATH" << '\n';
      cout << dist[tar] << '\n';
      while (tar != -1) {
        cout << tar << ' ';
        tar = pp[tar];
      }
    } else {
      cout << "PAIRING" << '\n';
      int cnt = ((((n + 1) / 2) & 1) ? (((n + 1) / 2) + 1) / 2
                                     : (((n + 1) / 2) + 0) / 2);
      cout << cnt * 2 << '\n';
      for (int i = 1; i <= n; i++) {
        if (cnt <= 0) break;
        for (int j = 0; j + 1 < ((int)(depth[i]).size()); j += 2) {
          if (cnt <= 0) break;
          cout << depth[i][j] << ' ' << depth[i][j + 1] << '\n';
          cnt--;
        }
      }
    }
    cout << '\n';
  }
}
