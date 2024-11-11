#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, d = 0;
  char c;
  cin >> a >> a;
  while (cin >> c >> b) {
    if (c == '+')
      a = a + b;
    else if (a - b < 0)
      d = d + 1;
    else
      a = a - b;
  }
  cout << a << ' ' << d;
}
