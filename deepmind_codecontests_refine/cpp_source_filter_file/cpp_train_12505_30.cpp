#include <bits/stdc++.h>
using ll = long long;
constexpr ll MOD = 1000000007;
using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::map;
using std::multimap;
using std::multiset;
using std::pair;
using std::queue;
using std::set;
using std::sort;
using std::stack;
using std::string;
using std::unordered_map;
using std::unordered_multimap;
using std::unordered_set;
using std::vector;
int main() {
  ll x;
  cin >> x;
  for (ll n = (ll)(1); n < (ll)(x); ++n) {
    for (ll b = (ll)(1); b < (ll)(x); ++b) {
      if (n * b * b > x) {
        cout << n * b << " " << b << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}
