#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
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
const int N = 100000 + 5;
int n, w, q;
int a[N], b[N];
int mn[N], mx[N], ans[N];
inline void checkMax(int &x, const int &y) {
  if (x < y) {
    x = y;
  }
}
inline void checkMin(int &x, const int &y) {
  if (x > y) {
    x = y;
  }
}
int main() {
  read(n), read(w), read(q);
  for (int i = 0; i < n; ++i) {
    read(a[i]);
  }
  for (int i = 0, x; i < q; ++i) {
    read(x);
    b[i] = w - x;
  }
  fill(mn, mn + n, a[0]);
  fill(mx, mx + n, a[0]);
  for (int j = 1; j < n; ++j) {
    for (int i = 0; i < q; ++i) {
      checkMax(mx[i], a[j]);
      checkMin(mn[i], a[j]);
      if (mx[i] - mn[i] > b[i]) {
        ++ans[i];
        mn[i] = mx[i] = a[j];
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
