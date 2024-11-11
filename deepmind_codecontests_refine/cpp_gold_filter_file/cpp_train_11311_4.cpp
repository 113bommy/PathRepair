#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int x, y, a, b, a1, b1;
  unsigned long long int t1, t2;
  cin >> x >> y;
  int flag = -1;
  if (x > y) {
    a = y;
    b = x;
    flag = 0;
  } else {
    a = x;
    b = y;
    flag = 1;
  }
  int c = 0;
  while (1) {
    if (a == 0 or b == 0) break;
    t1 = 2 * a;
    t2 = 2 * b;
    if (a < t2 and b < t1) break;
    b = b % (2 * a);
    swap(a, b);
    ++c;
  }
  if (flag == 0) {
    if (c & 1)
      cout << a << " " << b;
    else
      cout << b << " " << a;
  } else {
    if (c & 1)
      cout << b << " " << a;
    else
      cout << a << " " << b;
  }
}
