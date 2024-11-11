#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
struct data {
  long long v, id;
} b[maxn];
long long a[maxn], res, n, cf, cm, A, m, sum[maxn], sumr[maxn], rcf, rcm, gtm;
bool kt(long long v, long long m) {
  return ((a[v] * (n - v + 1) - sumr[v]) <= m);
}
long long bs(long long l, long long r, long long m) {
  long long res = r;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (kt(mid, m))
      res = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  return res;
}
bool cmp(data a, data b) { return a.v > b.v; }
bool cmp1(data a, data b) { return a.id > b.id; }
int main() {
  cin >> n >> A >> cf >> cm >> m;
  for (long long i = 1; i <= n; ++i) scanf("%I64d", &b[i].v), b[i].id = i;
  sort(b + 1, b + n + 1, cmp);
  for (int i = 1; i <= n; ++i) a[i] = b[i].v;
  for (long long i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
  for (long long i = n; i >= 1; --i) sumr[i] = sumr[i + 1] + a[i];
  res = -1;
  for (long long i = 0; i <= n; ++i) {
    if (m < A * i - sum[i]) break;
    long long nm = m - (A * i - sum[i]);
    long long vt = bs(i + 1, n, nm);
    long long gtmin = a[vt];
    nm -= (a[vt] * (n - vt + 1) - sumr[vt]);
    gtmin = min(gtmin + nm / (n - vt + 1), A);
    if (vt == n) gtmin = A;
    if (res < cf * i + cm * gtmin) {
      res = cf * i + cm * gtmin;
      rcf = i;
      rcm = vt;
      gtm = gtmin;
    }
  }
  for (int i = 1; i <= rcf; ++i) b[i].v = A;
  for (int i = rcm; i <= n; ++i) b[i].v = gtm;
  sort(b + 1, b + n + 1, cmp1);
  cout << res << endl;
  for (int i = 1; i <= n; ++i) printf("%I64d ", b[i].v);
}
