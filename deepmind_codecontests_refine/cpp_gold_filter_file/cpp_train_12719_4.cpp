#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 2e5 + 7;
long long a[MAXN];
int dis[233][233];
int val[233][233];
int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  for (int i = (1); i <= (n); ++i) {
    scanf("%lld", &a[i]);
    if (a[i] == 0) {
      i--;
      n--;
    }
  }
  if (n > 400)
    printf("3\n");
  else {
    for (int i = (1); i <= (n); ++i) {
      for (int j = (1); j <= (n); ++j) {
        dis[i][j] = 1 << 28;
        val[i][j] = 1 << 28;
      }
    }
    for (int i = (1); i <= (n); ++i) {
      for (int j = (1); j <= (n); ++j) {
        if (a[i] & a[j]) {
          dis[i][j] = 1;
          val[i][j] = 1;
        }
      }
    }
    int ans = 1 << 28;
    for (int k = 1; k <= n; ++k) {
      for (int i = 1; i < k; ++i) {
        for (int j = 1; j < i; ++j) {
          ans = min(ans, dis[i][j] + val[i][k] + val[k][j]);
        }
      }
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
      }
    }
    if (ans > 200)
      printf("-1\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
