#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <typename T1, typename T2>
inline void mine(T1 &x, T2 y) {
  if (x > y) x = y;
}
template <typename T1, typename T2>
inline void maxe(T1 &x, T2 y) {
  if (x < y) x = y;
}
ostream &operator<<(ostream &a, const vector<int> &b) {
  for (auto k : b) cout << k << ' ';
  return a;
}
const int MOD = 1000000007;
const int INF = 1000000050;
const long long BIG = (long long)2e18 + 50;
const int MX = 1 << 19;
const double EPS = 1e-9;
const int D = 2400;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
int a[MX];
int f[MX];
vector<int> in[MX];
int add[256];
unordered_map<int, int> cnt[256];
void upd(int l, int r, int x) {
  if (r - l + 1 < D) {
    for (int i = l; i < r + 1; i++) {
      int bl = i / D;
      --cnt[bl][f[i]];
      f[i] += x;
      ++cnt[bl][f[i]];
    }
    return;
  }
  int bl1 = l / D;
  int bl2 = r / D;
  while (l % D != 0) {
    --cnt[bl1][f[l]];
    f[l] += x;
    ++cnt[bl1][f[l]];
    ++l;
  }
  while (r % D != D - 1) {
    --cnt[bl2][f[r]];
    f[r] += x;
    ++cnt[bl2][f[r]];
    --r;
  }
  bl1 = l / D;
  bl2 = r / D;
  while (bl1 <= bl2) {
    add[bl1++] += x;
  }
}
int get(int x) {
  int ans = 0;
  for (int bl = 0; bl * D < n; ++bl) {
    if (cnt[bl].count(x - add[bl])) ans += cnt[bl][x - add[bl]];
  }
  return ans;
}
pair<int, int> kek(int x, int it) {
  if ((int)in[x].size() == it + 3) return {in[x][it + 2], n - 1};
  return {in[x][it + 2], in[x][it + 3] - 1};
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    in[a[i]].push_back(i);
  }
  for (int bl = 0; bl * D < n; ++bl) {
    cnt[bl].reserve(1 << 15);
    cnt[bl].max_load_factor(0.05);
    add[bl] = 0;
  }
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    int x = a[i];
    int it = lower_bound(in[x].begin(), in[x].end(), i) - in[x].begin();
    if ((int)in[x].size() - it > 3) {
      pair<int, int> seg = kek(x, it + 1);
      upd(seg.first, seg.second, -3);
    }
    int bl = i / D;
    cnt[bl][-i - add[bl]]++;
    f[i] = -i - add[bl];
    if ((int)in[x].size() - it >= 3) {
      pair<int, int> seg = kek(x, it);
      upd(seg.first, seg.second, 3);
    }
    ans += get(-i + 1);
  }
  cout << ans << '\n';
}
