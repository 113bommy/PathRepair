#include <bits/stdc++.h>
using namespace std;
long long n, ans[501][501];
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  cin >> n;
  if (n < 3) cout << "-1\n";
  long long t = n * n - 9, x = 4, y = 1, tx = 0, ty = 1;
  ans[1][1] = 1, ans[1][2] = 5, ans[1][3] = 8, ans[2][1] = 3, ans[2][2] = 6,
  ans[2][3] = 4, ans[3][1] = 2, ans[3][2] = 9, ans[3][3] = 7;
  for (long long i = 1; i <= 3; i++)
    for (long long j = 1; j <= 3; j++) ans[i][j] += t;
  for (long long i = 1; i <= t; i++) {
    ans[x][y] = i;
    if (y == 1 && ty == -1) {
      ++x, tx = 0, ty = 1;
      continue;
    }
    if (x == 1 && tx == -1) {
      ++y, tx = 1, ty = 0;
      continue;
    }
    if (x == y)
      if (tx == 0)
        tx = -1, ty = 0;
      else
        tx = 0, ty = -1;
    x += tx, y += ty;
  }
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= n; j++)
      cout << ans[i][j] << (j != n ? ' ' : '\n');
  return 0;
}
