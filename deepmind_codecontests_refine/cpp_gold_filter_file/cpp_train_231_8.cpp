#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long a;
    cin >> a;
    if (a == 1) {
      cout << 0 << '\n';
      continue;
    }
    int ans = 0;
    int res = 1;
    while (a > 1) {
      int cnt = 0;
      while (a % 6 != 0 && cnt < 4) {
        a *= 2;
        ans++;
        cnt++;
      }
      if (cnt > 3) {
        res = 0;
        cout << -1 << '\n';
        break;
      } else {
        a /= 6;
        ans++;
      }
    }
    if (res == 1) {
      cout << ans << '\n';
    }
  }
  return 0;
}
