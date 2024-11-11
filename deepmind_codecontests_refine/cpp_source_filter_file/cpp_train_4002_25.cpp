#include <bits/stdc++.h>
using namespace std;
bool ispower(long long int x) {
  if (x == 0) {
    return false;
  }
  return (ceil(log2(x))) == (floor(log2(x)));
}
int main() {
  long long int test, i, j, xy, count, flag = 0, n, o1 = 0, o2 = 0, x, y, m, l,
                                       z, max1, x1, y1, x2, y2, z1, k, sum, f,
                                       ans1, min1;
  string a;
  x1 = y1 = z1 = f = 0;
  cin >> a;
  for (i = 0; i < a.size(); i++) {
    if (a[i] >= 'a' && a[i] <= 'z') {
      x1++;
    } else {
      if (a[i] >= 'A' && a[i] <= 'Z') {
        y1++;
      } else {
        if (a[i] >= '0' && a[i] <= '9') {
          z1++;
        } else {
          f++;
        }
      }
    }
  }
  if (x1 != 0 && y1 != 0 && z != 0 && x1 + y1 + z1 + f >= 5) {
    cout << "Correct";
  } else {
    cout << "Too weak";
  }
  return 0;
}
