#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    int a, b, c, d;
    cin >> a >> b >> c;
    int maxi = max(a, max(b, c));
    int dif = abs(a - b);
    if (maxi <= dif * 2) {
      d = c - dif;
      if (d <= 0) {
        d = dif + c;
      }
    } else {
      d = -1;
    }
    cout << d << endl;
    t--;
  }
  return 0;
}
