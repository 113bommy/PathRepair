#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
template <typename T>
inline void read(T &AKNOI) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  AKNOI = flag * x;
}
namespace ModCalculator {
const long long MOD = 1e9 + 7;
inline void Inc(long long &x, long long y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
inline void Dec(long long &x, long long y) {
  x -= y;
  if (x < 0) x += MOD;
}
inline long long Add(long long x, long long y) {
  Inc(x, y);
  return x;
}
inline long long Sub(long long x, long long y) {
  Dec(x, y);
  return x;
}
inline long long Mul(long long x, long long y) { return x * y % MOD; }
}  // namespace ModCalculator
using namespace ModCalculator;
int n, nn;
struct point {
  long long x, y;
  point() {}
  point(long long _x, long long _y) : x(_x), y(_y) {}
  friend point operator+(point a, point b) {
    return point(a.x + b.x, a.y + b.y);
  }
  friend point operator-(point a, point b) {
    return point(a.x - b.x, a.y - b.y);
  }
  friend long long operator^(point a, point b) { return a.x * b.y - a.y * b.x; }
} p[MAXN];
long long s[MAXN], ss[MAXN], sx[MAXN], sy[MAXN];
unsigned long long siz, half;
void init() {
  read(n);
  nn = n + n;
  for (int i = 1; i <= n; ++i) {
    read(p[i].x);
    read(p[i].y);
    p[n + i] = p[i];
  }
  siz = 0;
  for (int i = 1; i <= n; ++i) {
    siz += (p[i + 1] ^ p[i]);
  }
  for (int i = 1; i <= nn; ++i) {
    long long x = ((p[i] ^ p[i - 1]) % MOD + MOD) % MOD;
    s[i] = Add(s[i - 1], x);
    ss[i] = Add(ss[i - 1], s[i]);
    sx[i] = (sx[i - 1] + p[i].x + MOD) % MOD;
    sy[i] = (sy[i - 1] + p[i].y + MOD) % MOD;
  }
}
void solve() {
  long long ans = half = 0;
  for (int i = 1, j = 1; i <= n; ++i) {
    while (half + ((p[j + 1] - p[i]) ^ (p[j] - p[i])) <= siz / 2) {
      half += ((p[j + 1] - p[i]) ^ (p[j] - p[i]));
      ++j;
    }
    if (i < j) {
      long long tmp = Sub(Sub(ss[j], ss[i]), Mul(s[i], j - i));
      Inc(tmp, Mul(p[i].x + MOD, Sub(sy[j], sy[i])));
      Dec(tmp, Mul(p[i].y + MOD, Sub(sx[j], sx[i])));
      ans += Sub(Mul(siz % MOD, j - i - 1), Mul(tmp, 2));
      half -= ((p[j] - p[i]) ^ (p[i + 1] - p[i]));
    }
  }
  printf("%lld\n", ans);
}
int main() {
  init();
  solve();
  return 0;
}
