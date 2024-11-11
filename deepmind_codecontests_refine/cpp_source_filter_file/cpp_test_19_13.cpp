#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
const int M = 2000 + 10;
const int INF = 0x3f3f3f3f;
int n;
int a[M];
int f[N][M];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= 2000; ++j) f[i][j] = INF;
  f[1][a[1]] = a[1];
  for (int i = 2; i <= n; ++i) {
    for (int l = 0; l <= 2000; ++l) {
      if (l <= a[i])
        f[i][0] = min(f[i][0], f[i - 1][l] + (a[i] - l));
      else
        f[i][l - a[i]] = min(f[i][l - a[i]], f[i - 1][l]);
      f[i][l + a[i]] = min(f[i][l + a[i]], max(f[i - 1][l], l + a[i]));
    }
  }
  int ans = INF;
  for (int j = 0; j <= 2000; ++j) ans = min(ans, f[n][j]);
  printf("%d\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
