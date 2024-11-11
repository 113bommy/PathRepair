#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    bool use_1 = 2 * x < y ? 1 : 0;
    long long int ans = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        if (s[j] == '.') {
          count++;
        } else {
          if (count > 1) {
            if (use_1)
              ans += x * count;
            else {
              ans += y * count / 2 + x * count % 2;
            }
          } else {
            ans += count * x;
          }
          count = 0;
        }
      }
      if (count > 1) {
        if (use_1)
          ans += x * count;
        else {
          ans += y * count / 2 + x * count % 2;
        }
      } else {
        ans += count * x;
      }
      count = 0;
    }
    cout << ans << endl;
  }
  return 0;
}
