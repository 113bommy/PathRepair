#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, m;
  double d;
  cin >> x >> y;
  string s[] = {"black", "white", "black"};
  d = sqrt(x * x + y * y);
  long long X = (int)d;
  m = (x == 0 || y == 0 || d == X ? 0 : (y * 1.0 / x > 0 ? 1 : -1));
  X %= 2;
  cout << (m == 0 ? s[0] : (m == 1 ? s[0 + X] : s[1 + X])) << endl;
  return 0;
}
