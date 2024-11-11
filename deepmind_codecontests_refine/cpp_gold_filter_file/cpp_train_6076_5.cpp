#include <bits/stdc++.h>
int m, n, ans, h;
bool in[100];
struct ele {
  int a, b, c;
} num[100050];
int cmp(struct ele c, struct ele d) { return c.a < d.a; }
int cmpc(struct ele c, struct ele d) { return c.b < d.b; }
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int main() {
  int i, j, k, x, y, z;
  scanf("%d%d", &n, &h);
  for (i = 1; i <= n; i++) {
    scanf("%d", &num[i].a);
    num[i].b = i;
  }
  std::sort(num + 1, num + 1 + n, cmp);
  x = max(num[n].a + num[n - 1].a, num[n].a + num[1].a + h) -
      min(num[1].a + num[2].a + h, num[2].a + num[3].a);
  y = num[n].a + num[n - 1].a - num[1].a - num[2].a;
  if (x < y) {
    for (i = 2; i <= n; i++) num[i].c = 2;
    num[1].c = 1;
    printf("%d\n", x);
  } else {
    for (i = 1; i <= n; i++) num[i].c = 1;
    printf("%d\n", y);
  }
  std::sort(num + 1, num + 1 + n, cmpc);
  for (i = 1; i <= n; i++) {
    if (num[1].c == 2) {
      if (num[i].c == 2)
        printf("1 ");
      else
        printf("2 ");
    } else
      printf("%d ", num[i].c);
  }
  getchar();
  getchar();
}
