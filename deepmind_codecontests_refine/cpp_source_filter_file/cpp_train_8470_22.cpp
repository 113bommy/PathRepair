#include <bits/stdc++.h>
using namespace std;
bool isValid(int num) {
  int a[10]{0};
  int digit;
  for (int i = 0; i <= 3; i++) {
    digit = num % 10;
    ++a[digit];
    num = num / 10;
  }
  for (int i = 0; i <= 9; i++) {
    if (a[i] > 1) return false;
  }
  return true;
}
int main() {
  int n;
  cin >> n;
  while (n <= 9000) {
    ++n;
    if (isValid(n)) {
      cout << n << endl;
      return 0;
    }
  }
  return 0;
}
