#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, r, t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> a >> b;
    r = (a / b) * b;
    if (a % b > b / 2) {
      r += b / 2;
    } else {
      r += a % b;
    }
    cout << r << endl;
  }
  return 0;
}
