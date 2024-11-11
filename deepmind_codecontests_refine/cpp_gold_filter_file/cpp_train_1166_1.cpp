#include <bits/stdc++.h>
int min(int num1, int num2, int num3);
int main() {
  int t, s, v, j, e, f, l, p, q, sum;
  scanf("%d%d%d%d%d%d", &t, &s, &v, &j, &e, &f);
  if (e >= f) {
    if (j > t) {
      q = t * e;
      j = j - t;
      if (j > 0) {
        l = min(s, v, j);
        p = l * f;
      }
    } else {
      q = j * e;
      p = 0;
    }
  } else if (f > e) {
    l = min(s, v, j);
    j = j - l;
    p = l * f;
    if (j > 0) {
      if (j > t) {
        q = t * e;
      } else {
        q = j * e;
      }
    } else {
      q = 0;
    }
  }
  sum = p + q;
  printf("%d", sum);
}
int min(int num1, int num2, int num3) {
  if (num1 < num2 && num1 < num3) {
    return num1;
  } else if (num2 < num3) {
    return num2;
  } else {
    return num3;
  }
}
