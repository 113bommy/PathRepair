#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> a >> b;
    if (a > 3 || a >= b || (a == 2 && b == 3))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
