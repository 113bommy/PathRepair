#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long t, n, m, ans;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    if (n >= 3) {
      ans = m * 2;
      cout << ans << "\n";
    } else if (n > 1) {
      ans = m;
      cout << ans << "\n";
    } else {
      cout << "0"
           << "\n";
    }
  }
  return 0;
}
