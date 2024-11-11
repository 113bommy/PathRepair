#include <bits/stdc++.h>
using namespace std;
int oo = 0x3f3f3f3f;
double inf = 1.0 / 0.0;
const double pi = 2 * acos(0.0);
const int MOD = 1e9 + 7;
const int MOD1 = 998244353;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int x, y, z;
  cin >> x >> y >> z;
  int h = x - y;
  if (z == 0) {
    if (h > 0) return 0 * puts("+");
    if (h < 0) return 0 * puts("-");
    return 0 * puts("0");
  }
  if (h >= 0) {
    if (z >= h) {
      return 0 * puts("?");
    } else {
      return 0 * puts("+");
    }
  }
  h = -1 * h;
  if (z >= h) {
    return 0 * puts("?");
  } else {
    return 0 * puts("-");
  }
  return 0;
}
