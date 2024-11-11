#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2 * 1e5;
char a[55][55];
int vis[100][55][55];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
bool valid(int i, int k) { return i >= 0 && i < n && k >= 0 && k < m; }
int dfs(char color, int iter, int starti, int startk, int i, int k) {
  if (!valid(i, k)) {
    return 0;
  }
  if (iter >= 4 && i == starti && k == startk) {
    return 1;
  }
  if (vis[color][i][k]) {
    return 0;
  }
  if (a[i][k] != color) return 0;
  vis[color][i][k] = 1;
  if (iter >= 4 && i == starti && k == startk) {
    return 1;
  }
  int ret = 0;
  for (int j = 0; j < 4; j++) {
    ret += dfs(color, iter + 1, starti, startk, i + dx[j], k + dy[j]);
  }
  if (ret > 0) {
    return 1;
  } else {
    return 0;
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < m; k++) {
        cin >> a[i][k];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < m; k++) {
        memset(vis, 0, sizeof(vis));
        if (!vis[a[i][k]][i][k]) {
          int lets_see = dfs(a[i][k], 0, i, k, i, k);
          if (lets_see) {
            cout << "YES" << '\n';
            return 0;
          }
        }
      }
    }
    cout << "NO" << '\n';
  }
}
