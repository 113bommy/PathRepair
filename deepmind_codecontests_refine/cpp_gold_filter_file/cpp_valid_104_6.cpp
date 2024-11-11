#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    vector<int> ans;
    bool flag = true;
    for (int i = 0; i < n;) {
      if (x[i] == 0) {
        ++i;
        continue;
      }
      int j = i;
      while (j < n && x[j] == 1) ++j;
      while ((j - i) & 1) {
        int oj = j;
        while (j + 1 < n && x[j] == 0 && x[j + 1] == 0) {
          ans.push_back(j);
          x[j] = x[j + 1] = 1;
          j += 2;
        }
        while (j < n && x[j] == 1) ++j;
        if (oj == j) break;
      }
      if ((j - i) & 1) {
        if (j == n || j + 1 == n) {
          flag = false;
          break;
        }
        x[j + 1] = 0;
        for (int k = j - 1; k >= i; k -= 2) {
          ans.push_back(k + 1);
        }
      } else {
        if (i > 0) {
          for (int k = i; k < j; k += 2) {
            ans.push_back(k);
          }
        } else if (j < n) {
          for (int k = j - 2; k >= i; k -= 2) {
            ans.push_back(k + 1);
          }
        } else {
          flag = false;
          break;
        }
      }
      i = j;
    }
    if (flag) {
      cout << "YES\n";
      cout << ans.size() << "\n";
      for (int i : ans) cout << i << " ";
      cout << "\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
