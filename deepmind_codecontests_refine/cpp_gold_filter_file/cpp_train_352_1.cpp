#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  while (a % 2 == 0 || a % 3 == 0 || a % 5 == 0) {
    if (a % 2 == 0) {
      a1++;
      a /= 2;
    }
    if (a % 3 == 0) {
      a2++;
      a /= 3;
    }
    if (a % 5 == 0) {
      a3++;
      a /= 5;
    }
  }
  while (b % 2 == 0 || b % 3 == 0 || b % 5 == 0) {
    if (b % 2 == 0) {
      b1++;
      b /= 2;
    }
    if (b % 3 == 0) {
      b2++;
      b /= 3;
    }
    if (b % 5 == 0) {
      b3++;
      b /= 5;
    }
  }
  if (a != b) {
    cout << -1;
    return 0;
  }
  cout << abs(a1 - b1) + abs(a2 - b2) + abs(a3 - b3);
  return 0;
}
