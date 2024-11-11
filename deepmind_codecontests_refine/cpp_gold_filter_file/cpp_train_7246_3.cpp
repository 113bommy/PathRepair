#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  long long a, b;
  cin >> a >> b;
  t -= 2;
  long long flg = 0, d = b - a;
  while (t--) {
    a = b;
    cin >> b;
    if ((b - a) != d && flg == 0) flg = 1;
  }
  if (flg == 0)
    cout << b + d;
  else
    cout << b;
  return 0;
}
