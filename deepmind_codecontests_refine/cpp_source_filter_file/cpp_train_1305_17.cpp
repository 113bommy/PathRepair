#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d;
  cin >> a >> b >> c;
  d = b - a;
  if (c == 0) {
    if (a == b)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } else if (c != 0 && a == b)
    cout << "NO" << endl;
  else {
    if (d > 0 && c > 0) {
      if (d % c == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else if (d < 0 && c < 0) {
      if (d % c == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
