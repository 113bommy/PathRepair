#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, maxi = 0, ans = 0, k;
    cin >> n;
    int a[n], b[2000] = {0};
    memset(b, 0, sizeof(b));
    map<int, int> m;
    for (auto i = 0; i < n; i++) {
      cin >> a[i];
      m[a[i]]++;
      maxi = max(maxi, a[i]);
    }
    for (auto i = 1; i <= maxi * 2; i++) {
      ans = i;
      for (auto j = 0; j < n; j++) {
        k = a[j] ^ i;
        if (m[k] != 0 && b[k] + 1 <= m[k])
          b[k]++;
        else {
          ans = 0;
          break;
        }
      }
      if (ans) break;
      memset(b, 0, sizeof(b));
    }
    if (ans)
      cout << ans << endl;
    else
      cout << -1 << endl;
  }
}
