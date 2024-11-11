#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[105][105];
  cin >> n;
  int ans[105] = {0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 1) {
        ans[i + 1] = 1;
      }
      if (a[i][j] == 2) {
        ans[j + 1] = 1;
      }
      if (a[i][j] == 3) {
        ans[i + 1] = 1;
        ans[j + 1] = 1;
      }
    }
  }
  int safe = 0;
  for (int i = 1; i <= n; i++) {
    if (ans[i] == 0) safe++;
  }
  cout << safe << endl;
  for (int i = 1; i <= n; i++) {
    if (ans[i] == 0) cout << i << " ";
  }
}
