#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int dis[N][N];
int vis[N], arr[N];
long long ans[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> dis[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  for (int i = n; i > 0; --i) {
    int x = arr[i];
    vis[x] = 1;
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k) {
        dis[j][k] = min(dis[j][k], dis[j][x] + dis[x][k]);
        if (vis[j] && vis[k]) ans[i] += dis[j][k];
      }
    }
  }
  for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
  return 0;
}
