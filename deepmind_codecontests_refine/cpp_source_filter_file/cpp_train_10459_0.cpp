#include <bits/stdc++.h>
using namespace std;
int main() {
  int T = 3;
  {
    int a, b, c;
    cin >> a >> b;
    c = a - b;
    if (c == 0)
      cout << "infinity" << endl;
    else if (c < 0)
      cout << 0 << endl;
    else {
      int ans = 0;
      for (int i = 1; i * i < c; ++i)
        if (c % i == 0) ans += (i > b) + (!(i * i == c) && c / i > b);
      cout << ans << endl;
    }
  }
  return 0;
}
