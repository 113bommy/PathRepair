#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, d, e, i = 0;
  cin >> a >> b;
  d = a;
  e = b;
  while (d <= e) {
    d = 3 * d;
    e = 2 * e;
    i++;
  }
  cout << i;
  return 0;
}
