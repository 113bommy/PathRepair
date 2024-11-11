#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
struct Positions {
  long long posx, posy;
} a[N];
long long n;
long long maxf[N], minf[N], maxr[N], minr[N];
long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
bool cmp(Positions x, Positions y) { return x.posx < y.posx; }
bool check(long long mid) {
  long long h = 1;
  for (long long i = 1; i <= n; i++) {
    for (h; h <= n; h++)
      if ((a[h].posx - a[i].posx) > mid) break;
    long long needmax = (max(maxf[i - 1], maxr[h]));
    long long needmin = (min(minf[i - 1], minr[h]));
    if ((needmax - needmin) <= mid) return true;
  }
  return false;
}
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) {
    long long tmpx = read(), tmpy = read();
    a[i].posx = tmpx - tmpy;
    a[i].posy = tmpx + tmpy;
  }
  sort(a + 1, a + n + 1, cmp);
  maxf[0] = -1e10, minf[0] = 1e10;
  for (long long i = 1; i <= n; i++) {
    maxf[i] = max(maxf[i - 1], a[i].posy);
    minf[i] = min(minf[i - 1], a[i].posy);
  }
  maxr[n + 1] = -1e10, minr[n + 1] = 1e10;
  for (long long i = n; i >= 1; i--) {
    maxr[i] = max(maxr[i + 1], a[i].posy);
    minr[i] = min(minr[i + 1], a[i].posy);
  }
  long long l = 0, r = 1e10, mid;
  long long ans;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (check(mid))
      ans = r, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%.16lf", (double)ans / 2.00);
  return 0;
}
