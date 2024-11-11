#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  for (int x = 1; x < a; x++) {
    int y = sqrt(a * a - x * x);
    if (y * y == a * a - x * x && (y * b) % a == 0 && (x * b) % a == 0 &&
        (x * b) / a != y) {
      cout << "YES\n"
           << x << " " << y << "\n0 0\n"
           << -(y * b) / a << " " << (x * b) / b;
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
