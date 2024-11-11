#include <bits/stdc++.h>
using namespace std;
int const N = 2e5 + 10;
int main() {
  ios_base::sync_with_stdio(0);
  ;
  int T;
  cin >> T;
  while (T--) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    double tmp = double(y - x) / (a + b);
    if (tmp == int(tmp))
      cout << (int)tmp << endl;
    else
      cout << -1 << endl;
  }
}
