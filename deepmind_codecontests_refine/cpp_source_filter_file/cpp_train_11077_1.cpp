#include <bits/stdc++.h>
using namespace std;
struct xx {
  int s;
  int l;
  int r;
};
xx a[100005];
int xp, kt, n, m;
int check1(int xp, int step) {
  if (xp >= a[step].l && xp <= a[step].r) return 0;
  if (xp + 1 >= a[step].l && xp + 1 <= a[step].r) return 0;
  return 1;
}
int check2(int xp, int step) {
  if (xp >= a[step].l && xp <= a[step].r) return 0;
  if (xp - 1 >= a[step].l && xp - 1 <= a[step].r) return 0;
  return 1;
}
void solve() {
  int i, x, y, z, step, j;
  for (i = 1; i <= m; i++) {
    scanf("%d %d %d", &x, &y, &z);
    a[i].s = x;
    a[i].l = y;
    a[i].r = z;
  }
  step = 0;
  if (xp < kt) {
    for (i = 1; i <= m; i++) {
      {
        for (j = a[i - 1].s; j < a[i].s - 1; j++) {
          printf("R"), xp++;
          if (xp == kt) {
            printf("\n");
            return;
          }
        }
      }
      if (check1(xp, i) == 1) {
        printf("R"), xp++;
        if (xp == kt) {
          printf("\n");
          return;
        }
      } else
        printf("X");
    }
  } else {
    for (i = 1; i <= m; i++) {
      {
        for (j = a[i - 1].s; j < a[i].s - 1; j++) {
          printf("L"), xp--;
          if (xp == kt) {
            printf("\n");
            return;
          }
        }
      }
      if (check2(xp, i) == 1) {
        printf("L"), xp--;
        if (xp == kt) {
          printf("\n");
          return;
        }
      } else
        printf("X");
    }
  }
  if (xp < kt)
    for (i = xp; i < kt; i++) printf("R");
  else
    for (i = kt; i > xp; i--) printf("L");
  printf("\n");
}
int main() {
  while (scanf("%d %d %d %d", &n, &m, &xp, &kt) > 0) solve();
  return 0;
}
