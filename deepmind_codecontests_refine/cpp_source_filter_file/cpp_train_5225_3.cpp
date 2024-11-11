#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int M = 500005;
int n, m, K, v[M], d[M];
vector<int> v1[N][N], v2[N][N];
long long f[2][N][N][2];
long long sum[N][N], sx[N], sy[N];
void UPD(long long &x, long long y) { x > y ? x = y : 233; }
bool ins(int x, int y, int T, int v) {
  if (x + y > T) return 0;
  if ((x + y) % 4 != T % 4) return 0;
  sum[x][y] += v;
  return 1;
}
int main() {
  scanf("%d%d%d", &n, &m, &K);
  for (int i = (int)(1); i <= (int)(K); i++) {
    int x, y, d, T;
    scanf("%d%d%d%d%d", &x, &y, &d, &T, &v[i]);
    bool fl0 = ins(x + 0, y + 0, T + 0, v[i]);
    bool fl1 = ins(x + d, y - d, T + 1, v[i]);
    bool fl2 = ins(x + d, y + 0, T + 2, v[i]);
    bool fl3 = ins(x + 0, y + d, T + 3, v[i]);
    if (fl1 && fl2) v2[x + d][y].push_back(i);
    if (fl3 && fl0) v2[x][y + d].push_back(i);
    if (fl0 && fl2) v1[x + d][y].push_back(i);
    ::d[i] = d;
  }
  memset(f, 70, sizeof(f));
  f[0][0][0][0] = f[0][0][0][1] = sum[0][0];
  for (int i = (int)(1); i <= (int)(n + m - 2); i++) {
    int now = (i & 1), pre = now ^ 1;
    for (int py = (int)(0); py <= (int)(m - 1); py++) {
      int px = i - py;
      if (px < 0 || px >= n) continue;
      memset(sx, 0, sizeof(sx));
      memset(sy, 0, sizeof(sy));
      for (auto j : v2[px][py]) sy[py - d[j]] += v[j];
      for (auto j : v1[px][py]) sx[px - d[j]] += v[j];
      for (int j = (int)(py); j >= (int)(0); j--) sx[j] += sx[j + 1];
      for (int j = (int)(px); j >= (int)(0); j--) sy[j] += sy[j + 1];
      if (px != 0) {
        for (int j = (int)(0); j <= (int)(px - 1); j++)
          UPD(f[now][px][j][0], f[pre][px - 1][j][0]);
        for (int j = (int)(0); j <= (int)(py); j++)
          UPD(f[now][px][px - 1][0], f[pre][px - 1][j][1]);
        for (int j = (int)(0); j <= (int)(px); j++)
          f[now][px][j][0] += sum[px][py] - sx[j];
      }
      if (py != 0) {
        for (int j = (int)(0); j <= (int)(py - 1); j++)
          UPD(f[now][px][j][1], f[pre][px][j][1]);
        for (int j = (int)(0); j <= (int)(px); j++)
          UPD(f[now][px][py - 1][1], f[pre][px][j][0]);
        for (int j = (int)(0); j <= (int)(py); j++)
          f[now][px][j][1] += sum[px][py] - sy[j];
      }
    }
    memset(f[pre], 70, sizeof(f[pre]));
  }
  long long ans = 1ll << 60;
  for (int i = (int)(0); i <= (int)(n - 1); i++)
    UPD(ans, f[(n + m - 2) & 1][n - 1][i][0]);
  for (int i = (int)(0); i <= (int)(m - 1); i++)
    UPD(ans, f[(n + m - 2) & 1][n - 1][i][1]);
  printf("%lld\n", ans);
}
