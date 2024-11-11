#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (d < b) {
    swap(b, d);
    swap(a, c);
  }
  for (int m = 0; m <= 1000000; ++m) {
    if ((m * a + b - d) % c == 0) {
      int n = (m * a + b - d) / c;
      if (n >= 0) {
        cout << (m * a + b) << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
