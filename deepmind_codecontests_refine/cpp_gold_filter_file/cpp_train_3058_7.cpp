#include <bits/stdc++.h>
using namespace std;
int main() {
  int w;
  w = 1;
  while (w--) {
    int a, b, n;
    cin >> a >> b >> n;
    if (a % b == 0) {
      string s(n, '0');
      cout << a << s;
    } else {
      int i = 0;
      bool f = false;
      string s(n - 1, '0');
      while (i <= 9) {
        a = a * 10 + i;
        if (a % b == 0) {
          f = true;
          break;
        }
        a /= 10;
        i++;
      }
      if (f)
        cout << a << s << endl;
      else
        cout << "-1" << endl;
    }
  }
}
