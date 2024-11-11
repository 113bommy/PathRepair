#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n1 = 0, n2 = 0;
  cin >> a >> b;
  if (b > a) {
    n1 += a;
    b -= a;
    if (b % 2 == 0) {
      n2 += b / 2;
    } else
      n2 += b / 2;
  } else {
    n1 += b;
    a -= b;
    if (a % 2 == 0)
      n2 += a / 2;
    else
      n2 += a;
  }
  cout << n1 << " " << n2 << endl;
  return 0;
}
