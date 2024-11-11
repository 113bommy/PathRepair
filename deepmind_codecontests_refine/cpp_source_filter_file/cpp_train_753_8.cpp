#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    long long a[n];
    long long mx = -INT_MAX;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mx = max(mx, a[i]);
    }
    vector<long long> f, s;
    long long mx2 = -INT_MAX;
    for (int i = 0; i < n; i++) {
      f.push_back(mx - a[i]);
    }
    for (int i = 0; i < n; i++) {
      mx2 = max(mx2, f[i]);
    }
    for (int i = 0; i < n; i++) {
      s.push_back(mx2 - f[i]);
    }
    if (m & 1) {
      for (auto x : f) cout << x << " ";
    } else {
      for (auto x : s) cout << x << " ";
    }
    cout << endl;
  }
}
