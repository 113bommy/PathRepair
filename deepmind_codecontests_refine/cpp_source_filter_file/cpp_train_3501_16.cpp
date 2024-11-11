#include <bits/stdc++.h>
int main() {
  char ch[1000], c1, c2;
  int i, j, l, r, n, m;
  scanf("%d %d", &n, &m);
  getchar();
  gets(ch);
  for (i = 0; i < m; i++) {
    scanf("%d %d %c %c", &l, &r, &c1, &c2);
    for (j = l - 1; j <= r; j++) {
      if (ch[j] == c1) {
        ch[j] = c2;
      }
    }
  }
  printf(ch);
}
