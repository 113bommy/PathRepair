#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b;
  if (a <= b) {
    c = a;
    d = (b - c) / 2;
  } else
    c = b;
  d = (a - c) / 2;
  cout << c << " " << d << endl;
  return 0;
}
