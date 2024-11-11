#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    int a1, b1, c1, a2, b2, c2;
    int d1, d2, d3, d4, d5, d6, d7;
    scanf("%d %d %d %d %d %d", &a1, &b1, &c1, &a2, &b2, &c2);
    scanf("%d %d %d %d %d %d %d", &d1, &d2, &d3, &d4, &d5, &d6, &d7);
    int x1 = d1 + d2 + d3 - a2, y1 = a1;
    int x2 = d1 + d2 + d5 - b2, y2 = b1;
    int x3 = d1 + d3 + d5 - c2, y3 = c1;
    int s1 = -1, s2, s3, s4, s5, s6, s7;
    for (int p2 = (0); p2 <= (d2); ++p2)
      for (int p3 = (0); p3 <= (d3); ++p3) {
        int l1 = max(0, x1 - p2 - p3);
        int r1 = min(d1, y1 - p2 - p3);
        int l2 = max(x2 - p2, x3 - p3);
        int r2 = min(y2 - p2, y3 - p3);
        if (l1 > r1 || l2 > r2 || l1 > r2 || r1 + d5 < l2) continue;
        s1 = max(l1, min(l2, r1));
        s2 = p2, s3 = p3;
        s4 = max(0, x1 + d4 - s1 - s2 - s3);
        s5 = max(0, l2 - s1);
        s6 = max(0, x2 + d6 - s1 - s2 - s5);
        s7 = max(0, x3 + d7 - s1 - s3 - s5);
        break;
      }
    if (x1 + d4 > y1 || x2 + d6 > y2 || x3 + d7 > y3) s1 = -1;
    if (s1 == -1)
      puts("-1");
    else
      printf("%d %d %d %d %d %d %d\n", s1, s2, s3, s4, s5, s6, s7);
  }
  return 0;
}
