#include <bits/stdc++.h>
uint32_t readu32() {
  int c;
  while ((c = getchar_unlocked()) < '0')
    ;
  uint32_t n = c & 15U;
  while ((c = getchar_unlocked()) >= '0') n = n * 10 + (c & 15U);
  return n;
}
uint64_t readu64() {
  int c;
  while ((c = getchar_unlocked()) < '0')
    ;
  uint64_t n = c & 15U;
  while ((c = getchar_unlocked()) >= '0') n = n * 10 + (c & 15U);
  return n;
}
int32_t read32() {
  int c;
  while ((c = getchar_unlocked()) < '-')
    ;
  bool neg = c == '-';
  if (neg) c = getchar_unlocked();
  uint32_t n = c & 15U;
  while ((c = getchar_unlocked()) >= '0') n = n * 10 + (c & 15U);
  return neg ? -(int32_t)n : n;
}
int64_t read64() {
  int c;
  while ((c = getchar_unlocked()) < '-')
    ;
  bool neg = c == '-';
  if (neg) c = getchar_unlocked();
  uint64_t n = c & 15;
  while ((c = getchar_unlocked()) >= '0') n = n * 10 + (c & 15U);
  return neg ? -(int64_t)n : n;
}
using namespace std;
int o[10004][4];
int main() {
  ios_base::sync_with_stdio(0);
  int n = (readu32()), m = (readu32()), q = (readu32());
  for (int i = 0; i < q; i++) {
    o[i][0] = (readu32());
    o[i][1] = (readu32()) - 1;
    if (o[i][0] == 3) {
      o[i][2] = (readu32()) - 1;
      o[i][3] = (read32());
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int ii = i, jj = j;
      int v = 0;
      for (int k = 0; k < q; k++) {
        if (o[k][0] == 1 && o[k][1] == ii)
          jj = (jj - 1 + m) % m;
        else if (o[k][0] == 2 && o[k][1] == jj)
          ii = (ii - 1 + n) % n;
        else if (o[k][0] == 3 && o[k][1] == ii && o[k][2] == jj)
          v = o[k][3];
      }
      printf("%d ", v);
    }
    putchar('\n');
  }
  return 0;
}
