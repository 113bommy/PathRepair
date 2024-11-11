#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, n = 0;
  cin >> a >> b >> c;
  for (int i = 1; i <= pow(10, 5); i++) {
    a = a - 1;
    b = b - 2;
    c = c - 4;
    if (a >= 0 && b >= 0 && c >= 0) {
      n = n + 7;
    }
  }
  cout << n;
}
