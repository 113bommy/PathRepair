#include <bits/stdc++.h>
#pragma GCC optimize("O3,no-stack-protector")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
int64_t Mul(int64_t a, int64_t b, int64_t mod) { return (a * b) % mod; }
int64_t Sum(int64_t a, int64_t b, int64_t mod) { return (a + b) % mod; }
int64_t Can(int64_t a, int64_t mod) { return ((a % mod) + mod) % mod; }
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int64_t a, b, p, q;
    cin >> a >> b >> p >> q;
    int64_t mod = 2 * q;
    int64_t bs = sqrt(b - a + 1);
    vector<pair<int64_t, int64_t>> vec;
    set<int64_t> seen;
    for (int x = a; x < bs + a; ++x) {
      int64_t key = Can(2 * p * x, mod);
      if (seen.count(key) == 0) {
        vec.emplace_back(key, x);
        seen.insert(key);
      }
    }
    sort(begin(vec), end(vec));
    pair<int64_t, int64_t> best = {mod + 1, 0};
    int bi = 0;
    for (; a + (bi + 1) * bs <= b; ++bi) {
      int64_t target = Can(q - bi * bs * 2 * p, mod);
      pair<int64_t, int64_t> to_find = {target, -1};
      int pos = lower_bound(begin(vec), end(vec), to_find) - begin(vec);
      for (int s = 0; s <= 1; ++s) {
        int j = Can(pos - s, vec.size());
        int64_t dist = abs(target - vec[j].first);
        if (dist > q) {
          dist = mod - q;
        }
        pair<int64_t, int64_t> cur = {dist, vec[j].second + bi * bs};
        best = min(best, cur);
      }
    }
    for (int64_t x = a + bi * bs; x < b; ++x) {
      int64_t dist = abs(q - Can(2 * p * x, mod));
      if (dist > q) {
        dist = mod - q;
      }
      pair<int64_t, int64_t> cur = {dist, x};
      best = min(best, cur);
    }
    cout << best.second << '\n';
  }
  return 0;
}
