#include <bits/stdc++.h>
using namespace std;
struct head {
  int x;
  int y;
};
int findheadx(head a, head b, head c) { return a.x + b.x - c.x; }
int findheady(head a, head b, head c) { return a.y + b.y - c.y; }
int main() {
  head a, b, c;
  cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
  head ar[3];
  ar[0] = {findheadx(a, b, c), findheady(a, b, c)};
  ar[1] = {findheadx(c, a, b), findheady(c, a, b)};
  ar[2] = {findheadx(b, c, a), findheady(b, c, a)};
  cout << 3 << '\n';
  for (int j = 0; j < 3; j++) cout << ar[j].x << " " << ar[j].y << '\n';
  return 0;
}
