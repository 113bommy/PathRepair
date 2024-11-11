#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-2;
int main() {
  double left = -2 * 1e9, right = 2 * 1e9;
  long long int n, x;
  int i;
  string ch, ans;
  bool f = 1;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> ch >> x >> ans;
    if (f == 0) continue;
    if (ans == "N") {
      if (ch == ">")
        ch = "<=";
      else if (ch == "<")
        ch = ">=";
      else if (ch == ">=")
        ch = "<";
      else if (ch == "<=")
        ch = ">";
    }
    if (ch == "<") right = min(right, x - eps);
    if (ch == "<=") right = min(right, (double)x);
    if (ch == ">") left = max(left, x + eps);
    if (ch == ">=") left = max(left, (double)x);
    if (left > right) f = 0;
  }
  if (f == 1) {
    x = int(left + 0.999);
    if (x <= right && x >= -(long long)2 * 1e9 && x <= (long long)2 * 1e9) {
      cout << x << endl;
      return 0;
      return 0;
    }
  }
  cout << "Impossible" << endl;
  return 0;
}
