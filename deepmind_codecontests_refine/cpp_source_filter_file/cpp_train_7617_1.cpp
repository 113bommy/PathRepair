#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return {i, j};
}
struct printer {
  ~printer() { cerr << endl; }
  template <class c>
  printer& operator,(c x) {
    cerr << boolalpha << x;
    return *this;
  }
  printer& operator,(string x) {
    cerr << x;
    return *this;
  }
  template <class c, class d>
  printer& operator,(pair<c, d> x) {
    return *this, "(", x.first, ", ", x.second, ")";
  }
  template <class... d, template <class...> class c>
  printer& operator,(c<d...> x) {
    return *this, range(begin(x), end(x));
  }
  template <class c>
  printer& operator,(rge<c> x) {
    *this, "[";
    for (auto it = x.b; it != x.e; ++it) *this, (it == x.b ? "" : ", "), *it;
    return *this, "]";
  }
};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
const int magic = 120;
vector<vector<int>> all_perm;
bitset<magic> pre[magic][magic];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> m >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) p[i] = i;
  do {
    all_perm.push_back(p);
  } while (next_permutation(p.begin(), p.end()));
  sort(p.begin(), p.end());
  int sz = all_perm.size();
  vector<vector<int>> dp(sz, vector<int>(sz));
  for (int i = 0; i < sz; i++) {
    for (int j = 0; j < sz; j++) {
      auto q = all_perm[i];
      auto apply = all_perm[j];
      for (int k = 0; k < n; k++) {
        q[k] = all_perm[i][apply[k]];
      }
      dp[i][j] =
          lower_bound(all_perm.begin(), all_perm.end(), q) - all_perm.begin();
    }
  }
  for (int i = 0; i < sz; i++) {
    for (int j = 0; j < sz; j++) {
      bitset<magic> found;
      found[0] = true;
      while (true) {
        bool flag = false;
        for (int l = 0; l < sz; l++) {
          if (!found[l]) continue;
          auto t = {i, j};
          for (auto x : t) {
            if (!found[dp[l][x]]) flag = true;
            found[dp[l][x]] = true;
          }
        }
        if (!flag) break;
      }
      pre[i][j] = found;
    }
  }
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    vector<int> q(n);
    for (int j = 0; j < n; j++) {
      cin >> q[j];
      q[j]--;
    }
    a[i] = lower_bound(all_perm.begin(), all_perm.end(), q) - all_perm.begin();
  }
  long long ans = 0;
  vector<vector<int>> last(m, vector<int>(sz, m));
  for (int i = m - 1; i >= 0; i--) {
    int x = a[i];
    bitset<magic> found = pre[x][x];
    int cur = i;
    vector<int> taken = {a[i]};
    while (true) {
      int cnt = 0;
      int close = m;
      for (int j = 0; j < sz; j++) {
        if (found[j] == false) {
          if (cur + 1 < m) close = min(close, last[cur + 1][j]);
        } else {
          cnt++;
        }
      }
      ans += (close - cur) * cnt;
      cur = close;
      if (cur == m) break;
      taken.push_back(cur);
      if (taken.size() <= 2) {
        auto tt = taken;
        while (tt.size() <= 2) tt.push_back(tt.back());
        found = pre[tt[0]][tt[1]];
      } else {
        while (true) {
          bool flag = false;
          for (int l = 0; l < sz; l++) {
            if (!found[l]) continue;
            for (auto x : taken) {
              if (!found[dp[l][x]]) flag = true;
              found[dp[l][x]] = true;
            }
          }
          if (!flag) break;
        }
      }
    }
    if (i + 1 < m) last[i] = last[i + 1];
    last[i][x] = i;
  }
  cout << ans << endl;
}
