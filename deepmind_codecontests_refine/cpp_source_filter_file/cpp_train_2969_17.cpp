#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s, c;
  cin >> n >> c >> s;
  if (s == "week") {
    if (n < 5)
      cout << 365 / 7;
    else if (n > 4 && n != 7)
      cout << 365 / 7 + 1;
    if (n == 7) cout << 365 / 7;
  }
  if (s == "month") {
    if (n > 28 && n != 31)
      cout << 11;
    else if (n < 29)
      cout << 12;
    else if (n == 31)
      cout << 7;
  }
  return 0;
}
