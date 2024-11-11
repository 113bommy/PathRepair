#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d = 0;
  cin >> a >> b >> c;
  if ((c * a) % 100 != 0) {
    d = ((c * a) / 100) + 1;
  } else if ((c * a) % 100 == 0) {
    d = ((c * a) / 100);
  }
  if (d < b)
    cout << 0 << endl;
  else {
    cout << d - b << endl;
  }
}
