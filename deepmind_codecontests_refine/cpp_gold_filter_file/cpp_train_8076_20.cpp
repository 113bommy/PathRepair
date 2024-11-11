#include <bits/stdc++.h>
using namespace std;
long long K;
const int d[][2] = {{1, 1}, {2, 0}, {1, -1}, {-1, -1}, {-2, 0}, {-1, 1}};
bool check(int x, int y) {
  for (int i = 0; i < 6; i++) {
    long long X = x + d[i][0];
    long long Y = y + d[i][1];
    if (X * X + 3 * Y * Y > K) return (false);
  }
  return (true);
}
int main() {
  long long k;
  cin >> k;
  K = 4 * k * k;
  int x = 0;
  int y = 0;
  while (check(x, y)) y += 2;
  long long res = (y -= 2) + 1;
  while (true) {
    x += 3;
    y += 1;
    while (!check(x, y))
      if ((y -= 2) < 0) goto exit;
    res += (y + 1) << 1;
  }
exit:
  cout << res;
  return (0);
}
