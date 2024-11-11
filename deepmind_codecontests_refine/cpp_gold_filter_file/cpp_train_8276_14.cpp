#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  scanf("%d:%d%d", &a, &b, &c);
  b += c;
  a = a + (b / 60);
  b = b % 60;
  a = a % 24;
  if (a >= 10 && b >= 10) {
    cout << a << ":" << b;
  } else if (a <= 10 && b >= 10) {
    if (a == 0)
      cout << "00:" << b;
    else
      cout << "0" << a << ":" << b;
  } else if (b <= 10 && a >= 10) {
    cout << a << ":";
    if (b == 0)
      cout << "00";
    else
      cout << "0" << b;
  } else {
    if (a == 0 && b == 0)
      cout << "00:"
           << "00";
    else
      cout << "0" << a << ":"
           << "0" << b;
  }
  return 0;
}
