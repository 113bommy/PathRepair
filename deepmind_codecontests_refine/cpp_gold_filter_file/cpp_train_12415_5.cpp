#include <bits/stdc++.h>
using namespace std;
int arr[10009], frk[10009] = {};
vector<int> ans;
int main() {
  int t, n, i, j, cnt = 0, num, op;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 0; i < n; i++) cin >> arr[i];
    ans.clear();
    num = -1, op = -1;
    while (1) {
      for (i = 0; i < n; i++) {
        if (arr[i] != i && num == -1) num = i;
        frk[arr[i]] = 1;
      }
      if (num == -1) {
        for (i = 0; i <= n; i++) frk[i] = 0;
        cout << ans.size() << endl;
        for (i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
        break;
      } else {
        for (i = 0; i <= n; i++) {
          if (frk[i] == 0 && op == -1) op = i;
          frk[i] = 0;
        }
        if (op == n) {
          arr[num] = op;
          ans.push_back(num + 1);
        } else {
          arr[op] = op;
          ans.push_back(op + 1);
        }
        op = -1;
        num = -1;
      }
    }
  }
  return 0;
}
