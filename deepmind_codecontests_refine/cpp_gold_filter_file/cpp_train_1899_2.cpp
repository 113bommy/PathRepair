#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int d, m;
    cin >> d >> m;
    long long ans = 1;
    for (int i = 0; i < 30; i++) {
      if (d < (1 << i)) break;
      ans = ans * (min((1 << (i + 1)) - 1, d) - (1 << i) + 2) % m;
    }
    ans--;
    if (ans < 0) ans += m;
    cout << ans << endl;
  }
  return 0;
}
