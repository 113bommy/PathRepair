#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int vcnt = 0, mcnt = 0;
  mcnt = max((3 * a) / 10, a - ((a * c) / 250));
  vcnt = max((3 * b) / 10, b - ((b * d) / 250));
  if (mcnt == vcnt) {
    cout << "Tie";
  } else if (mcnt > vcnt) {
    cout << "Misha";
  } else {
    cout << "Vasya";
  }
  return 0;
}
