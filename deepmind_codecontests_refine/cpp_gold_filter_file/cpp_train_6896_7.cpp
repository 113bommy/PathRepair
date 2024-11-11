#include <bits/stdc++.h>
using namespace std;
int T, n, k;
char ch[200];
inline void ask(int x, int y, int xx, int yy) {
  printf("? %d %d\n", y - x + 1, yy - xx + 1);
  for (int i = x; i <= y; i++) printf("%d ", i);
  puts("");
  for (int i = xx; i <= yy; i++) printf("%d ", i);
  puts("");
  fflush(stdout);
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    bool flag = false;
    for (int i = 2; i <= 30; i++) {
      int x = rand() % (n - 1) + 2;
      ask(1, 1, x, x);
      scanf("%s", ch);
      if (ch[0] == 'W') {
        return 0;
      } else if (ch[0] == 'S') {
        flag = true;
        break;
      }
    }
    if (flag) {
      puts("! 1");
      fflush(stdout);
      continue;
    }
    int tl = 1, tr = 1, lx = 2, rx = 2;
    while (true) {
      ask(tl, tr, lx, rx);
      scanf("%s", ch);
      if (ch[0] == 'W') {
        return 0;
      } else if (ch[0] == 'F')
        break;
      if (rx == n) break;
      tr = rx;
      lx = tr + 1, rx = min(n, tr * 2);
      tl = tr - (rx - lx + 1) + 1;
    }
    int mid, tas = -1, L = lx;
    while (lx <= rx) {
      mid = (lx + rx) >> 1;
      ask(tl, tl + mid - L, L, mid);
      scanf("%s", ch);
      if (ch[0] == 'W')
        return 0;
      else if (ch[0] == 'E')
        tas = mid, lx = mid + 1;
      else
        rx = mid - 1;
    }
    if (tas == -1)
      printf("! %d\n", lx);
    else
      printf("! %d\n", tas + 1);
    fflush(stdout);
  }
}
