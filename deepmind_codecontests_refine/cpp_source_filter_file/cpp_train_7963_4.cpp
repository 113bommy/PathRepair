#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int _N = 1010;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
char s[_N][_N];
int n, m, f[3][_N][_N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  static vector<pair<int, int> > Queue;
  static int L, R, len[3];
  Queue.push_back(make_pair(0, 0));
  for (int k = 0; k < 3; k++) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (s[i][j] == k + '1')
          f[k][i][j] = 0, Queue.push_back(make_pair(i, j)), ++R;
        else
          f[k][i][j] = -1;
    len[k] = INF;
    while (L ^ R) {
      static pair<int, int> Get;
      Get = Queue[++L];
      static int ux, uy;
      ux = Get.first, uy = Get.second;
      for (int i = 0; i < 4; i++) {
        static int vx, vy;
        vx = ux + dx[i], vy = uy + dy[i];
        if (vx >= 1 && vx <= n && vy >= 1 && vy <= 3 && f[k][vx][vy] == -1 &&
            s[vx][vy] != '#') {
          if (s[ux][uy] == k + '1' && s[vx][vy] == (k + 1) % 3 + '1')
            len[k] = 0;
          if (s[vx][vy] == '.')
            f[k][vx][vy] = f[k][ux][uy] + 1, Queue.push_back(make_pair(vx, vy)),
            ++R;
        }
      }
    }
  }
  static int ans;
  ans = INF;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      for (int k = 0; k < 3; k++)
        if (f[k][i][j] != -1 && f[(k + 1) % 3][i][j] != -1)
          len[k] = min(len[k], f[k][i][j] + f[(k + 1) % 3][i][j] - 1);
      if (f[0][i][j] != -1 && f[1][i][j] != -1 && f[2][i][j] != -1)
        ans = min(ans, f[0][i][j] + f[1][i][j] + f[2][i][j] - 2);
    }
  for (int k = 0; k < 3; k++) ans = min(ans, len[k] + len[(k + 1) % 3]);
  if (ans == INF) ans = -1;
  printf("%d\n", ans);
  return 0;
}
