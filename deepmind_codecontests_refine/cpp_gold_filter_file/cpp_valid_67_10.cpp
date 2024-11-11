#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b, c;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    int n = abs(a - b);
    int check = 2 * n;
    if (a > check || b > check || c > check)
      cout << -1 << endl;
    else if (c <= n)
      cout << c + n << endl;
    else
      cout << c - n << endl;
  }
  return 0;
}
