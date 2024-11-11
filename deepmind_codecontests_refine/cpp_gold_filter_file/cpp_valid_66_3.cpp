#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int k, ans = 0;
    cin >> k;
    for (int i = 1; i <= k; i++) {
      ans++;
      while (ans % 3 == 0 || ans % 10 == 3) ans++;
    }
    cout << ans << "\n";
  }
}
