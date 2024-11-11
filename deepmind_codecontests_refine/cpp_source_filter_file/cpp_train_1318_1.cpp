#include <bits/stdc++.h>
using namespace std;
string a;
int main() {
  int x = 0, y = 0;
  cin >> a;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == '-')
      x++;
    else
      y++;
  }
  if (y == 0)
    cout << "NO" << endl;
  else if (x % y == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
