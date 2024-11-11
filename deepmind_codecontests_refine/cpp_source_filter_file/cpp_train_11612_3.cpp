#include <bits/stdc++.h>
using namespace std;
int h1, h2, a, b;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> h1 >> h2 >> a >> b;
  if (h2 <= h1 + a * 8) {
    cout << 0 << endl;
    return 0;
  }
  if (b >= a) {
    cout << -1 << endl;
    return 0;
  }
  int d = 1;
  h1 += a * 8;
  h1 -= b * 12;
  while (h2 >= h1 + a * 12) {
    h1 += (a - b) * 12;
    ++d;
  }
  cout << d << endl;
}
