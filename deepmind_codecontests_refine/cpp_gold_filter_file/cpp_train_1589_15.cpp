#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 0;
  cin >> t;
  while (t--) {
    int x, y, n;
    cin >> x >> y >> n;
    cout << ((n - y) / x) * x + y << endl;
  }
  return 0;
}
