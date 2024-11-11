#include <bits/stdc++.h>
using namespace std;
int kawsar(char ch) {
  if (ch == '[') return 0;
  if (ch == '(') return 1;
  return 2;
}
int main() {
  int a, b, i, j, x, y, p;
  string k, u;
  cin >> k >> u;
  p = k.size();
  x = y = 0;
  for (i = 0; i < p; i += 2) {
    if (k[i] != u[i]) {
      a = kawsar(k[i]);
      b = kawsar(u[i]);
      if (a == 0 && b == 1)
        x++;
      else if (a == 0 && b == 2)
        y++;
      else if (b == 0 && a == 1)
        y++;
      else if (b == 0 && a == 2)
        x++;
      else if (b == 1 && a == 2)
        x++;
      else
        y++;
    }
  }
  if (x == y)
    cout << "TIE" << endl;
  else if (x > y)
    cout << "TEAM 1 WINS" << endl;
  else if (x < y)
    cout << "TEAM 2 WINS" << endl;
  return 0;
}
