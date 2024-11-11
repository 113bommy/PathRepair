#include <bits/stdc++.h>
using namespace std;
long long n, x;
map<long long, long long> l;
int main() {
  cin >> n;
  set<long long> stax;
  cin >> x;
  stax.insert(x);
  for (int i = 1; i < n; i++) {
    cin >> x;
    auto et = stax.upper_bound(x);
    if (et == stax.end()) {
      et--;
      cout << *et << ' ';
    } else if (l[*et] == 0) {
      l[*et] = 1;
      cout << *et << ' ';
    } else {
      cout << *et << ' ';
    }
    stax.insert(x);
  }
  return 0;
}
