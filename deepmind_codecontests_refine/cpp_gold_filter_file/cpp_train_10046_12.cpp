#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  if (a == 0 && c == n) {
    cout << n + min(d + b, (n + n - d - b));
    return;
  }
  if (a == n && c == 0) {
    cout << n + min(d + b, (n + n - d - b));
    return;
  }
  if (b == 0 && d == n) {
    cout << n + min(a + c, (n + n - a - c));
    return;
  }
  if (b == n && d == 0) {
    cout << n + min(a + c, (n + n - a - c));
    return;
  }
  cout << abs(a - c) + abs(b - d);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
