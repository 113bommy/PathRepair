#include <bits/stdc++.h>
using namespace std;
template <typename Tp>
inline void read(Tp &x) {
  static char c;
  static bool neg;
  x = 0, c = getchar(), neg = false;
  for (; !isdigit(c); c = getchar()) {
    if (c == '-') {
      neg = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (neg) {
    x = -x;
  }
}
const int MOD = 1e9 + 7;
const int N = 1000 + 5;
const long long UPDATE = 1e16;
inline void fix(int &x) {
  if (x >= MOD) {
    x -= MOD;
  } else if (x < 0) {
    x += MOD;
  }
}
inline int inc(int &x, const int &y) {
  x += y;
  fix(x);
  return x;
}
inline int dec(int &x, const int &y) {
  x -= y;
  fix(x);
  return x;
}
inline int sum(const int &x, const int &y) {
  int res = x + y;
  fix(res);
  return res;
}
inline int sum(const initializer_list<int> &l) {
  int res = 0;
  for (const auto &x : l) {
    res += x;
    fix(res);
  }
  return res;
}
inline int mul(const int &x, const int &y) {
  int res = (long long)x * y % MOD;
  if (res < 0) {
    res += MOD;
  }
  return res;
}
long long p, alpha;
char str[N];
namespace A {
const int M = 3400 + 5;
int a[M], inp[N], top = 0;
inline void init(const char *str) {
  int len = strlen(str);
  for (int i = 0; i < len; ++i) {
    inp[i] = (int)(str[i] - '0');
  }
  int start = 0;
  while (start < len) {
    long long now = 0;
    for (int i = start; i < len; ++i) {
      now = now * 10 + inp[i];
      if (i == start && now < p) {
        ++start;
      } else {
        inp[i] = now / p;
        now %= p;
      }
    }
    a[top++] = now;
  }
}
int f[M][M][2][2];
inline void dp() {
  f[top][0][0][1] = 1;
  for (int i = top - 1, c0, c1, c2, c3, c4, c5; i >= 0; --i) {
    c0 = (long long)p * (p + 1) / 2 % MOD;
    c1 = (long long)a[i] * (a[i] + 1) / 2 % MOD;
    c2 = (long long)p * (p - 1) / 2 % MOD;
    c3 = sum(mul(a[i], p), -(long long)a[i] * (a[i] + 1) / 2 % MOD);
    c4 = (long long)a[i] * (a[i] - 1) % MOD;
    c5 = sum(mul(a[i], p), -(long long)a[i] * (a[i] - 1) / 2 % MOD);
    for (int j = 0, f0, f1, f2, f3; j <= top - i + 1; ++j) {
      f0 = f[i + 1][j][0][0];
      f1 = f[i + 1][j][0][1];
      f2 = f[i + 1][j][1][0];
      f3 = f[i + 1][j][1][1];
      if (f0 || f1 || f2 || f3) {
        f[i][j][0][0] =
            sum({mul(c0, f0), mul(c1, f1), mul(c2, f2), mul(c3, f3)});
        f[i][j][0][1] = sum(mul(a[i] + 1, f1), mul(p - a[i] - 1, f3));
        f[i][j + 1][1][0] =
            sum({mul(c2, f0), mul(c4, f1), mul(c0, f2), mul(c5, f3)});
        f[i][j + 1][1][1] = sum(mul(a[i], f1), mul(p - a[i], f3));
      }
    }
  }
}
inline void out() {
  int res = 0;
  for (int i = alpha; i <= top; ++i) {
    inc(res, sum(f[0][i][0][0], f[0][i][0][1]));
  }
  printf("%d\n", res);
}
}  // namespace A
int main() {
  read(p), read(alpha);
  scanf("%s", str);
  A::init(str);
  A::dp();
  A::out();
}
