#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, a2, b1, b2;
  cin >> a1 >> a2 >> b2 >> b1;
  bool a, b;
  a = (b1 >= a1 - 1) && (a1 >= (b1 - 2) / 2);
  b = (b2 >= a2 - 1) && (a2 >= (b2 - 2) / 2);
  if (a || b)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
