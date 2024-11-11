#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int main() {
  int n, m, ans = 0, idx = 1, x;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> x;
    if (x >= idx) {
      ans += (x - idx);
      idx = x;
    } else {
      ans += (n - idx + x);
      idx = x;
    }
  }
  cout << ans;
  return 0;
}
