#include <bits/stdc++.h>
using namespace std;
const long long maxn = 300010;
long long n, k, m, x, y, tem, ans;
inline long long read() {
  long long x = 0, w = 1;
  char ch = '0';
  while (ch < '0' || ch > '9') {
    w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * w;
}
signed main() {
  m = read();
  while (m--) {
    x = read();
    y = read();
    k = read();
    n = y * k + k;
    ans = k;
    if (x >= n)
      printf("%lld\n", ans + 1);
    else {
      tem = n - x;
      if (tem % (x - 1) == 0)
        ans += tem / (x - 1);
      else
        ans += tem / (x - 1) + 1;
      printf("%lld\n", ans + 1);
    }
  }
  return 0;
}
