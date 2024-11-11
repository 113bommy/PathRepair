#include <bits/stdc++.h>
using namespace std;
static inline void canhazfast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
template <typename T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
T extgcd(T a, T b, T &x, T &y) {
  T x0 = 1, y0 = 0, x1 = 0, y1 = 1;
  while (b) {
    T q = a / b;
    a %= b;
    swap(a, b);
    x0 -= q * x1;
    swap(x0, x1);
    y0 -= q * y1;
    swap(y0, y1);
  }
  x = x0;
  y = y0;
  return a;
}
static inline int ctz(unsigned x) { return __builtin_ctz(x); }
static inline int ctzll(unsigned long long x) { return __builtin_ctzll(x); }
static inline int clz(unsigned x) { return __builtin_clz(x); }
static inline int clzll(unsigned long long x) { return __builtin_clzll(x); }
int main() {
  int n, v;
  char op;
  int a = 1023, b = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf(" %c %d", &op, &v);
    if (op == '&') {
      a &= v;
      b &= v;
    } else if (op == '|') {
      a |= v;
      b |= v;
    } else {
      a ^= v;
      b ^= v;
    }
  }
  puts("3");
  printf("& %d\n", a | b);
  printf("| %d\n", a & b);
  printf("^ %d\n", b & ~a);
  return 0;
}
