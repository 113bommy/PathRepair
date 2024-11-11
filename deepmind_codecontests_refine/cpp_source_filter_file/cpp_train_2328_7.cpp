#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long int n, m, v;
  cin >> n >> m >> v;
  long long int y = (n * (n + 1)) / 2;
  y -= (n - 2);
  if (m > y || m < (n - 1)) {
    cout << -1;
    return 0;
  }
  long long int x = 1;
  vector<long long int> b;
  for (long long int i = 0; i < n - 1; i++) {
    if (x == v) x += 1;
    cout << v << " " << x << "\n";
    if (i != (n - 2)) b.push_back(x);
    x += 1;
  }
  m -= (n - 1);
  for (long long int j = 0; j < b.size(); j++) {
    for (long long int k = j + 1; k < b.size(); k++) {
      if (m == 0) break;
      cout << b[j] << " " << b[k] << "\n";
      m--;
    }
    if (m == 0) return 0;
  }
}
