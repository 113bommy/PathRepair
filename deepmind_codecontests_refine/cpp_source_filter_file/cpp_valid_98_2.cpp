#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t, i, j, n, s, k;
  int a[50];
  bool ans;
  char x;
  cin >> t;
  for (j = 0; j < t; j++) {
    s = 0;
    ans = false;
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> x;
      if (x == 'a')
        s += 1;
      else
        s -= 1;
      if (s == 0) {
        cout << 1 << " " << i + 1 << "\n";
        ans = true;
        for (k = i + 1; k < n; k++) cin >> x;
        break;
      }
      a[i] = s;
    }
    if (!ans)
      for (i = 0; i < n - 1; i++) {
        for (k = i + 1; k < n; k++)
          if (a[k] == a[i]) {
            cout << i + 1 << " " << k << "\n";
            ans = true;
            break;
          }
        if (ans) break;
      }
    if (!ans) cout << -1 << " " << -1 << "\n";
  }
  return 0;
}
