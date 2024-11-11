#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    string ans = "";
    cin >> n;
    int x = n / 2;
    int y = n % 2;
    while (x--) {
      ans += '1';
      n -= 2;
    }
    if (y == 1)
      ans[0] = '7', cout << ans << "\n";
    else
      cout << ans << "\n";
  }
  return 0;
}
