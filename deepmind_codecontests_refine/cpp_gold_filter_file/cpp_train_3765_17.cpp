#include <bits/stdc++.h>
const long long md = 1000000007;
inline long long fmul(long long x, long long y, const long long P) {
  return (x * y) % P;
}
inline long long fpw(long long x, long long y, const long long modol) {
  if (x == modol - 1) return y & 1 ? modol - 1 : 1;
  long long res = 1;
  while (y) {
    if (y & 1) res = fmul(res, x, modol);
    x = fmul(x, x, modol);
    y >>= 1;
  }
  return res % modol;
}
long long exgcd(long long& x, long long& y, long long a, long long b) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  long long res = exgcd(y, x, b, a % b);
  y -= x * (a / b);
  return res;
}
inline long long ad(long long x, long long y, const long long md) {
  return x + y >= md ? x + y - md : x + y;
}
inline long long sub(long long x, long long y, const long long md) {
  return x < y ? md + x - y : x - y;
}
inline long long inv(long long o, const long long modol) {
  long long x, y;
  exgcd(x, y, o, modol);
  x = (x % modol + modol) % md;
  return x;
}
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
long long mmax(long long x, long long y) { return x > y ? x : y; }
long long mmin(long long x, long long y) { return x < y ? x : y; }
const int N = 3e5 + 10;
int n, a[N], mx[N][20], lg[N], ans, p[N], t[N], mp[N];
int max(int x, int y) { return a[x] > a[y] ? x : y; }
int query(int l, int r) {
  int k = lg[r - l + 1];
  return max(mx[l][k], mx[r - (1 << k) + 1][k]);
}
void f(int l, int r) {
  if (l > r) return;
  if (l == r) {
    if (a[l] == 1) ++ans;
    return;
  }
  int mid = query(l, r), len = a[mid], i;
  if (mid - l < r - mid) {
    for (i = l; i <= mid; ++i)
      if (i + len - 1 >= mid && i + len - 1 <= r && mp[i + len - 1] < i) ++ans;
  } else
    for (i = mid; i <= r; ++i)
      if (i - len + 1 >= l && i - len + 1 <= mid && mp[i] < i - len + 1) ++ans;
  f(l, mid - 1);
  f(mid + 1, r);
}
int main() {
  n = read();
  int i;
  for (i = 1; i <= n; ++i) a[i] = read();
  int j;
  for (i = 1; i <= n; ++i) mx[i][0] = i;
  for (j = 1; j <= 19; ++j)
    for (i = 1; i + (1 << j) - 1 <= n; ++i)
      mx[i][j] = max(mx[i][j - 1], mx[i + (1 << j - 1)][j - 1]);
  for (i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
  for (i = 1; i <= n; ++i) p[i] = t[a[i]], t[a[i]] = i;
  for (i = 1; i <= n; ++i) mp[i] = std::max(mp[i - 1], p[i]);
  f(1, n);
  std::cout << ans;
}
