#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
const double PI = acos(-1);
const long long INFF = (long long)1e18;
const int INF = (int)1e9;
const int mod = (int)1e9 + 7;
const int MAX = (int)1e5 + 7;
int main(void) {
  int px, py;
  scanf("%d %d", &px, &py);
  ;
  int vx, vy;
  scanf("%d %d", &vx, &vy);
  ;
  int v1 = px + py;
  int v2 = max(vx, vy);
  if (px + py >= vx + vy)
    puts("Vasiliy");
  else {
    if (v2 >= v1) {
      puts("Polycarp");
      return 0;
    }
    for (int x = vx, y = vy, t = 0; x && y; --x, --y, ++t) {
      int v = abs(x - px) + abs(y - py);
      if (t >= v) {
        puts("Polycarp");
        return 0;
      }
    }
    puts("Vasiliy");
  }
  return 0;
}
