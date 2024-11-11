#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    int c = 0;
    cin >> n;
    vector<int> v(n), v1(n);
    set<int> s;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
      cin >> v1[i];
      s.insert(v1[i]);
    }
    bool ok = ((int)s.size() == 2 || is_sorted(v.begin(), v.end()));
    cout << (ok ? "Yes" : "No") << endl;
  }
  return 0;
}
