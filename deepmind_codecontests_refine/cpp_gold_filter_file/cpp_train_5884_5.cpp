#include <bits/stdc++.h>
using namespace std;
long long balta(long long a) {
  long long x, y = 0, i, j;
  for (i = 0; i < 62; i++) {
    for (j = 0; j < i - 1; j++) {
      x = pow(2, i) - pow(2, j) - 1;
      if (x <= a) y++;
    }
  }
  return y;
}
int main() {
  long long a, b;
  cin >> a >> b;
  a = balta(a - 1);
  b = balta(b);
  cout << b - a;
}
