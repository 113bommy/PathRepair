#include <bits/stdc++.h>
int main() {
  char ch, map[10][10];
  long i, x;
  while (gets(map[0])) {
    if (map[0][0] == '\0') break;
    gets(map[1]);
    gets(map[2]);
    if (map[0][1] == '>') {
      ch = map[0][0];
      map[0][0] = map[0][2];
      map[0][2] = ch;
    }
    if (map[1][1] == '>') {
      ch = map[1][0];
      map[1][0] = map[1][2];
      map[1][2] = ch;
    }
    if (map[2][1] == '>') {
      ch = map[2][0];
      map[2][0] = map[2][2];
      map[2][2] = ch;
    }
    long c[10], max, hand;
    c[0] = c[1] = c[2] = max = 0;
    for (i = 0; i <= 2; i++) {
      x = map[i][0] - 'A';
      c[x]++;
      if (c[x] > max) {
        max = c[x];
        hand = x;
      }
    }
    if (max < 2)
      printf("impossible\n");
    else {
      for (i = 0; i <= 2; i++) {
        x = map[i][0] - 'A';
        if (x != hand) break;
      }
      printf("%c%c%c\n", hand + 'A', map[i][0], map[i][2]);
    }
  }
  return 0;
}
