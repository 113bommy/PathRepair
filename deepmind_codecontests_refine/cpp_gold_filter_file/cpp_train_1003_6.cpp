#include <bits/stdc++.h>
using namespace std;
signed main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i != 0) {
      if (abs(a[i] - a[i - 1]) >= 2) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
  return 0;
}
