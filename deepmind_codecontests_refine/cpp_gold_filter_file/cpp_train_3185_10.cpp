#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  for (int i = 1; i < 100; i++) {
    a = 3 * a;
    b = 2 * b;
    if (a > b) {
      cout << i;
      break;
    }
  }
  return 0;
}
