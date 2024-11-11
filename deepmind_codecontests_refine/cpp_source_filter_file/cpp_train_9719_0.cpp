#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int m = min(a, min(b, c));
  int r = 0;
  for (int i = 1; i <= m; i++) {
    if (a % i == 0 && b % i == 0 && ((a / i) * (b / i) == c)) {
      r = a / i + b / i + i;
      r *= 4;
    }
  }
  cout << r << endl;
}
