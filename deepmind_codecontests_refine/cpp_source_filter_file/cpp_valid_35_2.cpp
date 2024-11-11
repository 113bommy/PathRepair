#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    long long n, m;
    cin >> n >> m;
    if (m + 1 <= n) {
      cout << 0 << endl;
      continue;
    }
    bool flag = false;
    for (int i = 32; i >= 0; --i) {
      int x = n >> i & 1, y = m >> i & 1;
      if (flag) {
        m -= y << i;
        m += x << i;
      } else if (x > y) {
        flag = 1;
        m += (1 << i);
      }
    }
    cout << (n ^ m) << endl;
  }
  return 0;
}
