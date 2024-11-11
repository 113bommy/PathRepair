#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  n = n % 360;
  int angle;
  angle = -n;
  int m = min(abs(n), 360 - abs(n)), pos = 0;
  for (int i = 0; i < 3; ++i) {
    angle += 90;
    int u = min(angle, 360 - angle);
    if (abs(u) < abs(m)) {
      m = u;
      pos = i + 1;
    }
  }
  cout << pos << endl;
  return 0;
}
