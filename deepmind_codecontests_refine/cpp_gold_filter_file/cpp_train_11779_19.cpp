#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int x, y, z, a, b, c, d;
  cin >> x >> y >> z;
  cin >> a >> b >> c;
  bool flag = true;
  if (a >= x) {
    a -= x;
  } else
    flag = false;
  d = a + b;
  if (d >= y) {
    d -= y;
  } else
    flag = false;
  d += c;
  if (d >= z) {
    d -= z;
  } else
    flag = false;
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
