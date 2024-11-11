#include <bits/stdc++.h>
using namespace std;
const int N = 110000;
int i, j, k, l, m, n, o, p, mid, f[20][N], b[N], is[N], a[N], L[N], R[N], lg[N];
struct arr {
  int x, y;
  arr() {}
  arr(int X, int Y) {
    x = X;
    y = Y;
  }
  inline bool operator<(const arr &t) const {
    return (x < t.x) || ((x == t.x) && (y < t.y));
  }
};
map<arr, int> F;
inline int read() {
  int o = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while ((c >= '0') && (c <= '9')) {
    o = (o << 1) + (o << 3) + c - '0';
    c = getchar();
  }
  return o;
}
inline void Init() {
  n = read();
  m = read();
  for (i = 1; i <= n; i++) a[i] = read();
  for (i = 1; i <= n - 1; i++) {
    b[i] = a[i + 1] - a[i];
    if (b[i] < 0) b[i] = -b[i];
  }
  lg[1] = 0;
  for (i = 2; i <= n; i++) lg[i] = lg[i - 1] + ((1 << lg[i - 1] + 1) == i);
}
inline int get(int L, int R) {
  int len = R - L + 1, k;
  k = lg[len];
  return max(f[k][L], f[k][R - (1 << k) + 1]);
}
inline void Prepare() {
  for (i = 1; i <= n - 1; i++) f[0][i] = b[i];
  for (i = 1; (1 << i) < n; i++)
    for (int j = 1; j < n; j++) {
      o = j + (1 << i - 1);
      if (o >= n) o = n - 1;
      f[i][j] = max(f[i - 1][j], f[i - 1][o]);
    }
  for (i = 1; i <= n - 1; i++) {
    o = 1;
    p = i - 1;
    while (o <= p) {
      mid = o + p >> 1;
      if (get(mid, i - 1) < b[i])
        p = mid - 1;
      else
        o = mid + 1;
    }
    L[i] = o;
    o = i + 1;
    p = n - 1;
    while (o <= p) {
      mid = o + p >> 1;
      if (get(i + 1, mid) <= b[i])
        o = mid + 1;
      else
        p = mid - 1;
    }
    R[i] = p + 1;
  }
}
inline void Solve() {
  long long l, r;
  long long ans = 0, t1, t2;
  while (m--) {
    o = read();
    p = read();
    ans = 0;
    for (i = 1; i <= n - 1; i++)
      if ((o <= i) && (i + 1 <= p)) {
        l = max(L[i], o);
        r = min(R[i], p);
        ans += (long long)(i - l + 1) * (long long)(r - i) * (long long)(b[i]);
      }
    printf("%I64d\n", ans);
  }
}
int main() {
  Init();
  Prepare();
  Solve();
  return 0;
}
