#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9';) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  for (; ch >= '0' && ch <= '9';) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long k, l, r, p;
inline long long power(long long a, long long b, long long p) {
  long long nowans = 1;
  for (; b; b >>= 1, a = a * a % p)
    if (b & 1) nowans = nowans * a % p;
  return nowans;
}
int main() {
  int T;
  for (scanf("%d", &T); T--;) {
    scanf("%I64d%I64d%I64d%I64d", &k, &l, &r, &p);
    if (p == 2)
      printf("%I64d\n", 1ll - (k & 1));
    else {
      long long x, y, ans;
      if (k % p == 0)
        x = y = p - 1;
      else
        x = power(k, power(2, r + 1, p - 1), p - 1) - 1,
        y = power(k, power(2, l, p - 1), p) - 1;
      if (!y)
        ans = power(2, r - l + 1, p);
      else
        ans = x * power(y, p - 2, p) % p;
      printf(
          "%I64d\n",
          ans *
              (k & 1 ? power(2, (r - l) % (p - 1) * (p - 2) % (p - 1), p) : 1) %
              p);
    }
  }
}
