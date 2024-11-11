#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
const int INF = 0x3f3f3f3f;
void solve() {
  int n, i = 1, p = 1;
  cin >> n;
  while (1) {
    if ((n - i) < 0) {
      if (n <= p) {
        cout << n << " " << p << '\n';
        return;
      } else {
        cout << p << " " << 2 * p - n << '\n';
        return;
      }
    }
    n = n - i;
    i = i + 2;
    p++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
