#include <bits/stdc++.h>
using namespace std;
long long int n, m, x, p, k;
set<pair<long long int, long long int> > v;
map<long long int, long long int> w;
int main() {
  ios::sync_with_stdio(false);
  cin >> x;
  for (long long int k = 1;; k++) {
    if ((6 * x - k * (k - 1) * (2 * k - 1) + 3 * k * k * (k - 1)) %
            (3 * k * (k + 1)) ==
        0) {
      m = (6 * x - k * (k - 1) * (2 * k - 1) + 3 * k * k * (k - 1)) /
          (3 * k * (k + 1));
      if (k <= m) {
        v.insert({k, m});
        v.insert({m, k});
      }
    }
    if (k * k * k >= 2 * x) break;
  }
  cout << v.size() << endl;
  for (auto i : v) cout << i.first << " " << i.second << endl;
  return 0;
}
