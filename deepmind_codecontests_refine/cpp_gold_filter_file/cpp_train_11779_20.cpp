#include <bits/stdc++.h>
using namespace std;
long long co(long long a) {
  if (a < 2)
    return 0;
  else
    return a * (a - 1) / 2;
}
string tos(long long a) {
  std::string s = std::to_string(a);
  return s;
}
int main() {
  long long a, b, c, x, y, z;
  cin >> x >> y >> z >> a >> b >> c;
  long long r = 0;
  if (a < x)
    cout << "NO";
  else {
    a = a - x;
    b = a + b;
    if (b < y)
      cout << "NO";
    else {
      b = b - y;
      c = b + c;
      if (c < z)
        cout << "NO";
      else
        cout << "YES";
    }
  }
}
