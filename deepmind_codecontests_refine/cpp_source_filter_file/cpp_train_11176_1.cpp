#include <bits/stdc++.h>
using namespace std;
long long resp(long long a, long long b, long long c, long long x, long long y,
               long long z) {
  if ((a == 0 && b == 0 && c == 0) || (x == 0 && y == 0 && z == 0)) return -1;
  if ((a == 0 && b == 0 && c != 0) || (x == 0 && y == 0 && z != 0)) return 0;
  if (a * y == b * x) {
    if (a == 0) {
      swap(a, b);
      swap(x, y);
    }
    if (a * z == x * c) return -1;
    return 0;
  } else {
    return 1;
  }
}
int main() {
  long long a, b, c, x, y, z;
  cin >> a >> b >> c >> x >> y >> z;
  cout << resp(a, b, c, x, y, z);
  return 0;
}
