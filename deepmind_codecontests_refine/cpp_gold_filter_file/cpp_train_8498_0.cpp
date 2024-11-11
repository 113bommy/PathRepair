#include <bits/stdc++.h>
using namespace std;
struct box {
  int len;
  int special;
};
bool operator<(box a, box b) {
  if (a.special && !b.special)
    return false;
  else if (!a.special && b.special)
    return true;
  else if (!a.special && !b.special)
    return a.len < b.len;
  else
    return a.len > b.len;
}
constexpr int maxn = 1e4 + 100;
int n, l, r;
box v[maxn] = {};
int suffix_len_sum[maxn] = {};
int d[maxn] = {};
int solve() {
  sort(v + 1, v + n + 1);
  for (int i = n; i >= 0; --i)
    suffix_len_sum[i] = v[i].len + suffix_len_sum[i + 1];
  d[0] = 0;
  for (int i = 1; i < maxn; ++i) d[i] = n + 100;
  int sol = 0, cnt_special = 0;
  for (int i = 1; i <= n; ++i) {
    if (v[i].special) {
      const int cur_len = suffix_len_sum[i];
      int best = maxn + 100;
      for (int i = l; i <= r - cur_len; ++i) best = min(best, d[i]);
      if (best > cnt_special) best = best + 0;
      if (best == cnt_special) sol = max(sol, n - i + 1);
      if (best < cnt_special) sol = max(sol, n - i + 1 + 1);
      ++cnt_special;
    }
    for (int j = maxn - 1; j - v[i].len >= 0; --j)
      d[j] = min(d[j], d[j - v[i].len] + v[i].special);
  }
  return sol;
}
int main() {
  cin >> n >> l >> r;
  for (int i = 1; i <= n; ++i) cin >> v[i].len;
  for (int i = 1; i <= n; ++i) cin >> v[i].special;
  ++n;
  v[n].len = 0;
  v[n].special = 1;
  cout << max(solve() - 1, 0) << endl;
  ;
  return 0;
}
