#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, i, j, k, f = 0;
  vector<int> a;
  cin >> t;
  for (i = 0; i < t; i++) {
    f = 0;
    cin >> n;
    for (j = 0; j < n; j++) {
      cin >> k;
      a.push_back(k);
    }
    int mi = *min_element(a.begin(), a.end());
    for (j = 0; j < n; j++) {
      a[j] -= mi;
      if (a[j] % 2 != 0) {
        f = 1;
        break;
      }
    }
    if (f == 1) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
    a.clear();
  }
  return 0;
}
