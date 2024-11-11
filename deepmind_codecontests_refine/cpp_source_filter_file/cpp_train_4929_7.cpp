#include <bits/stdc++.h>
using namespace std;
void solve() {
  static int dist[64][64][64];
  static int bestcar[64][64];
  static int distchg[1024][64][64];
  int n, m, r;
  cin >> n >> m >> r;
  for (int i = 0; i < (int)(m); i++)
    for (int j = 0; j < (int)(n); j++)
      for (int k = 0; k < (int)(n); k++) {
        cin >> dist[i][j][k];
      }
  for (int car = 0; car < (int)(m); car++)
    for (int k = 0; k < (int)(n); k++)
      for (int i = 0; i < (int)(n); i++)
        for (int j = 0; j < (int)(n); j++)
          if (dist[car][i][j] > dist[car][i][k] + dist[car][k][j])
            dist[car][i][j] = dist[car][i][k] + dist[car][k][j];
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(n); j++) {
      int cost = INT_MAX;
      for (int car = 0; car < (int)(m); car++)
        if (dist[car][i][j] < cost) {
          cost = dist[car][i][j];
          bestcar[i][j] = car;
        }
    }
  memset(distchg, 0x1f, sizeof(distchg));
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(n); j++) {
      distchg[0][i][j] = dist[bestcar[i][j]][i][j];
    }
  for (int c = (int)(1); c < (int)(n + 1); c++)
    for (int k = 0; k < (int)(n); k++)
      for (int i = 0; i < (int)(n); i++)
        for (int j = 0; j < (int)(n); j++) {
          if (distchg[c][i][j] > distchg[c - 1][k][j] + distchg[0][i][k])
            distchg[c][i][j] = distchg[c - 1][k][j] + distchg[0][i][k];
        }
  for (int i = 0; i < (int)(r); i++) {
    int s, e, k;
    cin >> s >> e >> k;
    s--, e--;
    cout << distchg[k][s][e] << endl;
  }
}
int main() {
  solve();
  return 0;
}
