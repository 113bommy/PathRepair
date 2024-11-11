#include <bits/stdc++.h>
using namespace std;
int main() {
  int y = 0, x = 0;
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < b.size() / 2; i++) {
    if ((a[i] == '8' && b[i] == '[') || (a[i] == '[' && b[i] == '(') ||
        (a[i] == '(' && b[i] == '8'))
      x++;
    else if (a[i] != b[i])
      y++;
  }
  if (x > y)
    cout << "TEAM 1 WINS";
  else if (x < y)
    cout << "TEAM 2 WINS";
  else
    cout << "TIE";
}
