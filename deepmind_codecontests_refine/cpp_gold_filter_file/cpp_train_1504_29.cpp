#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long ma = 2 * 1e+9, mi = -ma;
  for (int i = 0; i < n; i++) {
    string x, y;
    long long d;
    cin >> x >> d >> y;
    if (y == "N") {
      if (x == ">=")
        x = "<";
      else if (x == "<")
        x = ">=";
      else if (x == "<=")
        x = ">";
      else
        x = "<=";
    }
    if (x == ">")
      mi = max(mi, d + 1);
    else if (x == ">=")
      mi = max(mi, d);
    else if (x == "<")
      ma = min(ma, d - 1);
    else if (x == "<=")
      ma = min(ma, d);
  }
  if (ma >= mi) {
    cout << ma;
  } else {
    cout << "Impossible";
  }
  return 0;
}
