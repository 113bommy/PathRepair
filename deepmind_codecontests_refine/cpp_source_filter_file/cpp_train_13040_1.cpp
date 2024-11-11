#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int i, a[n], b[n], mina = 10000000000, minb = 10000000000,
                                 ans = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      mina = min(mina, a[i]);
    }
    for (i = 0; i < n; i++) {
      cin >> b[i];
      minb = min(minb, b[i]);
    }
    for (i = 0; i < n; i++) {
      if (a[i] == mina && b[i] == minb)
        continue;
      else if (a[i] == mina && b[i] != minb) {
        ans += b[i] - minb;
      } else if (b[i] == minb && a[i] != mina) {
        ans += a[i] - mina;
      } else {
        long long int x = a[i] - mina;
        long long int y = b[i] - minb;
        ans += min(x, y);
        a[i] -= min(x, y);
        b[i] -= min(x, y);
        if (a[i] - mina > 1) {
          ans += a[i] - mina;
        } else {
          ans += b[i] - minb;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
