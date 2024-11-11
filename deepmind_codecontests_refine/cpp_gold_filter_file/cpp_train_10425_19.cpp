#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  while (cin >> a >> b >> c) {
    if (b == a / 2 && c == a / 2)
      cout << "NO" << endl;
    else if (b == a / 2 && c == a / 2 + 1)
      cout << "NO" << endl;
    else if (b == a / 2 + 1 && c == a / 2 + 1)
      cout << "NO" << endl;
    else if (b == a / 2 + 1 && c == a / 2)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
