#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> a >> b >> c;
    if (c < a) {
      cout << c << endl;
    } else if (a <= c && c <= b) {
      cout << ((b / c) + 1) * c << endl;
    } else
      cout << c << endl;
  }
  return 0;
}
