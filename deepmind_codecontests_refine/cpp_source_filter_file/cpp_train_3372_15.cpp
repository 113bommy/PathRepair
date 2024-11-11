#include <bits/stdc++.h>
using namespace std;
const int intmax = 0x3f3f3f3f;
const long long lldmax = 0x3f3f3f3f3f3f3f3fll;
double eps = 1e-8;
template <class T>
inline void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline T lowbit(T n) {
  return (n ^ (n - 1)) & n;
}
template <class T>
inline int countbit(T n) {
  return (n == 0) ? 0 : (1 + countbit(n & (n - 1)));
}
template <class T>
inline T checkmod(T n, T m) {
  return (n % m + m) % m;
}
template <class T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <class T>
inline T euclid(T a, T b, T &x, T &y) {
  if (a < 0) {
    T d = euclid(-a, b, x, y);
    x = -x;
    return d;
  }
  if (b < 0) {
    T d = euclid(a, -b, x, y);
    y = -y;
    return d;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    T d = euclid(b, a % b, x, y);
    T t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
  }
}
template <class T>
inline int dblcmp(T a, const T b) {
  a -= b;
  return a > eps ? 1 : (a < -eps ? -1 : 0);
}
template <class T>
inline int sgn(T a) {
  return a > eps ? 1 : (a < -eps ? -1 : 0);
}
bool isPrime(int n) {
  for (int i = 2; i < n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}
template <class T>
T modpow(T a, T n, T p) {
  T b = a % p, ans = 1;
  while (n) {
    if (n & 1) ans = (1LL * ans * b) % p;
    b = (1LL * b * b) % p;
    n >>= 1;
  }
  return ans;
}
int a[1100000];
int main() {
  int n, x;
  int top = 0;
  cin >> n >> x;
  for (int i = 1; i < n; ++i) {
    if (n % i == 0) a[top++] = i;
  }
  if (!isPrime(n + 1)) {
    puts("-1");
  } else {
    int ans = -1;
    for (int i = x - 1; i >= 1; --i) {
      bool flag = true;
      if (modpow(i, n, n + 1) != 1) flag = false;
      for (int j = 0; j < top && flag; ++j) {
        if (modpow(i, a[j], n + 1) == 1) flag = false;
      }
      if (flag) {
        ans = i;
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
