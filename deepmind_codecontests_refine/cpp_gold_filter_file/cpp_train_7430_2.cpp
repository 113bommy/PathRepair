#include <bits/stdc++.h>
using namespace std;
int n, m;
long long sol;
int dp[155][155][155][2][2], sp[2][2][155][155];
inline int fmod(long long x) {
  x %= 1000000007;
  if (x < 0) x += 1000000007;
  return x;
}
int sum(int lmax, int rmax, int il, int ir, int jl, int jr) {
  if (il > ir || jl > jr) return 0;
  return fmod(1LL * sp[lmax][rmax][ir][jr] + sp[lmax][rmax][il - 1][jl - 1] -
              sp[lmax][rmax][il - 1][jr] - sp[lmax][rmax][ir][jl - 1]);
}
int main() {
  scanf("%d %d", &n, &m);
  for (int row = 1; row <= n; ++row) {
    for (int l = 1; l <= m; ++l) {
      for (int r = l; r <= m; ++r) {
        if (row == 1) {
          dp[row][l][r][1][1] = 1;
          continue;
        }
        long long x = 0;
        for (int i = 0; i < 2; ++i)
          for (int j = 0; j < 2; ++j) x += sum(i, j, 1, l - 1, r + 1, m);
        for (int i = 0; i < 2; ++i)
          x += sum(i, 0, 1, l - 1, r, r) + sum(0, i, l, l, r + 1, m);
        x += sum(0, 0, l, l, r, r);
        dp[row][l][r][0][0] = fmod(x);
        x = 0;
        for (int i = 0; i < 2; ++i) x += sum(i, 1, 1, l - 1, l, r);
        x += sum(0, 1, l, l, l, r);
        dp[row][l][r][0][1] = fmod(x);
        x = 0;
        for (int i = 0; i < 2; ++i) x += sum(1, i, l, r, r + 1, m);
        x += sum(1, 0, l, r, r, r);
        dp[row][l][r][1][0] = fmod(x);
        dp[row][l][r][1][1] = sum(1, 1, l, r, l, r);
      }
    }
    for (int lmax = 0; lmax < 2; ++lmax)
      for (int rmax = 0; rmax < 2; ++rmax) {
        for (int i = 1; i <= m; ++i)
          for (int j = 1; j <= m; ++j)
            sp[lmax][rmax][i][j] =
                fmod(1LL * sp[lmax][rmax][i - 1][j] + sp[lmax][rmax][i][j - 1] -
                     sp[lmax][rmax][i - 1][j - 1] + dp[row][i][j][lmax][rmax]);
        sol += 1LL * sp[lmax][rmax][m][m] * (n - row + 1);
      }
    sol = fmod(sol);
  }
  printf("%I64d\n", sol);
  return 0;
}
