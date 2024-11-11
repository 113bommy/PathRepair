#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n][n], ans[100005] = {0};
  int res = n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (i != j) {
        if (a[i][j] == 1) {
          if (ans[i] == 0) {
            ans[i] = 1;
            res--;
          }
        } else if (a[i][j] == 2) {
          if (ans[j] == 0) {
            ans[j] = 1;
            res--;
          }
        } else if (a[i][j] == 3) {
          if (ans[j] == 0 && ans[i] == 0) {
            ans[j] = ans[i] = 1;
            res--;
            res--;
          } else if (ans[j] == 1 || ans[i] == 1) {
            ans[j] = ans[i] = 1;
            res--;
          }
        }
      }
    }
  }
  if (res <= 0) {
    cout << "0" << endl;
    return 0;
  }
  cout << res << endl;
  for (int i = 0; i < n; i++) {
    if (ans[i] == 0) cout << i + 1 << " ";
  }
}
