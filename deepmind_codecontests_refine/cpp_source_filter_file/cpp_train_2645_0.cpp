#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, h;
  cin >> a >> b;
  c = a / b;
  if (b == 1)
    cout << c << endl;
  else {
    a = a - (a / b) * b;
    c++;
    while (a % b != 0) {
      h = a;
      a = b - a;
      b = h;
      if ((a / b) > 1) {
        c += (a / b);
        a = a - (a / b) * b;
        if (b == 1) break;
      }
      c++;
      if (a < 0) break;
    }
    cout << c << endl;
  }
}
