#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<pair<long long int, long long int> > v;
  long long int x;
  cin >> x;
  long long int d;
  long long int u;
  for (long long int n = 1; n <= min(x, 5000000LL); n++) {
    d = n * n - ((n - 1) * n) / 2;
    u = x + (n * n * (n - 1)) / 2 - (n * (n - 1) * (2 * n - 1)) / 6;
    if (u % d == 0) {
      u /= d;
      if (u >= n) {
        v.push_back({n, u});
        if (u != n) v.push_back({u, n});
      }
    }
  }
  cout << v.size() << "\n";
  sort(v.begin(), v.end());
  for (auto x : v) {
    cout << x.first << " " << x.second << "\n";
  }
}
