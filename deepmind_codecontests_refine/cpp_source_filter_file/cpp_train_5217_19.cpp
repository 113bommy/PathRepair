#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    n -= 10;
    if (n <= 0)
      cout << 0 << endl;
    else if (n <= 9)
      cout << 4 << endl;
    else if (n == 10)
      cout << 15 << endl;
    else if (n == 11)
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
