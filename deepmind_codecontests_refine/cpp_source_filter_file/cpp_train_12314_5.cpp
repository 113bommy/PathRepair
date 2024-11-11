#include <bits/stdc++.h>
using namespace std;
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    set<int> a;
    bool bo = 1;
    for (int i = 0; i < n; i++) {
      if (a.count(b[i])) {
        bo = 0;
      }
      a.insert(b[i]);
    }
    if (bo) {
      cout << "YES\n";
      continue;
    }
    cout << "NO\n";
  }
}
