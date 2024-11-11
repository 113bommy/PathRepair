#include <bits/stdc++.h>
char string[30];
int count[26];
char answer[2][14];
int main(void) {
  int x;
  int p, q;
  int u, v, w;
  int i;
  scanf("%s", string);
  for (i = 0; i < 27; ++i) ++count[string[i] - 'A'];
  for (i = 0; i < 26; ++i)
    if (count[i] > 1) break;
  x = i + 'A';
  p = q = -1;
  for (i = 0; i < 27; ++i)
    if (string[i] == x && p == -1)
      p = i;
    else if (string[i] == x)
      q = i;
  if (q - p == 1) {
    puts("Impossible");
    return 0;
  }
  if (q - p == 26) {
    for (i = 0; i < 13; ++i) putchar(string[i]);
    putchar('\n');
    for (i = 26 - 1; i >= 13; --i) putchar(string[i]);
    putchar('\n');
    return 0;
  }
  x = (q - p - 1) / 2;
  x = 13 - x - 1;
  u = 0;
  v = x;
  w = p;
  for (i = 0; i < 26; ++i) {
    answer[u][v] = string[w];
    ++w;
    if (w == q) ++w;
    w %= 27;
    if (u == 0) ++v;
    if (u == 1) --v;
    if (v == 13) u = 1, v = 12;
    if (v == -1) u = 0, v = 0;
  }
  printf("%s\n%s\n", answer[0], answer[1]);
  return 0;
}
