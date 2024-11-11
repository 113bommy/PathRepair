#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, t;
  double pi = 3.1415926535897932;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n % 2)
      cout << setprecision(16) << fixed << cos(pi / (2 * n)) / sin(pi / (4 * n))
           << '\n';
    else
      cout << setprecision(16) << fixed << 1 / tan(pi / (n * 2)) << '\n';
  }
}
