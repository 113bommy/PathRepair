#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  long long h, n;
  cin >> h >> n;
  long long max = 1 << h;
  long long res = 2 * max - 2;
  int dir = 1;
  max >>= 1;
  while (max) {
    if (dir) {
      if (n <= max) {
        res -= (2 * max - 1);
        dir = !dir;
      } else {
        n -= max;
      }
    } else {
      if (n > max) {
        res -= (2 * max - 1);
        dir = !dir;
        n -= max;
      }
    }
    max >>= 1;
  }
  cout << res << endl;
  return 0;
}
