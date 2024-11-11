#include <bits/stdc++.h>
using namespace std;
int a1, a2, a3, b1, b2, b3;
int judge(int x1, int y1, int x2, int y2) {
  return x1 <= a1 && x2 <= a1 && y1 <= b1 && y2 <= b1 &&
         (x1 + x2 <= a1 || y1 + y2 <= b1);
}
int main() {
  scanf("%d%d%d%d%d%d", &a1, &b1, &a2, &b2, &a3, &b3);
  if (judge(a2, b2, a3, b3) || judge(a2, b2, b3, a3) || judge(b2, a2, a3, b3) ||
      judge(b2, a2, b3, a3))
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
