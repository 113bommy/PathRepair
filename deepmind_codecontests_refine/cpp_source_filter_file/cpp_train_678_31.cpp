#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a;
  if (a == 1) b = a;
  if (a != 1) {
    if (a % 2 == 0 && a != 1) {
      b = a / 2;
    } else
      b = (a - 1) / 2;
  }
  cout << b;
  return 0;
}
