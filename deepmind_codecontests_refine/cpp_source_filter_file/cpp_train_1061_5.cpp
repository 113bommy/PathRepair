#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n;
  a = n / 36;
  b = (n - a * 36) / 3;
  if ((n - a * 36) % 3 > 1) ++b;
  if (b >= 12) {
    a = b / 12;
    b %= 12;
  }
  cout << a << " " << b;
  return 0;
}
