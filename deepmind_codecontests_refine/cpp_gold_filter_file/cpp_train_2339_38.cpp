#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, s;
  char a[10], b[10], c[10];
  cin >> a >> b >> c;
  if (a[0] == 'p' && b[0] == 'r' && c[0] == 'r')
    cout << "F" << endl;
  else if (a[0] == 'r' && b[0] == 's' && c[0] == 's')
    cout << "F" << endl;
  else if (a[0] == 's' && b[0] == 'p' && c[0] == 'p')
    cout << "F" << endl;
  else if (a[0] == 'r' && b[0] == 'p' && c[0] == 'r')
    cout << "M" << endl;
  else if (a[0] == 's' && b[0] == 'r' && c[0] == 's')
    cout << "M" << endl;
  else if (a[0] == 'p' && b[0] == 's' && c[0] == 'p')
    cout << "M" << endl;
  else if (a[0] == 's' && b[0] == 's' && c[0] == 'r')
    cout << "S" << endl;
  else if (a[0] == 'r' && b[0] == 'r' && c[0] == 'p')
    cout << "S" << endl;
  else if (a[0] == 'p' && b[0] == 'p' && c[0] == 's')
    cout << "S" << endl;
  else
    cout << "?" << endl;
  return 0;
}
