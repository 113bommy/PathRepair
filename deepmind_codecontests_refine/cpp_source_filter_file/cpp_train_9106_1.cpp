#include <bits/stdc++.h>
using namespace std;
int main() {
  string x, y;
  int n, z, i = 0, a = 0;
  cin >> x >> n;
  if ((int)x.size() % n != 0) {
    cout << "NO";
    return 0;
  }
  z = x.size() / 2;
  while (i < x.size()) {
    y = x.substr(i, x.size() / 2);
    if (y == string(y.rbegin(), y.rend())) {
      a++;
      i += z;
    } else
      break;
  }
  if (a == n)
    cout << "YES" << endl;
  else
    cout << "NO";
}
