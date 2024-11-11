#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int MAXN = 1e5;
const int B = 315;
int cnt[1 + MAXN], dp[1 + MAXN];
vector<int> occ[1 + MAXN];
void add_self(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
void min_self(int &x, int y) { x = min(x, y); }
struct SQRT {
  int id, offset, pref_sum[B];
  void rebuild() {
    int st = id * B, dr = (id + 1) * B - 1, minn = INT_MAX;
    for (int i = st; i <= dr; ++i) min_self(minn, offset + cnt[i]);
    for (int i = st; i <= dr; ++i) cnt[i] -= minn - offset;
    offset = minn;
    for (int i = 0; i < B; ++i) pref_sum[i] = 0;
    for (int i = st; i <= dr; ++i) add_self(pref_sum[cnt[i]], dp[i]);
    for (int i = 1; i < B; ++i) add_self(pref_sum[i], pref_sum[i - 1]);
  }
} a[MAXN / B + 1];
int get_bucket(int index) { return index / B; }
void update(int l, int r, short t) {
  int bl = get_bucket(l), br = get_bucket(r);
  for (int i = l; i <= r && get_bucket(i) == bl; ++i) cnt[i] += t;
  a[bl].rebuild();
  if (bl == br) return;
  for (int i = bl + 1; i < br; ++i) a[i].offset += t;
  for (int i = r; get_bucket(i) == br; --i) cnt[i] += t;
  a[br].rebuild();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i <= get_bucket(n); ++i) a[i].id = i;
  for (int i = 1; i <= n; ++i) occ[i].emplace_back(-1);
  dp[0] = 1;
  a[0].rebuild();
  for (int r = 0; r < n; ++r) {
    int x;
    cin >> x;
    vector<int> &vec = occ[x];
    if (static_cast<int>(vec.size()) >= 2)
      update(vec.end()[-2] + 1, vec.back(), -1);
    update(vec.back() + 1, r, 1);
    vec.emplace_back(r);
    int val = 0;
    for (int i = 0; i <= get_bucket(r); ++i) {
      int at_most = k - a[i].offset;
      if (at_most >= 0) add_self(val, a[i].pref_sum[min(at_most, B - 1)]);
    }
    dp[r + 1] = val;
    a[get_bucket(r + 1)].rebuild();
  }
  cout << dp[n] << '\n';
  return 0;
}
