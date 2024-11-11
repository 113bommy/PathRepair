#include <bits/stdc++.h>
using namespace std;
int n;
struct point {
  int x, y;
} a, s;
int ret[10];
int main() {
  scanf("%d%d%d", &n, &s.x, &s.y);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a.x, &a.y);
    if (a.x < s.x && a.y < s.y) {
      ret[4]++, ret[1]++, ret[2]++;
    } else if (a.x == s.x && a.y < s.y) {
      ret[2]++;
    } else if (a.x > s.x && a.y < s.y) {
      ret[2]++, ret[3]++, ret[6]++;
    } else if (a.x > s.x && a.y == s.y) {
      ret[6]++;
    } else if (a.x > s.x && a.y > s.y) {
      ret[6]++, ret[9]++, ret[8]++;
    } else if (a.x == s.x && a.y > s.y)
      ret[8]++;
    else if (a.x < s.x && a.y > s.y) {
      ret[4]++, ret[7]++, ret[8]++;
    } else if (a.x < s.x && a.y == s.y)
      ret[4]++;
  }
  int num = 0, cnt;
  for (int i = 1; i <= 9; i++) {
    if (ret[i] > num) num = ret[i], cnt = i;
  }
  if (cnt == 1)
    printf("%d\n%d %d", ret[1], s.x - 1, s.y - 1);
  else if (cnt == 2)
    printf("%d\n%d %d", ret[2], s.x, s.y - 1);
  else if (cnt == 3)
    printf("%d\n%d %d", ret[3], s.x + 1, s.y - 1);
  else if (cnt == 4)
    printf("%d\n%d %d", ret[4], s.x - 1, s.y);
  else if (cnt == 6)
    printf("%d\n%d %d", ret[6], s.x + 1, s.y);
  else if (cnt == 7)
    printf("%d\n%d %d", ret[7], s.x - 1, s.y + 1);
  else if (cnt == 8)
    printf("%d\n%d %d", ret[8], s.x, s.y + 1);
  else if (cnt == 9)
    printf("%d\n%d %d", ret[9], s.x + 1, s.y + 1);
}
