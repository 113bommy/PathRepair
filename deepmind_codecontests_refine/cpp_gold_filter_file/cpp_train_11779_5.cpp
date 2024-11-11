#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, a, b, c, flag = 0;
  cin >> x >> y >> z >> a >> b >> c;
  a -= x;
  if (a < 0) {
    flag = 1;
  }
  if (a + b < y || a + b + c < y + z) {
    flag = 1;
  }
  if (flag == 1) {
    cout << "NO";
    return 0;
  }
  cout << "YES";
  return 0;
}
