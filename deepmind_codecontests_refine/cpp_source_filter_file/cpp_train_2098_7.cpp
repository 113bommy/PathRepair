#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, mod = 998244353;
template <class o>
inline void qr(o &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + (c ^ 48);
    c = getchar();
  }
  x *= f;
}
template <class o>
void qw(o x) {
  if (x / 10) qw(x / 10);
  putchar(x % 10 + 48);
}
template <class o>
void pr1(o x) {
  if (x < 0) putchar('-'), x = -x;
  qw(x);
  putchar(' ');
}
template <class o>
void pr2(o x) {
  if (x < 0) putchar('-'), x = -x;
  qw(x);
  puts("");
}
inline int ksm(int a, int b = mod - 2) {
  int ans = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) ans = 1ll * ans * a % mod;
  return ans;
}
inline int add(int a, int b) { return a += b, a >= mod ? a - mod : a; }
inline int sub(int a, int b) { return a -= b, a < 0 ? a + mod : a; }
struct Vec {
  long long x, y;
  Vec(long long x = 0, long long y = 0) : x(x), y(y) {}
  bool operator<(const Vec &a) const { return x == a.x ? y > a.y : x < a.x; }
  inline Vec operator-(const Vec &a) const { return Vec(x - a.x, y - a.y); }
} sta[N], a[N];
int top;
inline long long Cross(const Vec &a, const Vec &b) {
  return a.x * b.y - a.y * b.x;
}
void solve() {
  int n;
  qr(n);
  for (int i = 1; i <= n; ++i) {
    qr(a[i].x), qr(a[i].y);
    a[i].y -= a[i].x * a[i].x;
  }
  sort(a + 1, a + n + 1);
  int m = n;
  n = 0;
  for (int i = 1; i <= m; ++i)
    if (i == 1 || a[i].x != a[i - 1].x) a[++n] = a[i];
  for (int i = 1; i <= n; ++i) {
    Vec t = a[i];
    while (top > 1 && Cross(sta[top] - sta[top - 1], t - sta[top - 1]) > 0)
      --top;
    sta[++top] = t;
  }
  pr2(top - 1);
}
int main() {
  solve();
  return 0;
}
