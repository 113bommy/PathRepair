#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, a, b, c, flag = 0;
  cin >> x >> y >> z >> a >> b >> c;
  if (x > a) {
    flag = 1;
  } else {
    a -= x;
    if (y > a + b) {
      flag = 1;
    } else {
      a -= y;
      int sum = a + b + c;
      if (sum > z) {
        flag = 0;
      } else {
        flag = 1;
      }
    }
  }
  (flag == 0) ? cout << "YES" : cout << "NO";
  return 0;
}
