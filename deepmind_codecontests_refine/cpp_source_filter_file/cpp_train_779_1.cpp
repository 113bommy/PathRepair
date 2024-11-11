#include <bits/stdc++.h>
using namespace std;
template <typename T_key, typename T_value, bool maximum_mode = false>
struct online_prefix_max {
  map<T_key, T_value> optimal;
  bool better(T_value a, T_value b) { return (a < b) ^ maximum_mode; }
  pair<T_key, T_value> query(T_key key_limit) const {
    auto it = optimal.lower_bound(key_limit);
    if (it == optimal.begin()) return {0, -1};
    it--;
    return *it;
  }
  void insert(T_key key, T_value value) {
    auto it = optimal.lower_bound(key);
    if (it != optimal.end() && it->first == key) {
      if (!better(value, it->second)) return;
    } else if (it != optimal.begin()) {
      auto prev_it = it;
      prev_it--;
      if (!better(value, prev_it->second)) return;
    }
    while (it != optimal.end() && !better(it->second, value))
      it = optimal.erase(it);
    optimal.insert(it, {key, value});
  }
};
int main() {
  int n, i, j, t;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  online_prefix_max<long long int, int> ds;
  map<pair<int, long long int>, pair<int, int> > mp;
  long long int l, r;
  cin >> n >> t;
  for (i = 0; i < n; i++) {
    cin >> l >> r;
    r += l;
    mp[{l, r}] = {i, 0};
    ds.insert(-r, l);
  }
  int pos, siz;
  pair<long long int, int> p;
  set<pair<int, int> > not_eaten;
  while (t--) {
    cin >> pos >> siz;
    p = ds.query(-pos + 1);
    if (p.second == -1 || p.second > pos) {
      not_eaten.insert({pos, siz});
    } else {
      l = p.second;
      r = -p.first;
      pair<int, int> val = mp[{l, r}];
      mp.erase({l, r});
      r += siz;
      val.second++;
      while (1) {
        auto it = not_eaten.lower_bound({l, -1});
        if (it == not_eaten.end() || it->first > r) break;
        r += it->second;
        val.second++;
        not_eaten.erase(it);
      }
      ds.insert(-r, l);
      mp[{l, r}] = val;
    }
  }
  pair<int, int> ans[n];
  for (auto &z : mp) {
    ans[z.second.first] = {z.second.second, z.first.second - z.first.first};
  }
  for (i = 0; i < n; i++) cout << ans[i].first << " " << ans[i].second << '\n';
  return 0;
}
