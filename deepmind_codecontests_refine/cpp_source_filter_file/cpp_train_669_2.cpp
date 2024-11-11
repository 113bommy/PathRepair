#include <bits/stdc++.h>
const int inf = 9999999;
using namespace std;
struct node {
  int x;
  int y;
} p[5][5], home[5];
long long d[8];
long long dis(node a, node b) {
  return (long long)(a.x - b.x) * (a.x - b.x) +
         (long long)(a.y - b.y) * (a.y - b.y);
}
void solve() {
  int ans = inf;
  for (int i = 1; i < 4; i++) {
    for (int j = 1; j < 4; j++) {
      for (int k = 1; k < 4; k++) {
        for (int l = 1; l < 4; l++) {
          d[0] = dis(p[i][0], p[j][1]);
          d[1] = dis(p[j][1], p[k][2]);
          d[2] = dis(p[k][2], p[l][3]);
          d[3] = dis(p[l][3], p[i][0]);
          d[4] = dis(p[i][0], p[k][2]);
          d[5] = dis(p[j][1], p[l][3]);
          sort(d, d + 6);
          if (d[0] == 0)
            continue;
          else if (d[0] == d[1] && d[1] == d[2] && d[2] == d[3] &&
                   2 * d[3] == d[4] && d[4] == d[5]) {
            ans = min(ans, i + j + k + l);
          }
        }
      }
    }
  }
  if (ans != inf)
    printf("%d\n", ans);
  else
    printf("-1\n");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < 4; i++) {
      scanf("%d%d", &p[0][i].x, &p[0][i].y);
      scanf("%d%d", &home[i].x, &home[i].y);
      int x = p[0][i].x - home[i].x;
      int y = p[0][i].y - home[i].y;
      p[1][i].x = home[i].x - y;
      p[1][i].y = home[i].y + x;
      p[2][i].x = home[i].x - x;
      p[2][i].y = home[i].y - y;
      p[3][i].x = home[i].x + y;
      p[3][i].y = home[i].y - x;
    }
    solve();
  }
  return 0;
}
