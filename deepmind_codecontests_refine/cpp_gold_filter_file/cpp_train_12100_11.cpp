#include <bits/stdc++.h>
using namespace std;
int main() {
  long T;
  cin >> T;
  while (T--) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if ((y - x) % (a + b) == 0)
      cout << (y - x) / (a + b) << endl;
    else
      cout << "-1\n";
  }
  return 0;
}
