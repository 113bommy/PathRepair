#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b, x, y, ans = 0;
  cin >> t;
  while (t > 0) {
    long long int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    cin >> a;
    cin >> b;
    cin >> x;
    cin >> y;
    c1 = b * x;
    c2 = (a - 1 - x) * b;
    c3 = (a * y);
    c4 = (b - 1 - y) * a;
    ans = max(max(c1, c2), max(c3, c4));
    t--;
    cout << ans << "\n";
  }
}
