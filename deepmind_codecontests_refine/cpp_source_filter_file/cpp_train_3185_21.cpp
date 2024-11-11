#include <bits/stdc++.h>
using namespace std;
int main() {
  int a = 0, b = 0;
  cin >> a >> b;
  for (int i = 0; i < 100; i++) {
    a = 3 * a;
    b = 2 * b;
    if (a > b) {
      cout << i;
      break;
    }
  }
  return 0;
}
