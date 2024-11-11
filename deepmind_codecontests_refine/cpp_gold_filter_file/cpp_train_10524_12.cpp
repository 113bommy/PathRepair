#include <bits/stdc++.h>
int main() {
  int m;
  scanf("%d", &m);
  struct result {
    int roll;
    int e, g, m, h;
  } st[1000];
  int p = 1, A = 0, B = 0, i;
  for (i = 0; i < m; i++) {
    scanf("%d%d%d%d", &st[i].e, &st[i].g, &st[i].m, &st[i].h);
  }
  A = st[0].e + st[0].g + st[0].m + st[0].h;
  for (i = 1; i < m; i++) {
    B = st[i].e + st[i].g + st[i].m + st[i].h;
    if (B > A) {
      p = p + 1;
    }
  }
  printf("%d", p);
  return 0;
}
