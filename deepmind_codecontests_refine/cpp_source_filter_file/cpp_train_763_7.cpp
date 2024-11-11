#include <bits/stdc++.h>
using namespace std;
const long long SIZE = 1e6 + 50;
inline long long read() {
  long long x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x;
}
long long n, m, ans, sum;
long long deletion[SIZE];
signed main() {
  n = read();
  m = read();
  for (long long i = 1; i <= m; ++i) {
    long long x = read(), y = read();
    deletion[x]++;
    deletion[y]++;
  }
  ans = n * (n - 1) / 2 * (n - 2) / 3;
  for (long long i = 1; i <= n; ++i) {
    sum += deletion[i] * (n - 1 - deletion[i]);
  }
  sum >>= 1;
  ans -= sum;
  printf("%d\n", ans);
  return 0;
}
