#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t) {
    t--;
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    int n = (b - a) * 2, d;
    if (b > n) {
      cout << -1 << endl;
      continue;
    }
    if (c > n / 2)
      d = c - n / 2;
    else
      d = c + n / 2;
    if (1 <= d && d <= n)
      cout << d << endl;
    else
      cout << -1 << endl;
  }
}
