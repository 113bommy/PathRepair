#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, s, n, x;
  cin >> a >> b;
  n = a / b;
  s = a % b;
  x = n + s;
  int j = x;
  while (j != 0) {
    s = x % b;
    x = x / b;
    j = x;
    n += x;
    x += s;
  }
  cout << a + n;
}
