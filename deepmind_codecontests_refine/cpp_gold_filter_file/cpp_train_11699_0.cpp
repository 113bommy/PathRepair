#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int n, m, t;
double sum[maxn];
inline int read() {
  int ret = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (isdigit(ch)) {
    ret = ret * 10 + ch - '0';
    ch = getchar();
  }
  return ret * f;
}
signed main() {
  n = read();
  m = read();
  t = read();
  if (m > n + t) {
    puts("0.0000");
    return 0;
  }
  if (t >= m) {
    puts("1.0000");
    return 0;
  }
  for (int k = 1; k <= n + m + t; k++) sum[k] = sum[k - 1] + log(k);
  printf("%.4lf", 1.0 - exp(sum[m] + sum[n] - sum[m - t - 1] - sum[n + t + 1]));
  return 0;
}
