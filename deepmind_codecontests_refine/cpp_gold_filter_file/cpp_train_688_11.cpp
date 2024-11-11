#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, c = 1, a = 1, b = 1;
  cin >> n;
  for (i = 1; i <= n; i++) {
    if (c == i) {
      c = a + b;
      b = a;
      a = c;
      cout << "O";
    } else
      cout << "o";
  }
  return 0;
}
