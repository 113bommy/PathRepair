#include <bits/stdc++.h>
using namespace std;
const int N = 17, M = 1 << N;
int dp[M][2][2];
bool a[M];
int n, m;
inline void update(int &a, int b, int c, int d) {
  if (b == -1 || c == -1) return;
  a = max(a, b + c + d);
}
void merge(int a[2][2], int b[2][2], int cc[2][2]) {
  int c[2][2];
  memset(c, -1, sizeof c);
  for (int i1 = 0; i1 < 2; ++i1)
    for (int i2 = 0; i2 < 2; ++i2)
      for (int j1 = 0; j1 < 2; ++j1)
        for (int j2 = 0; j2 < 2; ++j2) {
          for (int res = 0; res < 8; ++res) {
            int o[] = {(res >> 2) & 1, (res >> 1) & 1, res & 1};
            int k1 = -1, k2 = -1;
            int tmp, tmp2;
            int cost = 0;
            if (o[0]) {
              k1 = i1;
              tmp = j1;
            } else {
              k1 = j1;
              tmp = i1;
            }
            if (i1 || j1) ++cost;
            if (o[1]) {
              tmp2 = i2;
            } else {
              tmp2 = j2;
            }
            if (i2 || j2) ++cost;
            if (o[2])
              k2 = tmp;
            else
              k2 = tmp2;
            if (tmp || tmp2) ++cost;
            update(c[k1][k2], a[i1][i2], b[j1][j2], cost);
            if (c[k1][k2] == 7) {
              ;
            }
          }
        }
  memcpy(cc, c, sizeof(c));
}
int main(int argc, char const *argv[]) {
  memset(dp, -1, sizeof dp);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x;
    scanf("%d", &x);
    a[--x] = 1;
  }
  for (int i = 0; i < M; i += 2) {
    if (a[i] || a[i + 1])
      dp[i][a[i]][a[i + 1]] = dp[i][a[i + 1]][a[i]] = 1;
    else
      dp[i][0][0] = 0;
  }
  for (int k = 0; k < (1 << n); ++k)
    ;
  for (int i = 2; i <= n; ++i) {
    ;
    int step = 1 << i, seg = 1 << (i - 1);
    for (int j = 0; j < (1 << n); j += step) {
      ;
      merge(dp[j], dp[j + seg], dp[j]);
    }
    for (int k = 0; k < (1 << n); ++k)
      ;
  }
  int ans =
      max(dp[0][0][0], max(dp[0][0][1] + 1, max(dp[0][1][0], dp[0][1][1])));
  printf("%d\n", ans);
  return 0;
}
