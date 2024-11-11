#include <bits/stdc++.h>
using namespace std;
int main() {
  int test_case;
  test_case = 1;
  while (test_case--) {
    long long int n, m, ans = -1;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      long long int r = 999999999999;
      for (int j = 0; j < m; j++) {
        long long int t;
        cin >> t;
        r = min(r, t);
      }
      ans = max(ans, r);
    }
    cout << ans << endl;
  }
  return 0;
}
