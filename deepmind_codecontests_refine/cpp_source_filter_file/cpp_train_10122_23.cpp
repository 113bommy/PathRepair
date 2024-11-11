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
      cout << "0";
    else if (dif < 0 && dif % 2 == 0)
      cout << "1";
    else if (dif > 0 && dif % 2 == 1)
      cout << "1";
    else
      cout << "2";
  }
  return 0;
}
