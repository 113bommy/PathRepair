#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
      int d;
      cin >> d;
      if (d == 1)
        a = a + 1;
      else
        b = b + 1;
    }
    if (b > a)
      cout << a << endl;
    else
      cout << b + ((a - b) / 3) << endl;
  }
}
