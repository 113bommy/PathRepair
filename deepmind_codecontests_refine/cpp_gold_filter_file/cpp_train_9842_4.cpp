#include <bits/stdc++.h>
using namespace std;
int main() {
  double d, h, v, e;
  cin >> d >> h >> v >> e;
  double z = d * d / 4 * 3.14159265358979323846 * h /
             (v - d * d / 4 * 3.14159265358979323846 * e);
  if (z <= 0) {
    cout << "NO";
  } else {
    cout << "YES " << z;
  }
  return 0;
}
