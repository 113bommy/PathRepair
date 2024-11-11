#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T mod_v(T num) {
  if (num >= 0)
    return num % 1000000007;
  else
    return (num % 1000000007 + 1000000007) % 1000000007;
}
template <class T>
inline T gcd(T a, T b) {
  a = abs(a);
  b = abs(b);
  while (b) b ^= a ^= b ^= a %= b;
  return a;
}
template <class T>
T fast_pow(T n, T p) {
  if (p == 0) return 1;
  if (p % 2) {
    T g = mod_v(mod_v(n) * mod_v(fast_pow(n, p - 1)));
    return g;
  } else {
    T g = fast_pow(n, p / 2);
    g = mod_v(mod_v(g) * mod_v(g));
    return g;
  }
}
template <class T>
inline T modInverse(T n) {
  return fast_pow(n, 1000000007 - 2);
}
bool equalTo(double a, double b) {
  if (fabs(a - b) <= 1e-9)
    return true;
  else
    return false;
}
bool notEqual(double a, double b) {
  if (fabs(a - b) > 1e-9)
    return true;
  else
    return false;
}
bool lessThan(double a, double b) {
  if (a + 1e-9 < b)
    return true;
  else
    return false;
}
bool lessThanEqual(double a, double b) {
  if (a < b + 1e-9)
    return true;
  else
    return false;
}
bool greaterThan(double a, double b) {
  if (a > b + 1e-9)
    return true;
  else
    return false;
}
bool greaterThanEqual(double a, double b) {
  if (a + 1e-9 > b)
    return true;
  else
    return false;
}
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
int nextInt() {
  int n;
  scanf("%d", &n);
  return n;
}
long long nextLong() {
  long long n;
  scanf("%lld", &n);
  return n;
}
void print(int n) { printf("%d", n); }
void println(int n) { printf("%d\n", n); }
void println(long long n) { printf("%lld\n", n); }
template <class T>
inline int in(register T& num) {
  register char c = 0;
  num = 0;
  bool n = false;
  while (c < 33) c = getchar();
  while (c > 33) {
    if (c == '-')
      n = true;
    else
      num = num * 10 + c - '0';
    c = getchar();
  }
  num = n ? -num : num;
  return 1;
}
int ara[2 * 100006];
int lastUpdateDoneAt[2 * 100005];
int updateValue[2 * 100005];
int n, q;
int main() {
  in(n);
  for (int i = 1; i <= n; i++) in(ara[i]);
  in(q);
  int typ;
  for (int i = 1; i <= q; i++) {
    in(typ);
    if (typ == 1) {
      int p, val;
      in(p), in(val);
      ara[p] = val;
      lastUpdateDoneAt[p] = i;
    } else {
      int val;
      in(val);
      updateValue[i] = val;
    }
  }
  for (int i = q; i >= 1; i--) {
    updateValue[i] = max(updateValue[i], updateValue[i + 1]);
  }
  for (int i = 1; i <= n; i++) {
    ara[i] = max(ara[i], updateValue[lastUpdateDoneAt[i]]);
    printf("%d ", ara[i]);
  }
  return 0;
}
