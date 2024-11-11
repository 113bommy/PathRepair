#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, a, b;
    cin >> n >> x >> a >> b;
    int r = min(a, b);
    int q = max(a, b);
    while (x--) {
      if (r != 1) {
        r = r - 1;
      } else if (q != n) {
        q++;
      }
    }
    cout << q - r << endl;
  }
  return 0;
}
