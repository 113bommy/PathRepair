#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  int ans = 13;
  for (int i = 3; i <= n; i++) {
    ans += (2 * (i - 1) - 1) * 6 + 6;
  }
  cout << ans << endl;
}
