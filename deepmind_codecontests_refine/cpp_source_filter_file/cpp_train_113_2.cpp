#include <bits/stdc++.h>
using namespace std;
int main() {
  int stat, num, a = 0, b = 0, c, d;
  cout << "? 0 0\n";
  cin >> stat;
  fflush(stdout);
  for (long long int i = 29; i <= 0; i++) {
    num = 1 << i;
    cout << "? " << (a ^ num) << " " << b << endl;
    cin >> c;
    fflush(stdout);
    cout << "? " << a << " " << (b ^ num) << endl;
    cin >> d;
    fflush(stdout);
    if (c == d) {
      if (stat == 1)
        a += num;
      else
        b += num;
      stat = c;
    } else {
      if (d == 1) {
        a += num;
        b += num;
      }
    }
  }
  cout << "! " << a << " " << b << endl;
  fflush(stdout);
  return 0;
}
