#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 7;
const int M = 20;
const int inf = (int)1e9 + 7;
const long long base = (long long)1e18;
const double pi = acos(-1);
const double ep = 1e-18;
long long a[4][N][N];
int mx[4], my[4];
int n;
void update(int i, int u, int v, long long val) {
  while (u <= mx[i]) {
    for (int t = v; t <= my[i]; t += t & -t) {
      a[i][u][t] ^= val;
    }
    u += u & -u;
  }
}
long long get(int i, int u, int v) {
  long long ans = 0;
  while (u > 0) {
    for (int t = v; t > 0; t -= t & -t) ans ^= a[i][u][t];
    u -= u & -u;
  }
  return ans;
}
int x[4] = {0, 0, -1, -1};
int y[4] = {0, -1, 0, -1};
long long get(int u, int v) {
  long long ans = 0;
  for (int i = 0; i < 1; i++) {
    int p = u + x[i], q = v + y[i];
    if (p == 0 || q == 0) continue;
    int t = ((p & 1) << 1) + (q & 1);
    ans ^= get(t, (p + 1) / 2, (q + 1) / 2);
  }
  return ans;
}
void update(int __x0, int __y0, int __x1, int __y1, long long val) {
  int t = ((__x0 & 1) << 1) + (__y0 & 1);
  __x1++;
  __y1++;
  if ((__x1 - __x0) & 1) __x1++;
  if ((__y1 - __y0) & 1) __y1++;
  update(t, (__x0 + 1) / 2, (__y0 + 1) / 2, val);
  if (__y1 <= n) update(t, (__x0 + 1) / 2, (__y1 + 1) / 2, val);
  if (__x1 <= n) update(t, (__x1 + 1) / 2, (__y0 + 1) / 2, val);
  if (__x1 <= n && __y1 <= n) update(t, (__x1 + 1) / 2, (__y1 + 1) / 2, val);
}
void update2(int u, int v, int val) {
  int t = ((u & 1) << 1) + (v & 1);
  update(t, (u + 1) / 2, (v + 1) / 2, val);
}
void solve() {
  int q;
  cin >> n >> q;
  mx[3] = my[3] = (n + 1) / 2;
  mx[0] = my[0] = n / 2;
  mx[1] = mx[0];
  my[1] = my[3];
  mx[2] = my[1], my[2] = mx[1];
  int c, __x0, __y0, __x1, __y1;
  long long val;
  while (q-- > 0) {
    scanf("%d", &c);
    if (c == 2) {
      scanf("%d%d%d%d%I64d", &__x0, &__y0, &__x1, &__y1, &val);
      update(__x0, __y0, __x1, __y1, val);
      int tmp = (__x1 - __x0 + 1) * (__y1 - __y0 + 1) % 2;
      if ((__y1 - __y0 + 1) & 1) {
        if (__y1 < n) update2(__x0, __y1 + 1, val);
        if (__y1 + 1 < n) update2(__x0, __y1 + 2, val);
        int nxt = __x1 + 1;
        if ((nxt - __x0) & 1) nxt++;
        if (nxt <= n) {
          if (__y1 < n) update2(nxt, __y1 + 1, val);
          if (__y1 + 1 < n) update2(nxt, __y1 + 2, val);
        }
      }
      if ((__x1 - __x0 + 1) & 1) {
        if (__x1 < n) update2(__x1 + 1, __y0, val);
        if (__x1 + 1 < n) update2(__x1 + 2, __y0, val);
        int nxt = __y1;
        if ((nxt - __y0) & 1) nxt++;
        if (nxt <= n) {
          if (__x1 < n) update2(__x1 + 1, nxt, val);
          if (__x1 + 1 < n) update2(__x1 + 2, nxt, val);
        }
      }
      if (tmp) {
        for (int i = 0; i < 4; i++) {
          int u = __x1 + 1 - x[i], v = __y1 + 1 - y[i];
          if (u > n || v > n) continue;
          update2(u, v, val);
        }
      }
    } else {
      scanf("%d%d%d%d", &__x0, &__y0, &__x1, &__y1);
      long long ans = get(__x1, __y1) ^ get(__x1, __y0 - 1) ^
                      get(__x0 - 1, __y1) ^ get(__x0 - 1, __y0 - 1);
      printf("%I64d\n", ans);
    }
  }
}
int main() {
  solve();
  return 0;
}
