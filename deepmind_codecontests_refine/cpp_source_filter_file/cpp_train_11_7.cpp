#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long INF = 1e18L;
const long long MAXN = 1e5;
const long long B = 315;
long long cnt[1 + MAXN], dp[1 + MAXN];
vector<long long> occ[1 + MAXN];
void add_self(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
}
void min_self(long long &x, long long y) { x = min(x, y); }
struct SQRT {
  long long id, offset, pref_sum[B];
  void rebuild() {
    long long st = id * B, dr = (id + 1) * B - 1, minn = INF;
    for (long long i = st; i <= dr; ++i) min_self(minn, offset + cnt[i]);
    for (long long i = st; i <= dr; ++i) cnt[i] -= minn - offset;
    offset = minn;
    for (long long i = 0; i < B; ++i) pref_sum[i] = 0;
    for (long long i = st; i <= dr; ++i) add_self(pref_sum[cnt[i]], dp[i]);
    for (long long i = 1; i < B; ++i) add_self(pref_sum[i], pref_sum[i - 1]);
  }
} a[MAXN / B + 1];
long long get_bucket(long long index) { return index / B; }
void update(long long l, long long r, short t) {
  long long bl = get_bucket(l), br = get_bucket(r);
  for (long long i = l; i <= r && get_bucket(i) == bl; ++i) cnt[i] += t;
  a[bl].rebuild();
  if (bl == br) return;
  for (long long i = bl + 1; i < br; ++i) a[i].offset += t;
  for (long long i = r; get_bucket(i) == br; --i) cnt[i] += t;
  a[br].rebuild();
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n, k;
  cin >> n >> k;
  for (long long i = 0; i <= get_bucket(n); ++i) a[i].id = i;
  for (long long i = 1; i <= n; ++i) occ[i].emplace_back(-1);
  dp[0] = 1;
  a[0].rebuild();
  for (long long r = 0; r < n; ++r) {
    long long x;
    cin >> x;
    vector<long long> &vec = occ[x];
    if (static_cast<long long>(vec.size()) >= 2)
      update(vec.end()[-2] + 1, vec.back(), -1);
    update(vec.back() + 1, r, 1);
    vec.emplace_back(r);
    long long val = 0;
    for (long long i = 0; i <= get_bucket(r); ++i) {
      long long at_most = k - a[i].offset;
      if (at_most >= 0) add_self(val, a[i].pref_sum[min(at_most, B - 1)]);
    }
    dp[r + 1] = val;
    a[get_bucket(r + 1)].rebuild();
  }
  cout << dp[n] << '\n';
  return 0;
}
