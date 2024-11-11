#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<string> > ans;
  string a, num;
  int t;
  for (int i = 0; i < n; i++) {
    int q = 0;
    cin >> a;
    cin >> t;
    int k;
    for (k = 0; k < ans.size(); k++) {
      if (a == ans[k][0]) {
        q = 1;
        break;
      }
    }
    if (q == 0) {
      vector<string> bb;
      bb.push_back(a);
      ans.push_back(bb);
    }
    for (int j = 0; j < t; j++) {
      cin >> num;
      int zz = 0;
      for (int q = 1; q < ans[k].size(); q++) {
        for (int ww = 0; ww < ans[k][q].size(); ww++) {
          if (num == ans[k][q].substr(ww, ans[k][q].size() - ww)) {
            zz = 1;
            break;
          }
        }
        if (zz != 0) {
          for (int ww = 0; ww < num.size(); ww++) {
            if (ans[k][q] == num.substr(ww, num.size() - ww)) {
              ans[k][q] = num;
              zz = 1;
              break;
            }
          }
        }
      }
      if (zz == 0) ans[k].push_back(num);
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i][0] << ' ' << ans[i].size() - 1 << ' ';
    for (int j = 1; j < ans[i].size(); j++) {
      cout << ans[i][j] << ' ';
    }
    cout << endl;
  }
}
