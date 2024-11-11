#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d = 0;
  cin >> a >> b;
  c = a * b;
  for (int x = 1; x < c; x++) {
    if (x % 2 == 0) {
      d = d + 1;
    }
  }
  cout << d << endl;
  return 0;
}
