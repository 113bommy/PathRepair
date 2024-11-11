#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
const int M = 10000 + 10;
const int Q = 1000 + 10;
const int A = 30 + 1;
char s1[A], s2[A];
int main() {
  scanf("%s%s", s1, s2);
  int x1 = s1[0] - 96, y1 = s1[1] - 48;
  int x2 = s2[0] - 96, y2 = s2[1] - 48;
  int x = abs(x1 - y1), y = abs(x2 - y2);
  int t = max(x, y);
  printf("%d\n", t);
  int s = min(x, y);
  for (int i(1); i <= (s); ++i) {
    if (x1 > x2 && y1 > y2)
      puts("LD"), --x1, --y1;
    else if (x1 > x2 && y1 < y2)
      puts("LU"), --x1, ++y1;
    else if (x1 < x2 && y1 > y2)
      puts("RD"), ++x1, --y1;
    else if (x1 < x2 && y1 < y2)
      puts("RU"), ++x1, ++y1;
  }
  for (int i(1); i <= (t - s); ++i) {
    if (x1 > x2)
      puts("L"), --x1;
    else if (x1 < x2)
      puts("R"), ++x1;
    else if (y1 > y2)
      puts("D"), --y1;
    else if (y1 < y2)
      puts("U"), ++y1;
  }
  return 0;
}
