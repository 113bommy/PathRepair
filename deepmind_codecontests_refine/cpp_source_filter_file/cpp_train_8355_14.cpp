#include <bits/stdc++.h>
using namespace std;
typedef map<int, int> mp;
void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  int t = 0;
  bool c = 0, b = 0;
  for (int i = 1; i <= 200; i++) {
    t = i / n;
    for (int j = 1; j <= x; j++) {
      b = 0, c = 0;
      for (int r = j; r < j + n * t; r += t) {
        if (r == x) b = 1;
        if (r == y) c = 1;
      }
      if (b && c) {
        for (int i = 0; i < n; i++) {
          cout << (j + t * i) << " ";
        }
        cout << "\n";
        return;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
