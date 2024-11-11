#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a + b == c + d || a + c == b + d || a + d == b + c)
    cout << "YES" << endl;
  else {
    if (a + b + c == d || a + b + d == c || a + c + d == b || a == b + c + d)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
