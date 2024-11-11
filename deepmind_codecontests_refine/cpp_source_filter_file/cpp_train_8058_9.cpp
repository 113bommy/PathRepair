#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n, m;
  cin >> n >> m;
  long long a[n], l[n];
  map<long long, long long> x;
  set<long long> y;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    x[a[i]] += x[a[i]];
    y.insert(a[i]);
  }
  for (long long i = 0; i < n; i++) {
    l[i] = y.size();
    long long s = x[a[i]];
    if (s == 1) {
      x[a[i]]--;
      y.erase(a[i]);
    } else {
      x[a[i]]--;
    }
  }
  for (long long i = 0; i < m; i++) {
    long long t;
    cin >> t;
    cout << l[t - 1] << "\n";
  }
}
