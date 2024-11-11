#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int p, x, y;
bool ok(int s) {
  int i = (s / 50) % 475;
  for (int j = 1; j <= 25; j++) {
    i = (i * 96 + 42) % 475;
    if (i + 26 == p) return true;
  }
  return false;
}
int main() {
  cin >> p >> x >> y;
  int xx = x;
  while (xx - 50 >= y) {
    if (ok(xx)) {
      printf("0\n");
      return 0;
    }
    xx -= 50;
  }
  int cnt = 0;
  while (1) {
    if (ok(x + cnt * 50)) {
      cout << (cnt + 1) / 2 << endl;
      return 0;
    }
    cnt++;
  }
}
