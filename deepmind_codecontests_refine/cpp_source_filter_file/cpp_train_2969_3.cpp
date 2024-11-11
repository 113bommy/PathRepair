#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  string garbage, weekOrMonth;
  cin >> x >> garbage >> weekOrMonth;
  if (weekOrMonth == "week") {
    if (x != 5 || x != 6)
      cout << 52;
    else
      cout << 53;
  } else if (weekOrMonth == "month") {
    if (x <= 29)
      cout << 12;
    else if (x == 30)
      cout << 11;
    else if (x == 31)
      cout << 7;
  }
  return 0;
}
