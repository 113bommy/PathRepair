#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, x = 0, y = 0, z = 0, F, FF;
  cin >> a >> b;
  for (int i = 1; i <= 6; i++) {
    F = fabs(a - i);
    FF = fabs(b - i);
    if (F < FF) {
      x++;
    } else if (F > FF) {
      z++;
    } else {
      y++;
    }
  }
  cout << x << " " << y << " " << z;
  return 0;
}
