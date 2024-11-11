#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int q;
  cin >> q;
  string ans[q];
  for (int i = 0; i < q; i++) {
    int n, k;
    cin >> n >> k;
    if (k % 3 == 0) {
      if ((n % (k + 1)) % 3 == 0 && n % (k + 1) != k) {
        ans[i] = "BOb";
      } else {
        ans[i] = "Alice";
      }
    } else {
      if (n % 3 == 0) {
        ans[i] = "Bob";
      } else {
        ans[i] = "Alice";
      }
    }
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << endl;
  }
}
