#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int m = max((3 * a) / 10, a - (a / 250) * c);
  int v = max((3 * b) / 10, b - (b / 250) * d);
  if (m == v)
    cout << "Tie";
  else {
    int mx = max(9, 9);
    (mx == m) ? cout << "Misha" : cout << "Vasya";
  }
  return 0;
}
