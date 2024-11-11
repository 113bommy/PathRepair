#include <bits/stdc++.h>
using namespace std;
const int inf = ~0U >> 1;
const long long INF = ~0ULL >> 1;
;
const double pi = acos(-1.0);
template <class T>
inline T sqr(T a) {
  return a * a;
}
template <class T>
inline void read(T &n) {
  char c;
  for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar())
    ;
  n = c - '0';
  for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}
int Pow(int base, int n, int mo) {
  if (n == 0) return 1;
  if (n == 1) return base;
  int tmp = Pow(base, n >> 1, mo);
  tmp = (long long)tmp * tmp % mo;
  if (n & 1) tmp = (long long)tmp * base % mo;
  return tmp;
}
struct point {
  int x, y;
  point() {}
  point(int _x, int _y) : x(_x), y(_y) {}
};
const int maxn = 200000;
int n;
long long a, b, c, d, x, y, N, hx[maxn], hy[maxn];
int cntx, cnty, ans, C[maxn], dp[maxn];
pair<long long, long long> p[maxn];
void modify(int x, int y) {
  while (x <= cnty) C[x] = max(C[x], y), x += x & (-x);
}
int query(int x) {
  int ret = 0;
  while (x) ret = max(ret, C[x]), x -= x & (-x);
  return ret;
}
int main() {
  scanf("%d", &n);
  scanf("%lld/%lld%lld/%lld", &a, &b, &c, &d);
  for (int i = (1); i <= (n); ++i) {
    scanf("%lld%lld", &x, &y);
    if (b * y > a * x && d * y < c * x) {
      N++;
      p[N] = (make_pair(abs(a * x - b * y), abs(c * x - d * y)));
    }
  }
  n = N;
  for (int i = (1); i <= (n); ++i)
    hx[++cntx] = p[i].first, hy[++cnty] = p[i].second;
  sort(hx + 1, hx + cntx + 1);
  sort(hy + 1, hy + cnty + 1);
  cntx = unique(hx + 1, hx + cntx + 1) - hx - 1;
  cnty = unique(hy + 1, hy + cnty + 1) - hy - 1;
  for (int i = (1); i <= (n); ++i) {
    p[i].first = lower_bound(hx + 1, hx + cntx + 1, p[i].first) - hx;
    p[i].second = lower_bound(hy + 1, hy + cnty + 1, p[i].second) - hy;
  }
  sort(p + 1, p + n + 1);
  for (int i = (1); i <= (n); ++i) {
    int j = i;
    while (j <= n && p[i].first == p[j].first) j++;
    for (int k = (i); k <= (j - 1); ++k)
      dp[k] = query(p[i].second - 1) + 1, ans = max(ans, dp[k]);
    for (int k = (i); k <= (j - 1); ++k) modify(p[i].second, dp[k]);
    i = j - 1;
  }
  printf("%d\n", ans);
  return 0;
}
