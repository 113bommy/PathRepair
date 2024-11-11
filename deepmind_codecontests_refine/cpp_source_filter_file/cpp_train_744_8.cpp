#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int q;
  cin >> q;
  while (q--) {
    int n, i, j, w = 0, k;
    cin >> n;
    vector<int> a(n), b;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 1 || b.size()) b.push_back(a[i]);
    }
    if (n == 1) {
      cout << "YES" << endl;
      continue;
    }
    for (i = 0; b.size() < n; i++) b.push_back(a[i]);
    if (b[1] != n && b[1] != 2) {
      cout << "NO" << endl;
      continue;
    }
    if (b[1] == 2) {
      for (i = 2; i < n - 1; i++) {
        if (b[i + 1] - b[i] != 1) break;
      }
      if (i == n - 1)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
      continue;
    } else {
      for (i = n - 1; i > 0; i--) {
        if (b[i - 1] - b[i] != 1) break;
      }
      if (i <= 1)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
