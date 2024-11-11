#include <bits/stdc++.h>
using namespace std;
const int Maxn = 100015, Maxm = 100005, Mo = 1000000007;
const long long oo = LLONG_MAX >> 1;
struct Tree {
  int l, r;
};
struct edge {
  int v, c, nt;
};
struct point {
  long long x, y;
};
typedef int IArr[Maxn];
typedef long long LArr[Maxn];
typedef double DArr[Maxn];
point p[Maxn];
int i, j, n, T, ans, k, m;
LArr x, y, lmin, rmin, lmax, rmax;
bool cmp(point a, point b) { return a.x < b.x; }
bool check(long long d) {
  int lpos = 0, rpos = n + 1;
  while (p[rpos - 1].x - d > p[1].x) rpos--;
  long long pos = p[1].x;
  for (i = 1; i <= n * 2 + 1; i++) {
    while (rpos <= n && p[rpos].x - pos <= d) rpos++;
    while (lpos <= n && pos - p[lpos + 1].x > d) lpos++;
    long long Max = max(lmax[lpos], rmax[rpos]);
    long long Min = min(lmin[lpos], rmin[rpos]);
    if (Max - Min <= d) return 1;
    pos = min(p[lpos + 1].x + d + 1, p[rpos].x - d);
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (i = 1; i <= n; i++) {
    long long x, y;
    cin >> x >> y;
    p[i].x = x - y;
    p[i].y = x + y;
    p[i].x *= 2;
  }
  sort(p + 1, p + n + 1, cmp);
  lmin[0] = oo;
  lmax[0] = -oo;
  lmin[1] = lmax[1] = p[1].y;
  for (i = 2; i <= n; i++) {
    lmin[i] = min(lmin[i - 1], p[i].y);
    lmax[i] = max(lmax[i - 1], p[i].y);
  }
  rmin[n + 1] = oo;
  rmax[n + 1] = -oo;
  rmin[n] = rmax[n] = p[n].y;
  for (i = n - 1; i >= 1; i--) {
    rmin[i] = min(rmin[i + 1], p[i].y);
    rmax[i] = max(rmax[i + 1], p[i].y);
  }
  long long l = 0, r = 1100000000;
  p[n + 1].x = p[n + 2].x = oo;
  while (l < r) {
    long long mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%.10f\n", l / 2.0);
}
