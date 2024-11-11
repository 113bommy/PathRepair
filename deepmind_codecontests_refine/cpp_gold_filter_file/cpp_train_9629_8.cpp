#include <bits/stdc++.h>
using namespace std;
constexpr int ms = 5e5 + 13;
vector<int> g[ms], mask_times[ms], level_times[ms], accumulated_mask[ms];
int in[ms], out[ms], depth[ms], lvl[ms], timer = 0, n, q;
string s;
void go(int root = 0, int L = 0) {
  lvl[root] = L;
  in[root] = timer++;
  int mask = (1 << (s[root] - 'a'));
  mask_times[L].push_back(mask);
  level_times[L].push_back(in[root]);
  for (const int& x : g[root]) {
    go(x, L + 1);
  }
  out[root] = timer - 1;
}
bool is_good(int v) { return __builtin_popcount(v) <= 1; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> q;
  for (int i = 1; i < n; ++i) {
    int par;
    cin >> par;
    --par;
    g[par].push_back(i);
  }
  cin >> s;
  go();
  for (int l = 0; l < ms; ++l) {
    if (!mask_times[l].empty()) {
      accumulated_mask[l].assign((mask_times[l].size()), 0);
      partial_sum(mask_times[l].begin(), mask_times[l].end(),
                  accumulated_mask[l].begin(),
                  [&](int x, int y) { return x ^ y; });
    }
  }
  for (int i = 0; i < q; ++i) {
    int root, d;
    cin >> root >> d;
    --root;
    --d;
    int st =
        lower_bound(level_times[d].begin(), level_times[d].end(), in[root]) -
        level_times[d].begin();
    int nd =
        upper_bound(level_times[d].begin(), level_times[d].end(), out[root]) -
        level_times[d].begin();
    if (nd == 0) {
      cout << "Yes\n";
      continue;
    }
    int mask = accumulated_mask[d][nd - 1];
    if (st > 0) mask ^= accumulated_mask[d][st - 1];
    if (is_good(mask))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
