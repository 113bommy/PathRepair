#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int ans = 1e9, M = 1e4 + 5;
  int x, y, z;
  for (int i = 1; i < M; i++) {
    for (int j = i; j < M; j += i) {
      for (int k = j; k < M; k += j) {
        if (abs(a - i) + abs(b - j) + abs(c - k) < ans) {
          ans = abs(a - i) + abs(b - j) + abs(c - k);
          x = i;
          y = j;
          z = k;
        }
      }
    }
  }
  cout << ans << '\n';
  cout << x << ' ' << y << ' ' << z << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
