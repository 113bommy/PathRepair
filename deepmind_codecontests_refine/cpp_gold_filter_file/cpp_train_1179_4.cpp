#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, d = 0;
  cin >> a >> b;
  while (b != 0) {
    int r = b % 10;
    d = d * 10 + r;
    b /= 10;
  }
  cout << a + d << "\n";
}
