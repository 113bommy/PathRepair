#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b, string c) {
  if (a[0] == 'r' && b[0] == 's' && c[0] == 's') return true;
  if (a[0] == 's' && b[0] == 'p' && c[0] == 'p') return true;
  if (a[0] == 'p' && b[0] == 'r' && c[0] == 'r') return true;
  return false;
}
int main() {
  string a, b, c;
  while (cin >> a >> b >> c) {
    bool x = cmp(a, b, c);
    bool y = cmp(c, a, b);
    bool z = cmp(b, c, a);
    if (x)
      cout << "F" << endl;
    else if (y)
      cout << "M" << endl;
    else if (z)
      cout << "S" << endl;
    else
      cout << "?" << endl;
  }
  return 0;
}
