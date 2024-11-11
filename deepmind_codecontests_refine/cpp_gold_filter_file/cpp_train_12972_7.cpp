#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:33554432")
using namespace std;
int IT_MAX = 1 << 18;
const long long MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const double ERR = 1e-10;
int in[2550][2];
inline double sq(double a) { return a * a; }
double getdis(int a, int b) {
  return sqrt(sq(in[a][0] - in[b][0]) + sq(in[a][1] - in[b][1]));
}
double dp[2550][2550][2];
int main() {
  int N, i, j;
  scanf("%d", &N);
  for (i = 0; i < N; i++) scanf("%d %d", &in[i][0], &in[i][1]);
  if (N == 2) return !printf("%.20lf\n", getdis(0, 1));
  for (i = 0; i < N; i++) {
    int p = (i + N - 1) % N;
    dp[i][i][0] = getdis(p, i);
    p = (i + 1) % N;
    dp[i][i][1] = getdis(p, i);
  }
  for (i = 1; i < N; i++) {
    for (j = 0; j < N; j++) {
      int x = j, y = (i + j) % N;
      int p = (x + N - 1) % N;
      dp[x][y][0] = 0;
      dp[x][y][0] = max(dp[x][y][0], dp[(x + 1) % N][y][0] + getdis(p, x));
      dp[x][y][0] = max(dp[x][y][0], dp[x][(y + N - 1) % N][1] + getdis(p, y));
      p = (y + 1) % N;
      dp[x][y][1] = 0;
      dp[x][y][1] = max(dp[x][y][1], dp[(x + 1) % N][y][0] + getdis(p, x));
      dp[x][y][1] = max(dp[x][y][1], dp[x][(y + N - 1) % N][1] + getdis(p, y));
    }
  }
  double ans = 0;
  for (i = 0; i < N; i++) ans = max(ans, dp[(i + 2) % N][i][0]);
  return !printf("%.20lf\n", ans);
}
