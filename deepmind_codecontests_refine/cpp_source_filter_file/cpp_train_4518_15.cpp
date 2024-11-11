#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n;
  cin >> a >> b >> n;
  if (a == 0 && b != 0) {
    cout << "No solutions";
    return 0;
  }
  if (a == 0 || b == 0) {
    cout << 0;
    return 0;
  }
  if (a * b < 0 && n % 2 == 0) {
    cout << "No solution";
    return 0;
  }
  if (b % a) {
    cout << "No solution";
    return 0;
  }
  int x = abs(b / a);
  for (int i = 0; i < 12; i++) {
    if (pow(i, n) == x) {
      if (a * b < 0) cout << '-';
      cout << i;
      return 0;
    }
  }
  cout << "No solution";
  return 0;
}
