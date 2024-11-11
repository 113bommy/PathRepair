#include <bits/stdc++.h>
using namespace std;
const int N = 504;
int ans[N];
int dis[N][N];
int del[N];
bool vis[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &dis[i][j]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &del[i]);
  }
  for (int i = n; i >= 1; --i) {
    int node = del[i];
    vis[node] = 1;
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k) {
        dis[j][k] = min(dis[j][k], dis[j][node] + dis[node][k]);
        if (vis[j] && vis[k]) ans[i] += dis[j][k];
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << ' ';
  }
  return 0;
}
