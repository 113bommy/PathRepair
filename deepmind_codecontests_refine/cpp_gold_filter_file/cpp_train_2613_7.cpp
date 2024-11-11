#include <bits/stdc++.h>
using namespace std;
pair<int, int> solve() {
  int n;
  cin >> n;
  deque<pair<int, int64_t> > adds, accepts;
  {
    string action;
    for (int i = 0; i < n; ++i) {
      cin >> action;
      int64_t price;
      cin >> price;
      if (action == "ADD") {
        adds.emplace_back(i, price);
      } else {
        accepts.emplace_back(i, price);
      }
    }
  }
  adds.emplace_back(n, -1);
  accepts.emplace_back(n, -1);
  set<int64_t> active_sells;
  set<int64_t> active_buys;
  int freedom = 0;
  int after_free = 0;
  while (adds.front().first != n || accepts.front().first != n) {
    if (adds.front().first < accepts.front().first) {
      int64_t price = adds.front().second;
      if (!active_buys.empty() && price <= *active_buys.rbegin()) {
        active_buys.emplace(price);
      } else if (!active_sells.empty() && price >= *active_sells.begin()) {
        active_sells.emplace(price);
      } else if (accepts.front().first == n) {
        ++after_free;
      } else {
        int64_t split = accepts.front().second;
        if (price > split) {
          active_sells.emplace(price);
        } else if (price < split) {
          active_buys.emplace(price);
        }
      }
      adds.pop_front();
    } else {
      int64_t price = accepts.front().second;
      if (!active_buys.empty() && price == *active_buys.rbegin()) {
        active_buys.erase(price);
      } else if (!active_sells.empty() && price == *active_sells.begin()) {
        active_sells.erase(price);
      } else if ((active_sells.empty() || price < *active_sells.begin()) &&
                 (active_buys.empty() || price > *active_buys.rbegin())) {
        ++freedom;
      } else {
        return {-1, 0};
      }
      accepts.pop_front();
    }
    assert(active_buys.empty() || active_sells.empty() ||
           *active_buys.rbegin() < *active_sells.begin());
  }
  return {freedom, after_free};
}
const uint32_t mod = 1e9 + 7;
uint32_t powm(uint32_t base, uint32_t exp) {
  uint32_t res = 1;
  for (; exp; exp >>= 1, base = (uint64_t)base * base % mod)
    if (exp & 1) res = (uint64_t)res * base % mod;
  return res;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  auto [ans, mul] = solve();
  if (ans == -1)
    cout << "0\n";
  else
    cout << powm(2, ans) * (int64_t)(mul + 1) % mod << '\n';
}
