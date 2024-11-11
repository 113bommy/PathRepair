#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
long long health(int k) { return a * (1ll + k) - k * (1ll + k) * b * d / 2; }
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> d;
    if (a > c * 1ll * b) {
      cout << "-1\n";
      continue;
    }
    int l = 0, r = c / d;
    while (l < r) {
      int c1 = (l + r) / 2;
      if (health(c1) < health(c1 + 1))
        l = c1 + 1;
      else
        r = c1;
    }
    cout << health(l) << "\n";
  }
  return 0;
}
