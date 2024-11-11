#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> v;
    long long int m = INT_MAX;
    for (long long int i = 0; i < n; i++) {
      long long int x;
      cin >> x;
      v.push_back(x);
      m = min(m, x);
    }
    n = n / 2;
    for (long long int i = 0, j = 0; i < n; i++) {
      if (m == v[j]) j++;
      cout << m << " " << v[j] << "\n";
      j++;
    }
  }
}
