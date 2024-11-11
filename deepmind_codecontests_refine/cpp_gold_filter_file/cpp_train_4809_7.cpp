#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int e = 0; e < t; e++) {
    int n, last = 0, now = 0, ff = 1;
    bool flag = true;
    cin >> n;
    vector<int> arr(n + 1, 0);
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      int q;
      cin >> q;
      if (q != last) {
        if (arr[q] != 0) {
          flag = false;
        } else {
          last = q;
          arr[q] = 1;
          res[now++] = q;
        }
      } else {
        bool tmp = false;
        while (ff <= n && !tmp) {
          if (arr[ff] == 0 && ff < last && !tmp) {
            tmp = true;
            res[now++] = ff;
            arr[ff] = 1;
          }
          ff++;
        }
        if (!tmp) {
          flag = false;
        }
      }
    }
    if (flag) {
      for (int i = 0; i < n; i++) cout << res[i] << ' ';
      cout << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
