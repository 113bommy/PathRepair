#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const long long LL_INF = 1ll * INF * INF;
const int MAX_N = 500000 + 7;
const int mod = INF;
template <typename T>
inline void addmod(T& a, const long long& b, const int& MOD = mod) {
  a = (a + b) % MOD;
  if (a < 0) a += MOD;
}
int n;
set<int> not_sure;
set<int> sell, buy;
void add(set<int>& a, set<int>& b) {
  while (!b.empty()) {
    int u = *b.begin();
    b.erase(u);
    a.insert(u);
  }
}
void solve() {
  cin >> n;
  long long ans = 1;
  for (int i = 0; i < n; ++i) {
    string s;
    int u;
    cin >> s >> u;
    if (s[1] == 'D') {
      if (!buy.empty() && u < *buy.rbegin())
        buy.insert(u);
      else if (!sell.empty() && u > *sell.begin())
        sell.insert(u);
      else
        not_sure.insert(u);
    } else {
      if (buy.count(u)) {
        if (u != *buy.rbegin()) {
          cout << 0;
          return;
        }
        buy.erase(u);
        add(sell, not_sure);
      } else if (sell.count(u)) {
        if (u != *sell.begin()) {
          cout << 0;
          return;
        }
        sell.erase(u);
        add(buy, not_sure);
      } else {
        assert(not_sure.count(u));
        ans = ans * 2 % INF;
        for (auto p : not_sure) {
          if (p < u)
            buy.insert(p);
          else if (p > u)
            sell.insert(p);
        }
        not_sure.clear();
      }
    }
  }
  ans = ans * (not_sure.size() + 1) % INF;
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  const bool multiple_test = false;
  int test = 1;
  if (multiple_test) cin >> test;
  for (int i = 0; i < test; ++i) {
    solve();
  }
}
