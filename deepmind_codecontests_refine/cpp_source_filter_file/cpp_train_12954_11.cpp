#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (k == 0) {
    if (n == 1)
      cout << 1 << '\n';
    else
      cout << -1 << '\n';
  } else if (n == 1)
    cout << -1 << '\n';
  else {
    int n1 = n / 2;
    if (k < n1)
      cout << -1 << '\n';
    else {
      vector<int> ans;
      int k1 = k - (n1 - 1);
      ans.push_back(k1);
      ans.push_back(k1 * 2);
      --n1;
      int id;
      for (int i = 1; n1;) {
        if (i == k1 || i == (k1 * 2) || i + 1 == k1 || i + 1 == (k1 * 2))
          ++i;
        else {
          ans.push_back(i);
          ans.push_back(i + 1);
          i += 2;
          --n1;
          id = i;
        }
      }
      if (n & 1) {
        while (id == k1 || id == (k1 * 2)) ++id;
        ans.push_back(id);
      }
      cout << ans[0];
      for (int i = 1; i < n; ++i) cout << ' ' << ans[i];
      cout << '\n';
    }
  }
  return 0;
}
