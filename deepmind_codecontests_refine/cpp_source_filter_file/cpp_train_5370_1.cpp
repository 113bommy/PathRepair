#include <bits/stdc++.h>
using namespace std;
int n, N, a[2005][2005], mn = 1000000000, mnp, dis[2005], vis[2005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      cin >> a[i][j];
      if (a[i][j] < mn) {
        mn = a[i][j];
        mnp = i;
      }
    }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) a[i][j] = a[j][i] = a[i][j] - mn;
  for (int i = 1; i <= n; i++) {
    dis[i] = a[mnp][i];
    for (int j = 1; j <= n; j++)
      if (i != j) dis[i] = min(dis[i], a[i][j] * 2);
  }
  dis[0] = 1000000000;
  vis[mnp] = 1;
  for (int FUCK = 1; FUCK < n; FUCK++) {
    int cur = 0;
    for (int i = 1; i <= n; i++)
      if (dis[i] <= dis[cur] && !vis[i]) cur = i;
    vis[cur] = 1;
    for (int i = 1; i <= n; i++)
      if (!vis[i]) dis[i] = min(dis[i], dis[cur] + a[i][cur]);
  }
  for (int i = 1; i <= n; i++) cout << mn * (n - 1) + dis[i] << '\n';
}
