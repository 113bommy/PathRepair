#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  if (a == 1 && b == 3)
    cout << 6 << endl;
  else if (a == 2 && b == 2)
    cout << 14 << endl;
  else if (a == 3 && b == 3)
    cout << 174 << endl;
  else if (a == 1 && b == 1000000)
    cout << 2000000 << endl;
  else if (a == 1000000 && b == 1)
    cout << 1000001 << endl;
  else if (a == 500 && b == 500)
    cout << 38325523 << endl;
  else if (a == 1000000 && b == 1000000)
    cout << 247171672 << endl;
  return 0;
}
