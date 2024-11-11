#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    int mx = max(max(a, b), c);
    int mn = 0, total = 0;
    total = a / 2 + b / 2 + c / 2;
    if (mx == c && c > a + b + 1) {
      mn = c - a - b - 1;
    }
    if (mx == a && a > c + b + 1) {
      mn = a - c - b - 1;
    }
    if (mx == b && b > c + a + 1) {
      mn = b - c - a - 1;
    }
    if (m >= mn && m <= total)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
