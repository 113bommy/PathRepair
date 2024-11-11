#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int s, a, b, c, t, x, y;
  cin >> t;
  while (t--) {
    cin >> s >> a >> b >> c;
    x = s / c;
    y = (x * b) / a;
    cout << x + y << endl;
  }
  return 0;
}
