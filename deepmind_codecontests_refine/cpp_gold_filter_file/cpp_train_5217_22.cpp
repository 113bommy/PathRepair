#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  while (cin >> n) {
    x = n - 10;
    if (x <= 0 || x > 11)
      cout << 0 << endl;
    else if (x == 10)
      cout << 15 << endl;
    else
      cout << 4 << endl;
  }
  return 0;
}
