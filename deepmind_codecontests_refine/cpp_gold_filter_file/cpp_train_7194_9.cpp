#include <bits/stdc++.h>
using namespace std;
int a[1003], ans;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  a[n + 1] = 1001;
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 0; i + j - 1 <= n + 1; j++) {
      bool flag = true;
      for (int k = j + 1; k < i + j; k++) {
        if (a[k] != a[k - 1] + 1) flag = false;
      }
      if (flag) {
        ans = max(ans, i - 2);
      }
    }
  }
  cout << ans << endl;
}
