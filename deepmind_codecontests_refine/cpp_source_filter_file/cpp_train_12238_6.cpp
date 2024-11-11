#include <bits/stdc++.h>
using namespace std;
const long long maxn = 5005;
long long f[maxn][maxn];
long long x[maxn], a[maxn], b[maxn], c[maxn], d[maxn];
long long N, s, e;
long long calc(long long i, long long l, long long r) {
  long long& res = f[i][l];
  if (res != -1) return res;
  if (l + r > i) {
    return 1e18;
  }
  if (i > N) {
    if (l == r && l == 0) return 0;
    return 1e18;
  }
  if (l + r == 0 && i > 1) return 1e18;
  if (i == s) {
    if (l) {
      return res = min(x[i] + c[i] + calc(i + 1, l - 1, r),
                       -x[i] + d[i] + calc(i + 1, l, r + 1));
    }
    return res = -x[i] + d[i] + calc(i + 1, l, r + 1);
  }
  if (i == e) {
    if (r)
      return res = min(x[i] + a[i] + calc(i + 1, l, r - 1),
                       -x[i] + b[i] + calc(i + 1, l + 1, r));
    return res = -x[i] + b[i] + calc(i + 1, l + 1, r);
  }
  res = 1e18;
  if (l && r)
    res = min(res, x[i] + c[i] + x[i] + a[i] + calc(i + 1, l - 1, r - 1));
  if (l) res = min(res, x[i] + c[i] + -x[i] + b[i] + calc(i + 1, l, r));
  if (r) res = min(res, -x[i] + d[i] + x[i] + a[i] + calc(i + 1, l, r));
  res = min(res, -x[i] + b[i] + -x[i] + d[i] + calc(i + 1, l + 1, r + 1));
  return res;
}
signed main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> s >> e;
  for (long long i = 1; i <= N; ++i) {
    cin >> x[i];
  }
  for (long long i = 1; i <= N; ++i) {
    cin >> a[i];
  }
  for (long long i = 1; i <= N; ++i) {
    cin >> b[i];
  }
  for (long long i = 1; i <= N; ++i) {
    cin >> c[i];
  }
  for (long long i = 1; i <= N; ++i) {
    cin >> d[i];
  }
  memset(f, -1, sizeof f);
  cout << calc(1, 0, 0);
}
