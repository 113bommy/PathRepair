#include <bits/stdc++.h>
using namespace std;
double dp[55][5001];
long long n, r, a[55], b[55], p[55];
inline long long read() {
  long long sum = 0, x = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') x = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    sum = sum * 10 + ch - '0';
    ch = getchar();
  }
  return sum * x;
}
bool check(double mid) {
  double t1, t2;
  for (register long long i = n - 1; i >= 0; --i) {
    for (register long long j = r + 1; j < 5000; ++j) dp[i + 1][j] = mid;
    for (register long long j = 0; j <= r; ++j) {
      t1 = 0.01 * (dp[i + 1][j + a[i]] + a[i]) * p[i];
      t2 = 0.01 * (dp[i + 1][j + b[i]] + b[i]) * (100 - p[i]);
      dp[i][j] = min(mid, t1 + t2);
    }
  }
  return dp[0][0] < mid;
}
signed main() {
  n = read();
  r = read();
  for (register long long i = 0; i < n; ++i) {
    a[i] = read();
    b[i] = read();
    p[i] = read();
  }
  double l = 0.0, r = 1e10, mid;
  for (register long long i = 1; i < 101; ++i) {
    mid = 0.5 * (l + r);
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.12lf", l + 0.0000000002);
  return 0;
}
