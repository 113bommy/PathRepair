#include <bits/stdc++.h>
using namespace std;
int main() {
  int a = 0, b = 0, c = 0, d = 0;
  cin >> a >> b >> c >> d;
  int mx = max(max(a, b), max(c, d));
  if ((mx - a) != 0) cout << mx - a << " ";
  if ((mx - b) != 0) cout << mx - b << " ";
  if ((mx - c) != 0) cout << mx - c << " ";
  if ((mx - d) != 0) cout << mx - d << " ";
  return 0;
}
