#include <bits/stdc++.h>
using namespace std;
const int N = 120, N2 = 8010, mod = 1000000007;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int ksm(long long a, int b, int c = 1) {
  for (; b; b /= 2, a = a * a % mod)
    if (b & 1) c = c * a % mod;
  return c;
}
int A[N2][N2], id[N][N], ans[N2], n, cnt, a[4], sum;
int solve() {
  for (int i = 1; i <= cnt; ++i)
    for (int j = i + 1; j <= cnt && j <= i + 2 * n; ++j)
      if (A[j][i]) {
        int tmp = ksm(A[i][i], mod - 2, A[j][i]);
        for (int k = 0; k <= 2 * n; ++k)
          A[j][i + k] =
              (A[j][i + k] - (long long)tmp * A[i][i + k] % mod + mod) % mod;
        A[j][0] = (A[j][0] - (long long)tmp * A[i][0] % mod + mod) % mod;
      }
  for (int i = cnt; i; --i) {
    ans[i] = ksm(A[i][i], mod - 2, A[i][0]);
    for (int j = i - 1; j && j >= i - n * 2; --j)
      if (A[j][i])
        A[j][0] = (A[j][0] - (long long)ans[i] * A[j][i] % mod + mod) % mod;
  }
  return ans[id[n][n]];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> a[0] >> a[1] >> a[2] >> a[3];
  sum = a[0] + a[1] + a[2] + a[3];
  for (int i = 0; i < 4; ++i) a[i] = ksm(sum, mod - 2, mod - a[i]);
  for (int i = -n; i <= n; ++i)
    for (int j = -n; j <= n; ++j)
      if (i * i + j * j <= n * n) id[i + n][j + n] = ++cnt;
  for (int i = -n; i <= n; ++i)
    for (int j = -n; j <= n; ++j)
      if (id[i + n][j + n]) {
        for (int k = 0; k < 4; ++k) {
          int nx = i + dx[k], ny = j + dy[k];
          if (nx * nx + ny * ny <= n * n)
            A[id[i + n][j + n]][id[nx + n][ny + n]] = a[k];
        }
        A[id[i + n][j + n]][id[i + n][j + n]] = A[id[i + n][j + n]][0] = 1;
      }
  cout << solve() << '\n';
  return 0;
}
