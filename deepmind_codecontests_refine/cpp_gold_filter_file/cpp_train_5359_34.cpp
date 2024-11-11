#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T rd() {
  T x = 0;
  long long f = 1;
  char c = getchar();
  while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
  return x * f;
}
template <class T>
inline void write(T x) {
  if (x < 0) {
    putchar('-'), write(-x);
    return;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + 48);
}
template <class T>
inline void write_(T x) {
  if (x < 0) {
    putchar('-'), write(-x);
    putchar(' ');
    return;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + 48);
  putchar(' ');
}
template <class T>
inline void writeln(T x) {
  if (x < 0) {
    putchar('-'), write(-x);
    putchar('\n');
    return;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + 48);
  putchar('\n');
}
template <class T>
inline T min(T a, T b, T c) {
  return min(min(a, b), c);
}
template <class T>
inline T max(T a, T b, T c) {
  return max(max(a, b), c);
}
template <class T>
inline T min(T a, T b, T c, T d) {
  return min(min(a, b), min(c, d));
}
template <class T>
inline T max(T a, T b, T c, T d) {
  return max(max(a, b), max(c, d));
}
template <class T>
inline T fpow(T a, T b, T c) {
  T ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * a % c;
    a = 1ll * a * a % c;
    b >>= 1;
  }
  return ans;
}
template <class T>
inline T fpow(T a, T b) {
  T ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * a;
    a = 1ll * a * a;
    b >>= 1;
  }
  return ans;
}
template <class T>
inline T gcd(T a, T b) {
  if (!b) return a;
  return gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
inline void Exgcd(T a, T b, T &x, T &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return;
  }
  Exgcd(b, a % b, x, y);
  T tp = x;
  x = y;
  y = tp - a / b * y;
}
template <class T>
inline bool isPrime(T x) {
  if (x == (T)1) return false;
  if (x == (T)2 || x == (T)3) return true;
  if (x % (T)6 != (T)1 && x % (T)6 != (T)5) return false;
  for (T i = (T)5; i * i <= x; i += (T)6)
    if (!(x % i) || !(x % (i + (T)2))) return false;
  return true;
}
int a[120], b[120];
int main() {
  int n, m;
  while (cin >> n >> m) {
    int p = rd<int>();
    for (int i = 0; i < p; i++) {
      int t = rd<int>();
      a[t] = 1;
    }
    int q = rd<int>();
    for (int i = 0; i < q; i++) {
      int t = rd<int>();
      b[t] = 1;
    }
    for (int i = 0; i < 100000; i++)
      if (a[i % n] || b[i % m]) a[i % n] = b[i % m] = 1;
    int flg1 = 0;
    int flg2 = 0;
    for (int i = 0; i < n; i++)
      if (!a[i]) flg1 = 1;
    for (int i = 0; i < m; i++)
      if (!b[i]) flg2 = 1;
    if (!flg1 && !flg2)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
