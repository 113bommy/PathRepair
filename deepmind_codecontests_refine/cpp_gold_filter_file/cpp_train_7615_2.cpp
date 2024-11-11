#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  long long a, ans, mod;
  cin >> T;
  while (T--) {
    ans = 0;
    cin >> a >> mod;
    while (a) {
      if (a % mod != 0) ans += (a % mod);
      if (a >= mod) ans++;
      a /= mod;
    }
    cout << ans << endl;
  }
  return 0;
}
