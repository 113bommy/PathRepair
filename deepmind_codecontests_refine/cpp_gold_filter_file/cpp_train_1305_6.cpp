#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
int main() {
  cin >> a >> b >> c;
  if (c == 0) {
    if (a == b)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } else if ((c > 0 && b < a) || (c < 0 && b > a)) {
    cout << "NO" << endl;
  } else {
    if (abs(a - b) % abs(c) == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
