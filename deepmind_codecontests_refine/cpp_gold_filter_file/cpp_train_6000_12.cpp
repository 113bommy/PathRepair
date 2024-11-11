#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, y1, x2, y2;
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  int xn = max(abs(x1 - x2) + 1, 2);
  int yn = max(abs(y1 - y2) + 1, 2);
  printf("%d\n", xn * 2 + yn * 2);
  return 0;
}
