#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = (int)1e9 + 7;
const int N = (int)45;
long long n, t;
long long C[N][N];
long long dfs(int row, int col, long long n) {
  if (!n) return 0;
  if (row < 1 || col < 0) return 0;
  if (n < (1ll << row)) {
    return dfs(row - 1, col, n);
  } else {
    return C[row][col] + dfs(row - 1, col - 1, n - (1ll << row));
  }
}
void Init() {
  for (int i = (0); i < (N); ++i) C[i][0] = 1;
  for (int i = (1); i < (N); ++i)
    for (int j = (1); j < (N); ++j) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
}
int Solve() {
  if (__builtin_popcountll(t) != 1) return puts("0");
  if (n == 1 && t == 1) return puts("1");
  int ii = 0, jj = __builtin_ctzll(t);
  for (long long tmp = 2; n >= tmp; n -= tmp, tmp <<= 1) ++ii;
  long long ans = C[ii + 1][jj + 1];
  if (n) ans += dfs(ii, jj, n);
  return printf("%I64d\n", ans - (t == 1));
}
int main() {
  while (~scanf("%I64d%I64d", &n, &t)) {
    Init();
    Solve();
  }
  return 0;
}
