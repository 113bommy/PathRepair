#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    int ans;
    cin >> n;
    if (n == 9) {
      ans = 1;
    } else
      ans = (n + 1) / 10;
    cout << ans << endl;
  }
  return 0;
}
