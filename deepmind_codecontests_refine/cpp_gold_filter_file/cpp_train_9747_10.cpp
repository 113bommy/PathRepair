#include <bits/stdc++.h>
using namespace std;
const double ang = 0.12321312321312;
struct ww {
  double x, y;
  inline bool operator==(const ww &A) {
    return abs(x - A.x) < (1e-6) && abs(y - A.y) < (1e-6);
  }
  inline void read() {
    int a, b;
    scanf("%d%d", &a, &b);
    x = cos(ang) * a - sin(ang) * b;
    y = sin(ang) * a + cos(ang) * b;
  }
  inline ww operator-(const ww &A) { return (ww){x - A.x, y - A.y}; }
  inline ww operator+(const ww &A) { return (ww){x + A.x, y + A.y}; }
  inline double operator*(const ww &A) { return x * A.y - y * A.x; }
} a[200010], b[200010], c[200010], O;
int i, j, k, n, m, K;
inline void get(ww a[200010], int n) {
  int i, k = 1;
  for (i = 1; i <= n; i++) c[i] = a[i];
  for (i = 2; i <= n; i++)
    if (a[i].x < a[k].x || a[i].x == a[k].x && a[i].y < a[k].y) k = i;
  int t = 0;
  for (i = k; i <= n; i++) a[++t] = c[i];
  for (i = 1; i <= k - 1; i++) a[++t] = c[i];
  a[n + 1] = a[1];
  a[n + 2] = a[2];
}
inline void merge(ww a[200010], ww b[200010]) {
  int i, j, t = 0;
  get(a, n);
  get(b, m);
  j = 1;
  c[t = 1] = a[1] + b[1];
  for (i = 1; i <= n + 1; i++) {
    ww A = a[i + 1] - a[i];
    for (;;) {
      if (t > 1 && c[1] == c[t]) break;
      ww B = b[j + 1] - b[j];
      double C = A * B;
      if (A * B > (1e-6)) break;
      c[++t] = a[i] + b[j + 1];
      j++;
    }
    if (t > 1 && c[1] == c[t]) break;
    c[++t] = a[i + 1] + b[j];
  }
  for (i = 1; i <= t; i++) a[i] = c[i];
  n = t - 1;
}
inline void pre() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) a[i].read();
  scanf("%d", &m);
  for (i = 1; i <= m; i++) b[i].read();
  merge(a, b);
  scanf("%d", &m);
  for (i = 1; i <= m; i++) b[i].read();
  merge(a, b);
}
inline bool pan() {
  if (O == a[1] || O == a[K]) return 1;
  if (O.x < a[1].x || O.x > a[K].x) return 0;
  int l = 1, r = K, mid;
  for (; l <= r;) {
    mid = (l + r) / 2;
    if (a[mid].x < O.x)
      l = mid + 1;
    else
      r = mid - 1;
  }
  int id = l - 1;
  double y = a[id].y + (a[id + 1].y - a[id].y) * (O.x - a[id].x) /
                           (a[id + 1].x - a[id].x);
  if (O.y + (1e-6) < y) return 0;
  l = K, r = n + 1;
  for (; l <= r;) {
    mid = (l + r) / 2;
    if (a[mid].x > O.x)
      l = mid + 1;
    else
      r = mid - 1;
  }
  id = l - 1;
  y = a[id].y +
      (a[id + 1].y - a[id].y) * (O.x - a[id].x) / (a[id + 1].x - a[id].x);
  if (O.y - (1e-6) > y) return 0;
  return 1;
}
int main() {
  pre();
  for (i = 1; i <= n; i++)
    if (a[i].x > a[i + 1].x) break;
  K = i;
  scanf("%d", &m);
  for (i = 1; i <= m; i++) {
    O.read();
    O.x *= 3, O.y *= 3;
    printf("%s\n", pan() ? "YES" : "NO");
  }
  return 0;
}
