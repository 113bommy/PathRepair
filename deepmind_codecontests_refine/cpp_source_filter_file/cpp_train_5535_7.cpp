#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, m;
  cin >> T >> m;
  for (int i = 0; i < T; i++) {
    int s, e, t;
    cin >> s >> e >> t;
    if (m == 1) {
      cout << 0 << endl;
      continue;
    }
    if (s == e) {
      cout << 0 << endl;
      continue;
    }
    int ans = 0;
    if (s < e) {
      int mod = t % (2 * m - 2);
      ans = 0;
      ans = e - s + (2 * m - 3 - mod + s) % (2 * m - 2);
    } else if (s > e) {
      int mod = t % (2 * m - 2);
      ans = 0;
      ans = s - e + (2 * m - 3 - mod + 2 * m - s) % (2 * m - 2);
    } else {
      int mod = t % (2 * m - 2);
      ans = 0;
      int s2 = 2 * m - 1 - s;
      if (mod == 2 * m - 1 - s || mod == s - 1) {
        ans = 0;
      } else {
        ans = min((2 * m - 3 - mod + s) % (2 * m - 2),
                  (2 * m - 3 - mod + s2) % (2 * m - 2));
      }
    }
    cout << t + ans << endl;
  }
  return 0;
}
