#include <bits/stdc++.h>
using namespace std;
inline int manh(int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}
int main() {
  int x1, y1, x2, y2;
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  int k = min(x2, y2);
  int xx2 = x2 - k;
  int yy2 = y2 - k;
  bool can = 0;
  if (manh(0, 0, x1, x2) <= max(x2, y2)) can = 1;
  for (int i = xx2, j = yy2; !can && i <= x2; ++i, ++j)
    if (manh(i, j, x1, y1) <= x2 - i) can = 1;
  if (can)
    printf("Polycarp");
  else
    printf("Vasiliy");
  return 0;
}
