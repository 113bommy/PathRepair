#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 10;
const long long mod = 998244353;
const long long MAX_N = 1e6 + 10;
const long long N = 1e6 + 5;
const long long inf = 1e18;
const long long INF = 1e16;
long long seg[4 * MAX_N], la[4 * MAX_N];
void shift(long long v) {
  seg[v] += la[v];
  if (v < 2 * MAX_N) {
    la[v << 1] += la[v];
    la[v << 1 | 1] += la[v];
  }
  la[v] = 0;
}
void up(long long l, long long r, long long val, long long v = 1,
        long long tl = 1, long long tr = N) {
  if (tl == l && tr == r) {
    la[v] += val;
    shift(v);
    return;
  }
  shift(v);
  if (l > r) return;
  long long tm = (tl + tr) >> 1;
  up(l, min(tm, r), val, v << 1, tl, tm);
  up(max(l, tm + 1), r, val, v << 1 | 1, tm + 1, tr);
  seg[v] = max(seg[v << 1], seg[v << 1 | 1]);
}
long long qu() {
  shift(1);
  return seg[1];
}
long long s, t, n;
long long a[maxn], b[maxn], ca[maxn], cb[maxn];
long long mna[maxn];
long long ar[MAX_N];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  fill(ar, ar + MAX_N, -inf);
  cin >> s >> t >> n;
  vector<pair<long long, long long>> A;
  for (long long i = 1; i <= s; i++) {
    cin >> a[i] >> ca[i];
    A.push_back({a[i], ca[i]});
  }
  for (long long i = 1; i <= t; i++) {
    cin >> b[i] >> cb[i];
    ar[b[i]] = max(-cb[i], ar[b[i]]);
  }
  for (long long i = N; i >= 1; i--) {
    ar[i] = max(ar[i + 1], ar[i]);
    up(i, i, ar[i]);
  }
  sort(A.begin(), A.end());
  mna[A.size()] = inf;
  for (long long i = A.size() - 1; i >= 0; i--)
    mna[i] = min(mna[i + 1], A[i].second);
  vector<pair<pair<long long, long long>, long long>> ve;
  for (long long i = 1, x, y, z; i <= n; i++) {
    cin >> x >> y >> z;
    ve.push_back({{x, y}, z});
  }
  sort(ve.begin(), ve.end());
  long long ans = -inf;
  for (auto X : ve) {
    long long x = X.first.first, y = X.first.second, z = X.second;
    x++;
    y++;
    up(y, N, z);
    long long XX =
        lower_bound(A.begin(), A.end(), make_pair(x, -inf)) - A.begin();
    ans = max(ans, -mna[XX] + qu());
  }
  if (ans < -(INF)) return cout << -mna[0] + ar[1], 0;
  cout << ans;
}
