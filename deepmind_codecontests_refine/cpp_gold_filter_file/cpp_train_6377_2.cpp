#include <bits/stdc++.h>
typedef struct node {
  long v;
  long c;
  long l;
  long dif;
} node;
node f[2 * 1000001];
char str[2 * 1000001];
long big[2 * 2 * 1000001];
long small[2 * 2 * 1000001];
int is_v(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
  if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return 1;
  return 0;
}
int main() {
  long i, t, count, maxl;
  long down, up;
  scanf("%s", str);
  t = strlen(str);
  memset(small, -1, sizeof(small));
  memset(big, -1, sizeof(big));
  f[0].v = f[0].c = f[0].l = 0;
  f[0].dif = 2 * 1000001;
  up = down = 2 * 1000001;
  for (i = 0; i < t; i++) {
    if (is_v(str[i])) {
      f[i + 1].v = f[i].v + 1;
      f[i + 1].c = f[i].c;
      f[i + 1].l = 0;
      f[i + 1].dif = f[i + 1].v - 2 * f[i + 1].c + 2 * 1000001;
      big[f[i + 1].dif] = i + 1;
      up = (up) > (f[i + 1].dif) ? (up) : (f[i + 1].dif);
      down = (down) < (f[i + 1].dif) ? (down) : (f[i + 1].dif);
    } else {
      f[i + 1].v = f[i].v;
      f[i + 1].c = f[i].c + 1;
      f[i + 1].l = 1;
      f[i + 1].dif = f[i + 1].v - 2 * f[i + 1].c + 2 * 1000001;
      big[f[i + 1].dif] = i + 1;
      up = (up) > (f[i + 1].dif) ? (up) : (f[i + 1].dif);
      down = (down) < (f[i + 1].dif) ? (down) : (f[i + 1].dif);
    }
  }
  small[down] = big[down];
  for (i = down + 1; i <= up; i++)
    small[i] = (small[i - 1]) > (big[i]) ? (small[i - 1]) : (big[i]);
  for (i = 0, maxl = 0; i <= t; i++) {
    if (small[f[i].dif] > i) f[i].l = small[f[i].dif] - i;
    maxl = (f[i].l) > (maxl) ? (f[i].l) : (maxl);
  }
  if (maxl == 0) {
    printf("No solution\n");
    return 0;
  }
  for (i = 0, count = 0; i <= t; i++)
    if (f[i].l == maxl) count++;
  if (!is_v(str[0]) && maxl == 1) count--;
  printf("%ld %ld\n", maxl, count);
  return 0;
}
