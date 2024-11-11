#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - 48;
    ch = getchar();
  }
  return x * f;
}
template <typename T>
inline void Max(T &a, T b) {
  if (a < b) a = b;
}
template <typename T>
inline void Min(T &a, T b) {
  if (a > b) a = b;
}
const int N = 10004;
int n, mx, lst;
long long f[N], ans[N];
int v[] = {1, 5, 10, 50};
long long s1(long long n) { return n * (n + 1) / 2; }
int main() {
  f[0] = 1;
  for (int n = 1; n <= 100; ++n) {
    mx += 100;
    for (int tv = mx; ~tv; --tv) {
      f[tv] = 0;
      for (int i = 0; i <= 3; ++i)
        if (tv >= v[i]) f[tv] |= f[tv - v[i]];
    }
    for (int i = 1; i <= 10000; ++i)
      if (f[i]) ++ans[n];
  }
  n = gi();
  if (n <= 11)
    printf("%lld\n", ans[n]);
  else
    printf("%lld\n", ans[11] + 49 * (n - 11));
  return 0;
}
