#include <bits/stdc++.h>
using namespace std;
const int mx = 1000000;
long long a[2000005], b[2000005], lazy[4 * 2000005], tr[4 * 2000005];
void pro(int p, int s, int e) {
  tr[p] += lazy[p];
  if (s != e) {
    lazy[p << 1] += lazy[p];
    lazy[p << 1 | 1] += lazy[p];
  }
  lazy[p] = 0;
}
void update(int p, int s, int e, int l, int r, long long val) {
  if (lazy[p] != 0) pro(p, s, e);
  if (s > r || e < l) return;
  if (s >= l && e <= r) {
    lazy[p] += val;
    pro(p, s, e);
    return;
  }
  int m = (s + e) >> 1;
  update(p << 1, s, m, l, r, val);
  update(p << 1 | 1, m + 1, e, l, r, val);
  tr[p] = max(tr[p << 1], tr[p << 1 | 1]);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  memset(a, 0x3f, sizeof a);
  memset(b, 0x3f, sizeof b);
  for (int i = 1; i <= n; i++) {
    long long p, q;
    cin >> p >> q;
    a[p] = min(a[p], q);
  }
  for (int i = 1; i <= m; i++) {
    long long p, q;
    cin >> p >> q;
    b[p] = min(b[p], q);
  }
  for (int i = mx; i >= 1; i--) {
    a[i] = min(a[i], a[i + 1]);
    b[i] = min(b[i], b[i + 1]);
  }
  for (int i = 1; i <= mx; i++) {
    update(1, 1, mx, i, i, -b[i]);
  }
  vector<tuple<int, int, int>> v;
  for (int i = 1; i <= k; i++) {
    int p, q, r;
    cin >> p >> q >> r;
    v.push_back(make_tuple(p, q, r));
  }
  sort(v.begin(), v.end());
  long long ans = -b[1] - a[1];
  for (auto u : v) {
    int p, q, r;
    tie(p, q, r) = u;
    long long c = a[p + 1];
    update(1, 1, mx, q + 1, mx, r);
    ans = max(ans, tr[1] - c);
  }
  cout << ans << "\n";
  return 0;
}
