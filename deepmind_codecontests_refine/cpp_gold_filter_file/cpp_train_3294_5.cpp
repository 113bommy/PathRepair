#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int a[k];
    for (int i = 0; i < k; i++) cin >> a[i];
    sort(a, a + k);
    int ans = 0;
    ans = a[0];
    ans = max(ans, n - a[k - 1] + 1);
    for (int i = 0; i < k - 1; i++) {
      int x = a[i + 1] - a[i];
      x = x / 2;
      x++;
      ans = max(ans, x);
    }
    cout << ans << endl;
  }
}
