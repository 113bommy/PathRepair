#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) a[i] = 299;
    int ans = -1;
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      x--;
      for (int l = 0; l < n; l++) {
        if (a[l] == 299)
          a[l] = abs(l - x + 1);
        else
          a[l] = min(a[l], abs(l - x + 1));
      }
    }
    for (int l = 0; l < n; l++) ans = max(ans, a[l]);
    cout << ans << endl;
  }
}
