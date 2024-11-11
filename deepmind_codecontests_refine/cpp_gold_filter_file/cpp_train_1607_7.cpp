#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
int main() {
  int x1, y1, z1;
  int x2, y2, z2;
  scanf("%d %d %d", &x1, &y1, &z1);
  scanf("%d %d %d", &x2, &y2, &z2);
  int dist = abs(x1 - x2) + abs(y1 - y2) + abs(z1 - z2);
  if (dist <= 2)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
