#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:500000000")
using namespace std;
int nextInt() {
  int n;
  scanf("%d", &n);
  return n;
}
long long nextLong() {
  long long n;
  scanf("%lld", &n);
  return n;
}
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int INF = (int)2e9;
char s[1009], t[1009];
int dp[1009][1009][12][2];
int n, m;
int f(int i, int j, int k, int haveTo) {
  if (i == n || j == m || (k == 0 && haveTo == 0)) {
    return 0;
  }
  if (dp[i][j][k][haveTo] != -1) {
    return dp[i][j][k][haveTo];
  }
  if (haveTo == 1) {
    dp[i][j][k][haveTo] = f(i, j, k, 0);
    if (s[i] == t[j]) {
      dp[i][j][k][haveTo] = max(f(i + 1, j + 1, k, 1) + 1, dp[i][j][k][haveTo]);
    }
  } else {
    dp[i][j][k][haveTo] = max(f(i + 1, j, k, 0), f(i, j + 1, k, 0));
    if (s[i] == t[j] && k > 0) {
      dp[i][j][k][haveTo] =
          max(f(i + 1, j + 1, k - 1, 1) + 1, dp[i][j][k][haveTo]);
    }
  }
  return dp[i][j][k][haveTo];
}
int main() {
  int k;
  scanf("%d %d %d", &n, &m, &k);
  scanf("%s", s);
  scanf("%s", t);
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      for (int cnt = 0; cnt <= k; ++cnt) {
        dp[i][j][cnt][0] = dp[i][j][cnt][1] = -1;
      }
    }
  }
  printf("%d\n", f(0, 0, k, 0));
  return 0;
}
