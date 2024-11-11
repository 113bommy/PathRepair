#include <bits/stdc++.h>
using namespace std;
const long long qhqh = 998244353;
const int maxn = 1e6 + 10;
inline int read() {
  char c = getchar();
  long long x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
int w, h;
long long qpow(long long x, int p) {
  long long ret = 1;
  while (p) {
    if (p & 1) ret = ret * x % qhqh;
    x = x * x % qhqh;
    p >>= 1;
  }
  return ret % qhqh;
}
int main() {
  scanf("%d %d", &w, &h);
  long long ans = qpow(2, w * h);
  printf("%lld\n", ans);
  return 0;
}
