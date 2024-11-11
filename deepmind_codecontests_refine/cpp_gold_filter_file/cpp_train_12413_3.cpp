#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc, n, a;
  cin >> tc;
  while (tc--) {
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
      cin >> a;
      m[a]++;
    }
    if (n == 1) {
      cout << 0 << endl;
    } else if (m.size() == n) {
      cout << 1 << endl;
    } else {
      int mx = 0;
      for (auto i : m) {
        if (i.second > mx) {
          mx = i.second;
        }
      }
      int x = m.size() - 1;
      int res = min(x, mx);
      if (res + 1 <= mx - 1) {
        cout << res + 1 << endl;
      } else {
        cout << res << endl;
      }
    }
  }
}
