#include <bits/stdc++.h>
using namespace std;
const int mxn = 400010;
long long rd() {
  long long x = 0;
  int flg = 1;
  char c = getchar();
  for (; (c < 48 || c > 57) && c != '-'; c = getchar())
    ;
  if (c == '-') flg = -1, c = getchar();
  for (; c > 47 && c < 58; x = x * 10 + c - 48, c = getchar())
    ;
  return flg * x;
}
int m;
long long n, k, a[mxn], L, R;
pair<long long, long long> b[mxn];
void solve() {
  n = rd(), m = rd(), k = rd();
  ++m, k += m;
  for (int i = 1; i < m; ++i) a[i] = rd();
  a[m] = n;
  for (int i = m; i; --i) a[i] -= a[i - 1];
  long long l = 1, r = n;
  for (int i = 1; i <= m; ++i) r = min(r, a[i]);
  for (; l <= r;) {
    long long mid = ((l + r) >> 1), sum = 0;
    for (int i = 1; i <= m; ++i) sum += a[i] / mid;
    if (sum >= k)
      l = mid + 1;
    else
      r = mid - 1;
  }
  L = r;
  l = 1, r = 0;
  for (long long i = 1; i <= m; ++i) r = max(r, a[i]);
  r = min(r, n - k + 1);
  for (; l <= r;) {
    long long mid = ((l + r) >> 1), sum = 0;
    for (int i = 1; i <= m; ++i) sum += (a[i] - 1) / mid + 1;
    if (sum <= k)
      r = mid - 1;
    else
      l = mid + 1;
  }
  R = l;
  if (L >= R) return (void)(puts("0"));
  n = 0;
  for (int i = 1; i <= m; ++i)
    if ((a[i] - 1) / R >= a[i] / L)
      b[++n] =
          make_pair(a[i] / ((a[i] - 1) / R + 1), (a[i] - 1) / (a[i] / L) + 1);
  b[++n] = make_pair(L, 1e18);
  b[++n] = make_pair(-1e18, R);
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; ++i) a[i] = max(a[i - 1], b[i].second);
  long long ans = 1e18;
  for (int i = n; i > 1; --i) ans = min(ans, a[i - 1] - b[i].first);
  printf("%lld\n", ans);
}
int main() {
  for (int T = rd(); T--; solve())
    ;
  return 0;
}
