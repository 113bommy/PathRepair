#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
static inline int Rint() {
  struct X {
    int dig[256];
    X() {
      for (int i = '0'; i <= '9'; ++i) dig[i] = 1;
      dig['-'] = 1;
    }
  };
  static X fuck;
  int s = 1, v = 0, c;
  for (; !fuck.dig[c = getchar()];)
    ;
  if (c == '-')
    s = 0;
  else if (fuck.dig[c])
    v = c ^ 48;
  for (; fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48))
    ;
  return s ? v : -v;
}
template <typename T>
static inline void cmax(T& a, const T& b) {
  if (b > a) a = b;
}
template <typename T>
static inline void cmin(T& a, const T& b) {
  if (b < a) a = b;
}
const int maxn = 100005;
int data[505][505];
long long sum[505][505];
long long ps[505][505];
long long best_sum[505][505];
long long best_cnt[505][505];
static inline long long sq(long long x) { return x * x; }
static inline int check_intersection(int x1, int y1, int x2, int y2, int r) {
  const int r2 = r * r;
  const int F = sq(2 * (r + 2)) + 370;
  const int d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  if (d <= F) {
    const int sx = x1 + x2;
    const int sy = y1 + y2;
    int ux[2], uy[2];
    int tx = sx >> 1, ty = sy >> 1;
    for (int a = -2; a <= 3; ++a)
      for (int b = -2; b <= 3; ++b) {
        int t0 = sq(a + tx - x1) + sq(b + ty - y1);
        if (t0 > r2) continue;
        int t1 = sq(a + tx - x2) + sq(b + ty - y2);
        if (t1 > r2) continue;
        return 1;
      }
  }
  return 0;
}
int main() {
  const int n = Rint(), m = Rint(), r = Rint();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) data[i][j] = Rint();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) ps[i][j] = data[i][j] + ps[i][j - 1];
  const int r2 = r * r;
  for (int i = r + 1; i <= n - r; ++i)
    for (int j = r + 1; j <= m - r; ++j) {
      long long s = 0;
      int l = j;
      for (int ii = i - r; ii <= i; ++ii) {
        while (sq(ii - i) + sq(l - j) <= r2) --l;
        const int r = 2 * j - l;
        s += ps[ii][r - 1] - ps[ii][l];
        int other = 2 * i - ii;
        if (other != ii) s += ps[other][r - 1] - ps[other][l];
      }
      sum[i][j] = s;
    }
  for (int i = 1; i <= n; ++i) {
    long long bv = 0;
    int bc = 0;
    for (int j = m; j >= 1; --j) {
      if (sum[i][j] > bv)
        bv = sum[i][j], bc = 1;
      else if (sum[i][j] == bv)
        ++bc;
      best_sum[i][j] = bv;
      best_cnt[i][j] = bv ? bc : 0;
    }
  }
  const int limit = (r + 15) * (r + 15);
  const int most = (r + 1) * 2;
  long long best = 0;
  long long cnt = 0;
  for (int j = r + 1; j <= m - r; ++j)
    for (int i = r + 1; i <= n - r; ++i) {
      const long long s1 = sum[i][j];
      for (int ii = r + 1; ii < i - 2 * r; ++ii) {
        if (best_sum[ii][j + 1] == 0) continue;
        long long t = s1 + best_sum[ii][j + 1];
        if (t > best)
          best = t, cnt = best_cnt[ii][j + 1];
        else if (t == best)
          cnt += best_cnt[ii][j + 1];
      }
      for (int ii = i + 2 * r + 1; ii <= n - r; ++ii) {
        if (best_sum[ii][j] == 0) continue;
        long long t = s1 + best_sum[ii][j];
        if (t > best)
          best = t, cnt = best_cnt[ii][j];
        else if (t == best)
          cnt += best_cnt[ii][j];
      }
      const int starti = max(i - 2 * r, r + 1);
      const int endi = min(i + 2 * r, n - r);
      for (int ii = starti, lastj = j + 1; ii <= i; ++ii) {
        while (lastj <= m - r && check_intersection(i, j, ii, lastj, r))
          ++lastj;
        if (lastj > m - r) break;
        const int s = s1 + best_sum[ii][lastj];
        if (s > best)
          best = s, cnt = best_cnt[ii][lastj];
        else if (s == best)
          cnt += best_cnt[ii][lastj];
      }
      for (int ii = endi, lastj = j; ii > i; --ii) {
        while (lastj <= m - r && check_intersection(i, j, ii, lastj, r))
          ++lastj;
        if (lastj > m - r) break;
        const int s = s1 + best_sum[ii][lastj];
        if (s > best)
          best = s, cnt = best_cnt[ii][lastj];
        else if (s == best)
          cnt += best_cnt[ii][lastj];
      }
    }
  printf("%I64d %I64d\n", best, cnt);
  return 0;
}
