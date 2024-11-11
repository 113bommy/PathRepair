#include <bits/stdc++.h>
using namespace std;
struct order {
  long long p;
  long long q;
};
bool comp(order a, order b) { return a.p < b.p; }
int32_t main() {
  long long n, s;
  cin >> n >> s;
  map<long long, long long> Buy, Sell;
  char ch;
  long long p, q;
  for (long long i = 0; i < n; i++) {
    cin >> ch >> p >> q;
    if (ch == 'B') {
      Buy[p] += q;
    } else {
      Sell[p] += q;
    }
  }
  while (Sell.size() > s) {
    Sell.erase(--Sell.end());
  }
  for (auto it = Sell.rbegin(); it != Sell.rend(); it++) {
    cout << 'S' << ' ' << it->first;
    cout << ' ' << it->second << "\n";
  }
  while (Buy.size() > s) {
    Buy.erase(Buy.begin());
  }
  for (auto it = Buy.rbegin(); it != Buy.rend(); it++) {
    cout << 'B' << ' ' << it->first;
    cout << ' ' << it->second << "\n";
  }
  return 0;
}
