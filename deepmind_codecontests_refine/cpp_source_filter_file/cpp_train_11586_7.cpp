#include <bits/stdc++.h>
int i, j, n, m, k;
int myabs(int a) { return a < 0 ? -a : a; }
int getit(char* s) {
  int i, a = -1, b = -1;
  bool empty = 0;
  for (i = 0; s[i]; i++) {
    if (s[i] == '-') {
      empty = true;
      continue;
    }
    if (s[i] == 'G') {
      a = i;
    }
    if (s[i] == 'R') {
      b = i;
    }
  }
  if (a < 0 || b < 0) {
    if (a < 0 && b < 0) return 0;
    if (a < 0) {
      if (empty) return -2;
    }
    if (b < 0) {
      if (empty) return -1;
    }
    return 0;
  }
  return myabs(a - b);
}
inline void second() { printf("Second\n"); }
inline void first() { printf("First\n"); }
int p[1000], t;
char s[1000];
int main() {
  scanf("%d %d %d", &n, &m, &k);
  if (m == 1) {
    second();
    return 0;
  }
  bool fr = 0, se = 0;
  for (i = 1; i <= n; i++) {
    scanf("%s", s);
    j = getit(s);
    if (j == -1) {
      fr = 1;
    } else if (j == -2) {
      se = 1;
    } else {
      p[t++] = j;
    }
  }
  if (fr || se) {
    if (fr && se) {
      printf("Draw\n");
      return 0;
    }
    if (fr) {
      first();
      return 0;
    } else {
      second();
      return 0;
    }
  }
  int ii, jj;
  for (ii = 0, jj = 1; ii < 28; ii++) {
    j = 0;
    for (i = 0; i < t; i++) {
      if (p[i] & jj) {
        j++;
      }
    }
    if (j % (k + 1) != 0) {
      first();
      return 0;
    }
    jj *= 2;
  }
  second();
  return 0;
}
