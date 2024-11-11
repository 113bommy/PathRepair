#include <bits/stdc++.h>
using namespace std;
const int mn = 2005;
int a[mn][mn], n, m, K;
char s[mn];
long long f[2][10], ans;
inline int num(int x1, int y1, int x2, int y2) {
  return a[x2][y2] - a[x1][y2] - a[x2][y1] + a[x1][y1];
}
void solve(int x1, int y1, int x2, int y2, bool flg) {
  if (x1 == x2 || y1 == y2) return;
  if (x1 + 1 == x2 || y1 + 1 == y2) {
    ans += (num(x1, y1, x2, y2) == K);
    return;
  }
  if (flg) {
    int mid = (x1 + x2) >> 1;
    solve(x1, y1, mid, y2, 0), solve(mid, y1, x2, y2, 0);
    for (int i = y1; i < y2; i++) {
      f[0][0] = f[1][0] = mid;
      for (int j = 1; j <= K + 1; j++) f[0][j] = x1, f[1][j] = x2;
      for (int j = i + 1; j <= y2; j++) {
        for (int k = 1; k <= K + 1; k++) {
          while (num(f[0][k], i, mid, j) >= k) ++f[0][k];
          while (num(mid, i, f[1][k], j) >= k) --f[1][k];
        }
        for (int k = 0; k <= K; k++)
          ans += (f[0][k] - f[0][k + 1]) * (f[1][K - k + 1] - f[1][K - k]);
      }
    }
  } else {
    int mid = (y1 + y2) >> 1;
    solve(x1, y1, x2, mid, 1), solve(x1, mid, x2, y2, 1);
    for (int i = x1; i < x2; i++) {
      f[0][0] = f[1][0] = mid;
      for (int j = 1; j <= K + 1; j++) f[0][j] = y1, f[1][j] = y2;
      for (int j = i + 1; j <= x2; j++) {
        for (int k = 1; k <= K + 1; k++) {
          while (num(i, f[0][k], j, mid) >= k) ++f[0][k];
          while (num(i, mid, j, f[1][k]) >= k) --f[1][k];
        }
        for (int k = 0; k <= K; k++)
          ans += (f[0][k] - f[0][k + 1]) * (f[1][K - k + 1] - f[1][K - k]);
      }
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &K);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    for (int j = 1; j <= m; j++)
      a[i][j] = s[j] - '0',
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
  }
  solve(0, 0, n, m, 0);
  printf("%I64d\n", ans);
}
