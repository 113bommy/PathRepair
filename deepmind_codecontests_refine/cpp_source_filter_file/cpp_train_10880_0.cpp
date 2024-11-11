#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, k = 0, cnt = 0;
  cin >> x;
  if (x == 1) {
    cout << 0;
    return 0;
  }
  if (x % 2 != 0) {
    cout << 1;
    return 0;
  }
  int p = x / 2;
  if (p % 2 != 0) {
    cout << p / 2;
    return 0;
  }
  if (p % 2 == 0) {
    cout << p / 2 - 1;
    return 0;
  }
  return 0;
}
