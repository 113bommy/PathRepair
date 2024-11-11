#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f = ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
const int N = 55, M = 20005, INF = 2e9;
int n, m, k;
int a[N][M], s[N][M], dp[N][M];
int f(int i, int l, int r) { return s[i][r] - s[i][l - 1]; }
void ckmax(int &x, int y) {
  if (x < y) x = y;
}
int p[M], v[M];
int main() {
  n = read(), m = read(), k = read();
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++)
      a[i][j] = read(), s[i][j] = s[i][j - 1] + a[i][j];
  for (int i = (1); i <= (m - k + 1); i++) dp[1][i] = f(1, i, i + k - 1);
  for (int i = (2); i <= (n); i++) {
    for (int j = (1); j <= (m - k + 1); j++) dp[i][j] = -INF;
    {
      int v = -INF;
      for (int j = (k + 1); j <= (m - k + 1); j++) {
        v = max(v, dp[i - 1][j - k] + f(i, j - k, j - 1));
        ckmax(dp[i][j], v + f(i, j, j + k - 1));
      }
      v = -INF;
      for (int j = (m - k + 1); j >= (k + 1); j--) {
        v = max(v, dp[i - 1][j] + f(i, j, j + k - 1));
        ckmax(dp[i][j - k], v + f(i, j - k, j - 1));
      }
    }
    int l = 1, r = 0;
    for (int j = (1); j <= (m - k + 1); j++) {
      while (l <= r && p[l] <= j - k) l++;
      int tmp = dp[i - 1][j] - s[i][j - 1];
      while (l <= r && v[r] <= tmp) r--;
      ++r, p[r] = j, v[r] = tmp;
      ckmax(dp[i][j], v[l] + s[i][j + k - 1]);
    }
    l = 1, r = 0;
    for (int j = (m - k + 1); j >= (1); j--) {
      while (l <= r && p[l] >= j + k) l++;
      int tmp = dp[i - 1][j] + s[i][j + k - 1];
      while (l <= r && v[r] <= tmp) r--;
      ++r, p[r] = j, v[r] = tmp;
      ckmax(dp[i][j], v[l] - s[i][j - 1]);
    }
  }
  int ans = 0;
  for (int i = (1); i <= (m - k + 1); i++) ckmax(ans, dp[n][i]);
  cout << ans << endl;
  return 0;
}
