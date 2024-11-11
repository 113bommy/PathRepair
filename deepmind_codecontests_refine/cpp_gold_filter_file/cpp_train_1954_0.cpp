#include <bits/stdc++.h>
using namespace std;
int book[10];
int main() {
  int x, y;
  cin >> x >> y;
  if (x == y) {
    cout << "=" << endl;
  } else if (x == 2) {
    if (y == 3)
      cout << "<" << endl;
    else if (y == 4)
      cout << "=" << endl;
    else
      cout << ">" << endl;
  } else if (y == 2) {
    if (x == 3)
      cout << ">" << endl;
    else if (x == 4)
      cout << "=" << endl;
    else
      cout << "<" << endl;
  } else if (x == 1 || y == 1) {
    if (x != 1)
      cout << ">" << endl;
    else if (y != 1)
      cout << "<" << endl;
  } else {
    if (x > y)
      cout << "<" << endl;
    else
      cout << ">" << endl;
  }
  return 0;
}
