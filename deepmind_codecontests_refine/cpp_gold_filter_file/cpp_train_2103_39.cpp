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
    if (a % c == 0) {
      pens = a / c;
    } else {
      pens = a / c + 1;
    }
    if (b % d == 0) {
      pencil = b / d;
    } else {
      pencil = b / d + 1;
    }
    if (pencil + pens > k) {
      cout << -1 << '\n';
    } else {
      cout << pens << " " << pencil << '\n';
    }
  }
  return 0;
}
