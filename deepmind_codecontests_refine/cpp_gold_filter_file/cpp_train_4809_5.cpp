#include <bits/stdc++.h>
using namespace std;
signed main() {
  int t;
  cin >> t;
  for (int q = 0; q < t; q++) {
    int n;
    cin >> n;
    vector<int> lst, used;
    used.assign(n + 3, 0);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      lst.push_back(x);
    }
    int k = 1;
    used[lst[0]] = 1;
    int bl = 1;
    vector<int> ans = {lst[0]};
    for (int i = 1; i < n; i++) {
      if (!bl) break;
      while (used[k]) k++;
      if (!used[lst[i]]) {
        ans.push_back(lst[i]);
        used[lst[i]] = 1;
      } else {
        if (k > n || k > lst[i]) {
          bl = 0;
          break;
        }
        used[k] = 1;
        ans.push_back(k);
      }
    }
    if (bl) {
      for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
      }
      cout << '\n';
    } else {
      cout << -1 << "\n";
    }
  }
  return 0;
}
