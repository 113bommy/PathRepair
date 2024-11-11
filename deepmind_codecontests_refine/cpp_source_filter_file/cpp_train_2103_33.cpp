#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int pens = 0, pencil = 0;
    if (a % b == 0) {
      pens = a / b;
    } else {
      pens = a / b + 1;
    }
    if (c % d == 0) {
      pencil = c / d;
    } else {
      pencil = c / d + 1;
    }
    if (pencil + pens > k) {
      cout << -1 << '\n';
    } else {
      cout << pens << " " << pencil << '\n';
    }
  }
  return 0;
}
