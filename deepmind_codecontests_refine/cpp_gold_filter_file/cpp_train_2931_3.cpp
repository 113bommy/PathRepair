#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = -1;
    for (int i = 0; i < 9; i++) {
      vector<int> v[2];
      for (int j = 0; j < n; j++) {
        v[j >> i & 1].push_back(j + 1);
      }
      if (v[1].empty()) break;
      cout << v[0].size() << ' ' << v[1].size();
      for (int i = 0; i < v[0].size(); i++) cout << ' ' << v[0][i];
      for (int i = 0; i < v[1].size(); i++) cout << ' ' << v[1][i];
      cout << endl;
      int x;
      cin >> x;
      ans = max(ans, x);
    }
    cout << -1 << ' ' << ans << endl;
  }
  return 0;
}
