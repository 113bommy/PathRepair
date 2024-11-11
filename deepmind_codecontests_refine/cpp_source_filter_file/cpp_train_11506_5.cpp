#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, m, l = -1, r = -1;
  cin >> n >> m;
  while (m--) {
    int p;
    string tmp, d;
    cin >> tmp >> tmp >> d >> tmp >> p;
    if (d == "left") {
      if (l == -1 || (l != -1 && p < l)) l = p;
    } else {
      if (r == -1 || (r != -1 && p > r)) r = p;
    }
  }
  if (l == -1 && r == -1)
    cout << n << endl;
  else if (l == -1 && r != -1) {
    if (r == n)
      cout << "-1" << endl;
    else
      cout << n - r << endl;
  } else if (l != -1 && r == -1) {
    if (l == 1)
      cout << "-1" << endl;
    else
      cout << l - 1 << endl;
  } else {
    if ((r - l) <= 1)
      cout << "-1" << endl;
    else
      cout << r - l - 1 << endl;
  }
  return 0;
}
