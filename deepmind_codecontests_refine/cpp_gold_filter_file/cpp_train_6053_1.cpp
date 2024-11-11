#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a == d) {
    if (c > 0) {
      if (a > 0) {
        cout << 1;
      } else {
        cout << 0;
      }
    } else {
      cout << 1;
    }
  } else {
    cout << 0;
  }
  return 0;
}
