#include <bits/stdc++.h>
using namespace std;
set<int> buy, sell, extra;
int main() {
  int n, ans = 1, p, m;
  cin >> n;
  string s;
  while (n--) {
    cin >> s >> p;
    if (s == "ACCEPT") {
      if (extra.find(p) != extra.end()) {
        for (auto it : extra) {
          if (it < p)
            buy.insert(it);
          else if (it > p)
            sell.insert(it);
        }
        ans = (ans + ans) % 1000000007;
        extra.clear();
      } else if (buy.find(p) != buy.end()) {
        auto it = buy.end();
        it--;
        if (*it != p) ans = 0;
        it = buy.find(p);
        buy.erase(it);
        for (auto it : extra) {
          sell.insert(it);
        }
        extra.clear();
      } else {
        auto it = sell.find(p);
        assert(it != sell.end());
        if (it != sell.begin()) ans = 0;
        sell.erase(it);
        for (auto it : extra) {
          buy.insert(it);
        }
        extra.clear();
      }
    } else {
      if (buy.empty()) {
        if (sell.empty()) {
          extra.insert(p);
        } else {
          auto it = sell.begin();
          if (p > *it)
            sell.insert(p);
          else
            extra.insert(p);
        }
      } else {
        auto it = buy.end();
        it--;
        if (sell.empty()) {
          if (p < *it)
            buy.insert(p);
          else
            extra.insert(p);
        } else {
          auto jt = sell.begin();
          if (p > *it && p < *jt)
            extra.insert(p);
          else if (p < *it)
            buy.insert(p);
          else
            sell.insert(p);
        }
      }
    }
  }
  long long int res = ((ans * 1LL) * (extra.size() + 1)) % 1000000007;
  cout << res << '\n';
  return 0;
}
