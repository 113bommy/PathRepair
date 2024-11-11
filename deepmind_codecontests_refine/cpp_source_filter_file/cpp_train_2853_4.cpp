#include <bits/stdc++.h>
int i, j, size, moves, t, p1, p2, p3, aryhold[1001], ans1[100000], ans2[100000];
int main() {
  scanf("%d", &size);
  for (i = 1; i <= size; scanf("%d", aryhold + i++))
    ;
  for (p2 = 1, p3 = 2, i = 3; i <= size; ++i)
    for (p1 = i;;) {
      if (aryhold[p1] > aryhold[p2]) {
        t = p1;
        p1 = p2;
        p2 = t;
      }
      if (aryhold[p2] > aryhold[p3]) {
        t = p2;
        p2 = p3;
        p3 = t;
      }
      if (aryhold[p1] > aryhold[p2]) {
        t = p1;
        p1 = p2;
        p2 = t;
      }
      if (aryhold[p1] == 0) {
        break;
      }
      for (j = aryhold[p2] / aryhold[p1]; j; j >>= 1)
        if (j & 1) {
          ans1[++moves] = p1;
          ans2[moves] = p2;
          aryhold[p2] -= aryhold[p1];
          aryhold[p1] <<= 1;
        } else {
          ans1[++moves] = p1;
          ans2[moves] = p2;
          aryhold[p3] -= aryhold[p1];
          aryhold[p1] <<= 1;
        }
    }
  if ((aryhold[p1] == 0) + (aryhold[p2] == 0) + (aryhold[p3] == 0) != 1) {
    puts("-1");
  } else {
    for (printf("%d\n", moves), i = 1; i <= moves; ++i) {
      printf("%d %d\n", ans1[i], ans2[i]);
    }
  }
  return 0;
}
