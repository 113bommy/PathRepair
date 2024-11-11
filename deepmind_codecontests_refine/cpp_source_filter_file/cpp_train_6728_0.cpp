#include <bits/stdc++.h>
using namespace std;
const int N = 2005, M = N * N;
const double z = 1e-8;
int n, ans, m, sum;
double dis[N];
bool bz[N];
struct P {
  double x, y;
  P() {}
  P(double _x, double _y) {
    x = _x;
    y = _y;
  }
} A[N], B[N], H, tmp, Now, zilch;
struct Data {
  P w;
  double z;
  int p, q;
} a[M];
bool operator<(Data a, Data b) { return a.z < b.z; }
double operator*(P a, P b) { return a.x * b.y - a.y * b.x; }
P Get(P a, P b) {
  double a0 = -a.y, b0 = a.x, c0 = 0, a1 = b0, b1 = -a0,
         c1 = -a1 * b.x - b1 * b.y, d = a0 * b1 - a1 * b0;
  return P((b0 * c1 - b1 * c0) / d, (a1 * c0 - a0 * c1) / d);
}
bool Same(double x, double y) { return x - y < z && y - x < z; }
long long gcd(long long x, long long y) { return (!y) ? x : gcd(y, x % y); }
double getdis(P a, P b) {
  return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main() {
  scanf("%d", &m);
  for (int x, y, i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    B[i] = P(x, y);
    H.x += x;
    H.y += y;
  }
  H.x /= m;
  H.y /= m;
  for (int i = 1; i < m; i++)
    if (!bz[i])
      for (int j = i + 1; j <= m; j++)
        if (!bz[j] && Same(B[i].x - H.x, H.x - B[j].x) &&
            Same(B[i].y - H.y, H.y - B[j].y)) {
          bz[i] = bz[j] = 1;
          break;
        }
  for (int i = 1; i <= m; i++)
    if (!bz[i]) A[++n] = B[i];
  if (n < 1) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++) {
      tmp = P((A[i].y + A[j].y) / 2 - H.y, H.x - (A[i].x + A[j].x) / 2);
      if (tmp.x < 0) {
        tmp.x = -tmp.x;
        tmp.y = -tmp.y;
      }
      if (tmp.x == 0) tmp.y = fabs(tmp.y);
      if (tmp.y == 0) tmp.x = fabs(tmp.x);
      a[++sum].w = tmp;
      a[sum].p = i;
      a[sum].q = j;
      a[sum].z = atan2(tmp.y, tmp.x);
    }
  sort(a + 1, a + sum + 1);
  ans = 0;
  for (int i = 1, l = 1; i <= sum; i++)
    if (i == sum || a[i].w * a[i + 1].w != 0) {
      if (i - l + 1 >= n / 2) {
        for (int j = 1; j <= n; j++) bz[j] = 1;
        for (; l <= i; l++) {
          if (bz[a[l].p] && bz[a[l].q]) bz[a[l].p] = bz[a[l].q] = 0;
        }
        int k = 0, cc = 0;
        for (int j = 1; j <= n; j++)
          if (bz[j]) {
            cc++;
            k = j;
          }
        if (cc > (n & 1)) continue;
        if (!k || getdis(Get(a[i].w, H), Get(a[i].w, A[k])) < z) ans++;
      }
      l = i + 1;
    }
  printf("%d\n", ans);
  return 0;
}
