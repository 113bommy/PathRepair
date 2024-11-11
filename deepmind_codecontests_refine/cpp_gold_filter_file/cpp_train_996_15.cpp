#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, a, b, c, d, mn, mx;
  cin >> a >> b >> c >> d;
  mn = min(b, d);
  b -= mn;
  d -= mn;
  if (d > b) {
    for (i = 0; i < 1000; i++) {
      if (d % a == 0) {
        cout << d + mn;
        return 0;
      }
      d += c;
    }
  } else if (d < b) {
    for (i = 0; i < 1000; i++) {
      if (b % c == 0) {
        cout << b + mn;
        return 0;
      }
      b += a;
    }
  } else if (d == b) {
    cout << d + mn;
    return 0;
  }
  cout << "-1";
  return 0;
}
