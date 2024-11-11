#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N], b[N];
long long c[2], d[N];
set<long long> se;
long long mabs(long long x) { return x < 0 ? -x : x; }
long long calc(long long x) {
  long long res = 1ll << 60;
  auto it = se.upper_bound(x);
  if (it != se.end()) res = min(res, mabs(x - *it));
  --it;
  res = min(res, mabs(x - *it));
  return res;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= (n); ++i) cin >> a[i];
  for (int i = 1; i <= (m); ++i) cin >> b[i];
  for (int i = 1; i <= (n); ++i) c[i & 1] += a[i];
  for (int i = 1; i <= (m); ++i) d[i] = d[i - 1] + (i & 1 ? b[i] : -b[i]);
  for (int i = 1; i <= (m); ++i)
    if (i >= n) {
      if ((i - n) & 1)
        se.insert(d[i - n] - d[i]);
      else
        se.insert(d[i] - d[i - n]);
    }
  cout << calc(c[1] - c[0]) << endl;
  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;
    if ((r - l + 1) & 1) c[l & 1] += x;
    cout << calc(c[1] - c[0]) << endl;
  }
  return 0;
}
