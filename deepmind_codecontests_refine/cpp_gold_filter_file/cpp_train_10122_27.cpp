#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int dif = b - a;
    if (a == b)
      cout << "0\n";
    else if (dif < 0 && dif % 2 == 0)
      cout << "1\n";
    else if (dif > 0 && dif % 2 == 1)
      cout << "1\n";
    else
      cout << "2\n";
  }
  return 0;
}
