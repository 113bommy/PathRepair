#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  string b;
  cin >> a >> b >> b;
  if (b == "week")
    if (a == 4 || a == 5)
      cout << 52 << endl;
    else
      cout << 51 << endl;
  else if (a <= 29)
    cout << 12 << endl;
  else if (a == 30)
    cout << 11 << endl;
  else if (a == 31)
    cout << 7 << endl;
  return 0;
}
