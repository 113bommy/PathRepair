#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (c < a) swap(c, a);
  if (c < b) swap(c, b);
  if (b < a) swap(a, b);
  if (c - d >= a + d) {
    if (b > c - d)
      cout << b - c + d << endl;
    else if (b < a + d)
      cout << a + d - b << endl;
    else
      cout << 0 << endl;
  } else if (b >= a + d) {
    cout << min((b - a - d) + (a + d + d - c), b + d - c) << endl;
  } else if (b <= c - d) {
    cout << min((c - d - b) + (c - d - d - a), a - b + d) << endl;
  } else {
    cout << (b + d - c) + (a - b + d) << endl;
  }
  return 0;
}
