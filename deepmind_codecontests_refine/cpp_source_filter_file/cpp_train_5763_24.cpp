#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1024;
int n, m;
int a[MAXN][MAXN];
long long h[MAXN], v[MAXN];
long long inf = 10000000000000000LL;
void read() {
  int i, j;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= m; ++j) {
      scanf("%d", &a[i][j]);
      h[i] += (long long)a[i][j];
      v[j] += (long long)a[i][j];
    }
  }
}
void solve() {
  int i, j, ans_x, ans_y;
  long long mx = inf, my = inf;
  for (i = 0; i <= n; ++i) {
    long long sum = 0LL;
    for (j = 1; j <= n; ++j) {
      sum += h[j] * ((4 * i - 2 * (j + j - 1)) * (4 * i - 2 * (j + j - 1)));
    }
    if (sum < mx) {
      mx = sum;
      ans_x = i;
    }
  }
  for (i = 0; i <= m; ++i) {
    long long sum = 0LL;
    for (j = 1; j <= m; ++j) {
      sum += v[j] * ((4 * i - 2 * (j + j - 1)) * (4 * i - 2 * (j + j - 1)));
    }
    if (sum < my) {
      my = sum;
      ans_y = i;
    }
  }
  printf("%I64d\n", mx + my);
  printf("%d %d\n", ans_x, ans_y);
}
int main() {
  read();
  solve();
  return 0;
}
