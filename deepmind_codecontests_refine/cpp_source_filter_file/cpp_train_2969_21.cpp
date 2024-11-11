#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  string s, f;
  cin >> x >> s >> f;
  if (f == "week" && (x == 6 || x == 7))
    cout << 53;
  else if (f == "week")
    cout << 52;
  else if (f == "month") {
    if (x <= 29)
      cout << 12;
    else if (x == 30)
      cout << 11;
    else if (x == 31)
      cout << 7;
  }
  return 0;
}
