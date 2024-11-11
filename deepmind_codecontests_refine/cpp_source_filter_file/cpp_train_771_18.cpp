#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void CLR(T &g) {
  T t;
  swap(t, g);
}
template <class T>
inline void CLR(T &g, long long a) {
  memset(g, a, sizeof g);
}
template <class T>
inline bool inr(T a, T b, T c) {
  return (a >= b && a <= c);
}
template <class T>
inline bool odd(T a) {
  return a & 1;
}
template <class T>
inline bool empty(T a, T b) {
  return !(a & (1 << (b - 1)));
}
template <class T>
inline void bin(T &a, T b) {
  a |= 1 << (b - 1);
}
inline long long read() {
  char ch = getchar();
  long long tmp = 0;
  for (; ch > '9' || ch < '0'; ch = getchar())
    ;
  for (; '0' <= ch && ch <= '9'; ch = getchar())
    tmp = tmp * 10 + (long long)ch - 48;
  return tmp;
}
long long N, M, K, Q;
long long a[200005];
long long f[200005], g[200005], h[200005];
int main() {
  long long T, o = 0;
  cin >> N;
  for (long long(i) = 1; (i) <= (N); (i)++) cin >> a[i];
  f[1] = 1;
  g[1] = -0x3f3f3f3f;
  if (a[1] > 0)
    h[1] = 1;
  else
    h[1] = -1;
  for (long long(i) = 2; (i) <= (N); (i)++) {
    if (a[i] == -1 && g[i - 1] != -0x3f3f3f3f &&
        (a[f[i - 1]] + (i - f[i - 1]) * g[i - 1] <= 0)) {
      f[i] = i;
      g[i] = -0x3f3f3f3f;
      h[i] = -1;
      continue;
    }
    if (a[i] == -1) {
      f[i] = f[i - 1];
      g[i] = g[i - 1];
      h[i] = h[i - 1];
    }
    if (a[i] != -1 && g[i - 1] != -0x3f3f3f3f) {
      if (a[h[i - 1]] + (i - h[i - 1]) * g[i - 1] != a[i]) {
        f[i] = i;
        g[i] = -0x3f3f3f3f;
        h[i] = i;
        continue;
      } else if (a[i] - (i - f[i - 1]) * (g[i - 1]) <= 0) {
        f[i] = i;
        g[i] = -0x3f3f3f3f;
        h[i] = i;
      } else {
        f[i] = f[i - 1];
        g[i] = g[i - 1];
        h[i] = i;
        continue;
      }
    }
    if (a[i] != -1 && g[i - 1] == -0x3f3f3f3f) {
      if (h[i - 1] == -1) {
        f[i] = f[i - 1];
        g[i] = -0x3f3f3f3f;
        h[i] = i;
        continue;
      } else {
        long long t = a[i] - a[h[i - 1]];
        if (t % (i - h[i - 1]) == 0 &&
            a[i] - t / (i - h[i - 1]) * (i - f[i - 1]) > 0) {
          f[i] = f[i - 1];
          g[i] = t / (i - h[i - 1]);
          h[i] = i;
          continue;
        } else {
          f[i] = i;
          g[i] = -0x3f3f3f3f;
          h[i] = i;
          continue;
        }
      }
    }
  }
  int ans = 0;
  for (long long(i) = 1; (i) <= (N); (i)++)
    if (f[i] == i) ans++;
  printf("%d\n", ans);
  return 0;
}
