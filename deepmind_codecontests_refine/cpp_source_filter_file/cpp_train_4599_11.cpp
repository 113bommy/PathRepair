#include <bits/stdc++.h>
using namespace std;
const int N = 50 + 5;
const int C = 2500 + 5;
const int MOD = 1000000007;
inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= b;
  return a;
}
inline int sub(int a, int b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}
inline int mul(int64_t a, int64_t b) { return static_cast<int>(a * b % MOD); }
int d[N], p[N], tot[3];
int dp0[N][C];
int dp12[N][N][C];
int way[N][N][N][4];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, t;
  cin >> n >> t;
  for (int i = 0; i < n; ++i) cin >> d[i] >> p[i];
  dp0[0][0] = 1;
  dp12[0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    tot[--p[i]]++;
    switch (p[i]) {
      case 0:
        for (int j = tot[0]; j >= 1; --j)
          for (int s = d[i]; s < C; ++s)
            dp0[j][s] = add(dp0[j][s], dp0[j - 1][s - d[i]]);
        break;
      case 1:
        for (int j = tot[1]; j >= 1; --j)
          for (int k = tot[2]; k >= 0; --k)
            for (int s = d[i]; s < C; ++s)
              dp12[j][k][s] = add(dp12[j][k][s], dp12[j - 1][k][s - d[i]]);
        break;
      case 2:
        for (int j = tot[1]; j >= 0; --j)
          for (int k = tot[2]; k >= 1; --k)
            for (int s = d[i]; s < C; ++s)
              dp12[j][k][s] = add(dp12[j][k][s], dp12[j][k - 1][s - d[i]]);
        break;
    }
  }
  way[0][0][0][3] = 1;
  for (int i = 0; i <= tot[0]; ++i) {
    for (int j = 0; j <= tot[1]; ++j) {
      for (int k = 0; k <= tot[2]; ++k) {
        if (i) {
          way[i][j][k][0] = add(way[i][j][k][0], mul(i, way[i - 1][j][k][1]));
          way[i][j][k][0] = add(way[i][j][k][0], mul(i, way[i - 1][j][k][2]));
          way[i][j][k][0] = add(way[i][j][k][0], mul(i, way[i - 1][j][k][3]));
        }
        if (j) {
          way[i][j][k][1] = add(way[i][j][k][1], mul(j, way[i][j - 1][k][0]));
          way[i][j][k][1] = add(way[i][j][k][1], mul(j, way[i][j - 1][k][2]));
          way[i][j][k][1] = add(way[i][j][k][1], mul(j, way[i][j - 1][k][3]));
        }
        if (k) {
          way[i][j][k][2] = add(way[i][j][k][2], mul(k, way[i][j][k - 1][0]));
          way[i][j][k][2] = add(way[i][j][k][2], mul(k, way[i][j][k - 1][1]));
          way[i][j][k][2] = add(way[i][j][k][2], mul(k, way[i][j][k - 1][3]));
        }
      }
    }
  }
  for (int i = 0; i <= tot[0]; ++i)
    for (int j = 0; j <= tot[1]; ++j)
      for (int k = 0; k <= tot[2]; ++k)
        for (int s = 0; s < 3; ++s)
          way[i][j][k][3] = add(way[i][j][k][3], way[i][j][k][s]);
  int ans = 0;
  for (int i = 0; i <= tot[0]; ++i)
    for (int j = 0; j <= tot[1]; ++j)
      for (int k = 0; k <= tot[2]; ++k)
        for (int s = 0; s <= t; ++s)
          ans =
              add(ans, mul(way[i][j][k][3], mul(dp0[i][s], dp12[j][k][t - s])));
  cout << ans << '\n';
  return 0;
}
