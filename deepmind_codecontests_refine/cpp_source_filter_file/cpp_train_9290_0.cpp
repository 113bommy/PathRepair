#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, d, t, i;
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> a >> b >> c >> d;
    if (a == c && b + d == a)
      cout << "Yes" << endl;
    else if (a == d && b + c == a)
      cout << "Yes" << endl;
    else if (b == d && +c == b)
      cout << "Yes" << endl;
    else if (b == c && a + d == b)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
