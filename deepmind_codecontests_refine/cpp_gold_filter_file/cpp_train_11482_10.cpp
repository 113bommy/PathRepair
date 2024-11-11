#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long idx = -1;
    vector<pair<long long, long long>> res;
    for (long long i = 0; i < n; i++) {
      if (a[i] != a[0]) {
        idx = i;
        res.push_back({1, i + 1});
      }
    }
    if (idx == -1) {
      cout << "No" << endl;
      continue;
    }
    for (long long i = 1; i < n; i++) {
      if (a[i] == a[0]) {
        res.push_back({idx + 1, i + 1});
      }
    }
    cout << "Yes" << endl;
    for (auto x : res) {
      cout << x.first << " " << x.second << endl;
    }
  }
}
