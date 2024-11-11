#include <bits/stdc++.h>
using namespace std;
char getc() {
  char c = getchar();
  while ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z') && (c < '0' || c > '9'))
    c = getchar();
  return c;
}
int gcd(int n, int m) { return m == 0 ? n : gcd(m, n % m); }
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return x * f;
}
int n, m, a[20010], f[20010][110], suf[20010], pre[20010], tail;
struct line {
  int k, b;
  int f(int x) { return k * x + b; }
} q[20010];
long double cross(line x, line y) {
  return (long double)(y.b - x.b) / (x.k - y.k);
}
void ins(int k, int b) {
  line t = (line){k, b};
  while (tail && q[tail].k == k) t.b = min(t.b, q[tail--].b);
  while (tail > 1 && cross(t, q[tail - 1]) < cross(q[tail], q[tail - 1]))
    tail--;
  q[++tail] = t;
}
int query(int x) {
  if (!tail) return 1200000010;
  int l = 1, r = tail - 1, p = tail;
  while (l <= r) {
    int mid = l + r >> 1;
    if (cross(q[mid], q[mid + 1]) >= x)
      p = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  return q[p].f(x);
}
void solve(int l, int r) {
  if (l == r) return;
  int mid = l + r >> 1;
  solve(l, mid);
  for (int k = 1; k <= m; k++) {
    suf[mid + 1] = 0;
    for (int i = mid; i >= l; i--) suf[i] = max(suf[i + 1], a[i]);
    pre[mid] = 0;
    for (int i = mid + 1; i <= r; i++) pre[i] = max(pre[i - 1], a[i]);
    int p = l;
    tail = 0;
    for (int i = r; i > mid; i--) {
      while (suf[p + 1] >= pre[i]) {
        if (f[p][k - 1] != f[0][1])
          ins(suf[p + 1], f[p][k - 1] - p * suf[p + 1]);
        p++;
      }
      f[i][k] = min(f[i][k], query(i));
    }
    int mx = 0;
    p = mid;
    tail = 0;
    if (f[p][k - 1] != f[0][1]) ins(p, f[p][k - 1]);
    for (int i = mid + 1; i <= r; i++) {
      mx = max(mx, a[i]);
      while (mx >= a[p] && p > l) {
        p--;
        if (f[p][k - 1] != f[0][1]) ins(p, f[p][k - 1]);
      }
      f[i][k] = min(f[i][k], query(-mx) + i * mx);
    }
  }
  solve(mid + 1, r);
}
signed main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  memset(f, 42, sizeof(f));
  f[0][0] = 0;
  solve(0, n);
  cout << f[n][m];
  return 0;
}
