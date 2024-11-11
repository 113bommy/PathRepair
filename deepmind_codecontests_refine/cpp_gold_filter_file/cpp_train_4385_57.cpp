#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, t1, t2, t3;
  while (cin >> x >> y >> z >> t1 >> t2 >> t3) {
    long long lt = 0, dt = 0;
    if (x > y) {
      lt = (x - y) * t1;
      if (x > z) {
        dt = (x - z) * t2 + (x - y) * t2 + 3 * t3;
      } else {
        dt = (z - x) * t2 + (x - y) * t2 + 3 * t3;
      }
    } else {
      lt = (y - x) * t1;
      if (x > z) {
        dt = (x - z) * t2 + (y - x) * t2 + 3 * t3;
      } else {
        dt = (z - x) * t2 + (y - x) * t2 + 3 * t3;
      }
    }
    if (dt > lt) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
  }
  return 0;
}
