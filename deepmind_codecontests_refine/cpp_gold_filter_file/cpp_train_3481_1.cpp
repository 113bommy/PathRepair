#include <bits/stdc++.h>
using namespace std;
char str[10];
char tb[128];
int mm[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int h1[2], kw[2], h2[2], kb[2], nb[2];
int check() {
  int i, j, p[2];
  if (h1[0] != nb[0] || h1[1] != nb[1]) {
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 8; j++) {
        p[0] = h1[0] + mm[i][0] * j;
        p[1] = h1[1] + mm[i][1] * j;
        if (p[0] == nb[0] && p[1] == nb[1]) return 1;
        if (p[0] == kw[0] && p[1] == kw[1]) break;
      }
    }
  }
  if (h2[0] != nb[0] || h2[1] != nb[1]) {
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 8; j++) {
        p[0] = h2[0] + mm[i][0] * j;
        p[1] = h2[1] + mm[i][1] * j;
        if (p[0] == nb[0] && p[1] == nb[1]) return 1;
        if (p[0] == kw[0] && p[1] == kw[1]) break;
      }
    }
  }
  if (kw[0] != nb[0] || kw[1] != nb[1]) {
    for (i = 0; i < 8; i++) {
      if (kw[0] + mm[i][0] == nb[0] && kw[1] + mm[i][1] == nb[1]) return 1;
    }
  }
  return 0;
}
int main() {
  int i;
  for (i = 0; i < 8; i++) {
    tb[i + 'a'] = i;
    tb[i + '1'] = i;
  }
  scanf("%s", str);
  h1[0] = tb[str[0]];
  h1[1] = tb[str[1]];
  scanf("%s", str);
  h2[0] = tb[str[0]];
  h2[1] = tb[str[1]];
  scanf("%s", str);
  kw[0] = tb[str[0]];
  kw[1] = tb[str[1]];
  scanf("%s", str);
  kb[0] = tb[str[0]];
  kb[1] = tb[str[1]];
  nb[0] = kb[0];
  nb[1] = kb[1];
  if (!check()) {
    puts("OTHER");
    return 0;
  }
  for (i = 0; i < 8; i++) {
    nb[0] = kb[0] + mm[i][0];
    nb[1] = kb[1] + mm[i][1];
    if (nb[0] >= 0 && nb[0] < 8 && nb[1] >= 0 && nb[1] < 8 &&
        (nb[0] != kw[0] || nb[1] != kw[1]) && !check()) {
      break;
    }
  }
  puts(i == 8 ? "CHECKMATE" : "OTHER");
  return 0;
}
