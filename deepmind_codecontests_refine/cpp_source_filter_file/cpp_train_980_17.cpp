#include <bits/stdc++.h>
using namespace std;
int ok(char x, char y) {
  if (x == y)
    return 0;
  else if ((x == '8' && y == '[') || (x == '[' && y == '(') ||
           (x == '(' && y == '8'))
    return 1;
  return -1;
}
int main() {
  char a[250], b[250];
  cin >> a >> b;
  int i = 0, one = 0, two = 0;
  while (a[i]) {
    if (ok(a[i], b[i]) == 1)
      one++;
    else if (ok(a[i], b[i]) == -1)
      two++;
    i++;
  }
  if (one > two)
    cout << "TEAM 1 WINS" << endl;
  else if (two > one)
    cout << "TEAM 2 WINS" << endl;
  else
    cout << "TIE" << endl;
  return 0;
}
