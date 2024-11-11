#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    cout << ((y - x) % (a + b) == 0 ? (y - x) / (a + b) : -1) << endl;
  }
}
