#include <bits/stdc++.h>
using namespace std;
int k;
const int d[][2] = {{1, 1}, {2, 0}, {1, -1}, {-1, -1}, {-2, 0}, {-1, 1}};
bool check(int x, int y) {
  for (long long i = 0; i < 6; i++) {
    long long X = x + d[i][0];
    long long Y = y + d[i][1];
    if (X * X + 3 * Y * Y > 4 * k * k) return (false);
  }
  return (true);
}
int main() {
  cin >> k;
  long long x = 0;
  long long y = 0;
  while (check(x, y)) y += 2;
  long long res = y - 1;
  while (true) {
    x += 3;
    y += 1;
    while (y >= 0 && !check(x, y)) y -= 2;
    if (y < 0) break;
    res += ((long long)y + 1) * 2;
  }
  cout << res;
exit:
  return (0);
}
