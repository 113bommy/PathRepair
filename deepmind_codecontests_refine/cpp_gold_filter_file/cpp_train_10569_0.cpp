#include <bits/stdc++.h>
inline int getint() {
  int x = 0, p = 1;
  char c = getchar();
  while (c <= 32) c = getchar();
  if (c == 45) p = -p, c = getchar();
  while (c > 32) x = x * 10 + c - 48, c = getchar();
  return x * p;
}
using namespace std;
const int mod = 1e9 + 7;
inline void reduce(int &x) { x += x >> 31 & mod; }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
const int N = 2e5 + 5;
int n, a[N], b[N], id[N];
long long l[N], r[N], T;
bool cmp(int x, int y) { return 1ll * a[y] * b[x] < 1ll * a[x] * b[y]; }
bool cmp2(int x, int y) { return a[x] > a[y]; }
inline pair<long double, long double> calc(int x, double y) {
  long long L = l[x], R = r[x];
  return make_pair((1.0 - y * r[x] / (1.0 * T)) * a[x],
                   (1.0 - y * l[x] / (1.0 * T)) * a[x]);
}
int main() {
  n = getint();
  for (int(i) = 0; (i) < (n); (i)++) a[i] = getint();
  for (int(i) = 0; (i) < (n); (i)++) T += 1ll * (b[i] = getint());
  for (int(i) = 0; (i) < (n); (i)++) id[i] = i;
  sort(id, id + n, cmp);
  long long tnow = 0;
  for (int ii = 0, j; ii < n; ii = j + 1) {
    j = ii;
    long long L = tnow, R = L;
    while (j + 1 < n &&
           1ll * a[id[ii]] * b[id[j + 1]] == 1ll * b[id[ii]] * a[id[j + 1]])
      ++j;
    for (int k = ii; k <= j; k++) R += b[id[k]];
    for (int k = ii; k <= j; k++) l[id[k]] = L + b[id[k]], r[id[k]] = R;
    tnow = R;
  }
  for (int(i) = 0; (i) < (n); (i)++) id[i] = i;
  sort(id, id + n, cmp2);
  double lb = 0.0, rb = 1.0;
  for (int(tt) = 0; (tt) < (50); (tt)++) {
    double mid = (lb + rb) / 2.0;
    long double now = 1000000000;
    bool fg = true;
    for (int i = 0, j; i < n; i = j + 1) {
      j = i;
      while (j + 1 < n && a[id[j + 1]] == a[id[i]]) ++j;
      long double tomn = now;
      for (int k = i; k <= j; k++) {
        pair<long double, long double> u = calc(id[k], mid);
        if (u.second > now) {
          fg = false;
          break;
        }
        tomn = min(tomn, u.first);
      }
      if (!fg) break;
      now = tomn;
    }
    if (fg)
      lb = mid;
    else
      rb = mid;
  }
  printf("%.11f\n", lb);
  return 0;
}
