#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x = x * f;
}
template <typename E>
E gcd(E a, E b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <typename E>
E ex_gcd(E a, E b, E &x, E &y) {
  if (b == 0) {
    x = 1;
    y = 0;
  } else {
    ex_gcd(b, a % b, y, x);
    y -= (a / b) * x;
  }
}
template <typename E>
E quick_pow(E a, E b, E c) {
  E ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % c;
    a = a * a % c;
    b >>= 1;
  }
  return ans;
}
template <typename E>
E inv1(E a, E b) {
  return quick_pow(a, b - 2, b);
}
template <typename E>
E inv2(E a, E b) {
  E x, y;
  ex_gcd(a, b, x, y);
  return (x % b + b) % b;
}
const double eps = 1.0e-5;
const int maxn = 200000 + 10;
const long long mod = 1e9 + 7;
int a, b, c, d;
int main() {
  scanf("%d:%d", &a, &b);
  scanf("%d:%d", &c, &d);
  int cnt = 0;
  int e = a, f = b;
  while (a != c || b != d) {
    b++;
    cnt++;
    if (b == 60) {
      a++;
      b = 0;
    }
  }
  int s = 0;
  while (s < cnt / 2) {
    s++;
    f++;
    if (f == 60) {
      e++;
      f = 0;
    }
  }
  if (e < 10)
    printf("0%d", e);
  else
    printf("%d", e);
  printf(":");
  if (f < 10)
    printf("0%d", f);
  else
    printf("%d\n", f);
}
