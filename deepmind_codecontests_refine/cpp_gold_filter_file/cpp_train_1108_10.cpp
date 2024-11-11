#include <bits/stdc++.h>
using namespace std;
int n, R;
long long A[2000010], k, Ans, l = 1e18, r = 1e20, cf[2000010], sum[2000010];
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
bool check(long long m) {
  long long tmp = k, x = 0;
  memset(cf, 0, sizeof(cf));
  for (int i = 1; i <= n; ++i) {
    x += cf[i];
    if (sum[min(i + R, n)] - sum[max(i - R - 1, 0)] + x < m) {
      long long d = m - (sum[min(i + R, n)] - sum[max(i - R - 1, 0)] + x);
      if (d > tmp) return 0;
      tmp -= d;
      x += d;
      cf[i + 2 * R + 1] -= d;
    }
  }
  return 1;
}
int main() {
  scanf("%d%d%I64d\n", &n, &R, &k);
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i - 1] + (A[i] = read());
    l = min(l, A[i]);
  }
  while (l < r) {
    long long m = (l + r) >> 1ll;
    if (check(m))
      Ans = m, l = m + 1;
    else
      r = m;
  }
  printf("%I64d\n", Ans);
  return 0;
}
