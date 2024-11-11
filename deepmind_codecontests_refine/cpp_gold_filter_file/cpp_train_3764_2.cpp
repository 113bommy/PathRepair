#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  long long ans;
  if (a >= b && a >= c && a >= d) {
    ans = a;
    cout << ans - b << " " << ans - c << " " << ans - d << endl;
  } else if (b >= a && b >= c && b >= d) {
    ans = b;
    cout << ans - a << " " << ans - d << " " << ans - c << endl;
  } else if (c >= b && c >= a && c >= d) {
    ans = c;
    cout << ans - a << " " << ans - b << " " << ans - d << endl;
  } else {
    ans = d;
    cout << ans - a << " " << ans - b << " " << ans - c << endl;
  }
  return 0;
}
