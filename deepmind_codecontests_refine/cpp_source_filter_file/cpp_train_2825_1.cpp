#include <bits/stdc++.h>
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (x < y) x = y;
}
using namespace std;
void solve() {
  int n, i, a, b = 0, x, y;
  x = y = 1e6;
  cin >> n;
  while (n - 7 * b >= 0) {
    if ((n - 7 * b) % 4 == 0) {
      a = (n - 7 * b) / 4;
      if (x + y > a + b) {
        x = a;
        y = b;
      }
    }
    b++;
  }
  if (x == INT_MAX)
    cout << -1;
  else {
    for (i = 0; i < x; i++) cout << 4;
    for (i = 0; i < y; i++) cout << 7;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
