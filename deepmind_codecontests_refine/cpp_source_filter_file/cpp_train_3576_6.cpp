#include <bits/stdc++.h>
struct Card {
  int v, s;
};
int n;
Card c[52];
int can[52][52][52][52];
bool check(int c1, int c2) { return c[c1].v == c[c2].v || c[c1].s == c[c2].s; }
bool gao(int p, int c1, int c2, int c3) {
  if (p == 1) {
    return true;
  } else if (p == 2) {
    return check(c1, c2);
  }
  if (can[p][c1][c2][c3] == -1) {
    int& t = can[p][c1][c2][c3] = 0;
    if (check(c1, c2) && gao(p - 1, c1, c3, p - 3)) {
      t = 1;
    } else if (p > 3 && check(c1, p - 3) && gao(p - 1, c2, c3, c1)) {
      t = 1;
    }
  }
  return can[p][c1][c2][c3] == 1;
}
bool gao() {
  if (n == 1) {
    return true;
  } else if (n == 2) {
    return check(0, 1);
  }
  memset(can, -1, sizeof(can));
  return gao(n - 1, n - 1, n - 2, n - 3);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    char buf[3];
    scanf("%s", buf);
    char ch = buf[0];
    if (ch >= '2' && ch <= '9') {
      c[i].v = ch - '0';
    } else {
      c[i].v = ch == 'T'   ? 10
               : ch == 'J' ? 11
               : ch == 'Q' ? 12
               : ch == 'K' ? 13
                           : 1;
    }
    ch = buf[1];
    c[i].s = ch == 'S' ? 0 : ch == 'D' ? 1 : ch == 'H' ? 2 : 3;
  }
  puts(gao() ? "YES" : "NO");
  return 0;
}
