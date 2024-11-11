#include <bits/stdc++.h>
using namespace std;
int mp[500][500], dist[500], visit[500];
int main() {
  int n, m, i, j, flag, a, b;
  while (cin >> n >> m) {
    memset(mp, 0, sizeof(mp));
    flag = 0;
    while (m--) {
      scanf("%d%d", &a, &b);
      mp[a][b] = mp[b][a] = 1;
      if ((a == n && b == 1) || (a == 1 && b == n)) {
        flag = 1;
      }
    }
    if (flag) {
      for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) mp[i][j] ^= 1;
      }
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        if (!mp[i][j]) mp[i][j] = 1 << 29;
      }
    }
    memset(visit, 0, sizeof(visit));
    visit[1] = 1;
    for (int i = 0; i <= n; i++) {
      dist[i] = mp[1][i];
    }
    int index;
    for (int i = 1; i <= n; i++) {
      int mincost = 1 << 29;
      for (int j = 1; j <= n; j++) {
        if (!visit[j] && dist[j] < mincost) {
          mincost = dist[j];
          index = j;
        }
      }
      visit[index] = 1;
      for (int j = 1; j <= n; j++) {
        if (!visit[j] && dist[j] > dist[index] + mp[index][j]) {
          dist[j] = dist[index] + mp[index][j];
        }
      }
    }
    if (dist[n] < (1 << 29))
      cout << dist[n] << endl;
    else
      cout << -1 << endl;
  }
}
