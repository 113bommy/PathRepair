#include <bits/stdc++.h>
using namespace std;
int x[9], y[9];
int de[8] = {0};
int sum() {
  int a = 0;
  for (int i = 0; i < 8; i++) a += de[i];
  return a;
}
bool sq() {
  bool sqq = false;
  int a[4], b[4], co = 0;
  for (int i = 0; i < 8; i++) {
    if (de[i] == 0) {
      a[co] = x[i];
      b[co] = y[i];
      co++;
    }
  }
  for (int i = 1; i < 4; i++) {
    a[i] -= a[0];
    b[i] -= b[0];
  }
  for (int i = 1; i < 4 && !sqq; i++)
    for (int j = 1; j < 4 && !sqq; j++) {
      if (a[i] * a[j] + b[i] * b[j] == 0 && a[i] + a[j] == a[6 - i - j] &&
          b[i] + b[j] == b[6 - i - j] && (a[i] == b[j] || a[i] == -b[j]) &&
          (a[j] == b[i] || a[j] == -b[i])) {
        sqq = true;
      }
    }
  bool re = false;
  co = 0;
  for (int i = 0; i < 8; i++) {
    if (de[i] == 1) {
      a[co] = x[i];
      b[co] = y[i];
      co++;
    }
  }
  for (int i = 1; i < 4; i++) {
    a[i] -= a[0];
    b[i] -= b[0];
  }
  for (int i = 1; i < 4 && !re; i++)
    for (int j = 1; j < 4 && !re; j++) {
      if (a[i] * a[j] + b[i] * b[j] == 0 && a[i] + a[j] == a[6 - i - j] &&
          b[i] + b[j] == b[6 - i - j]) {
        re = true;
      }
    }
  return sqq && re;
}
int main() {
  bool ans = false;
  for (int i = 0; i < 8; i++) scanf("%d %d", &x[i], &y[i]);
  for (int i = 0; i < 256; i++) {
    if (sum() == 4) {
      if (sq()) {
        ans = true;
        break;
      }
    }
    de[7]++;
    for (int i = 7; i > 0; i--) {
      de[i - 1] += de[i] / 2;
      de[i] %= 2;
    }
  }
  if (ans) {
    puts("YES");
    for (int i = 0; i < 8; i++)
      if (de[i] == 0) printf("%d ", i + 1);
    printf("\n");
    for (int i = 0; i < 8; i++)
      if (de[i] == 1) printf("%d ", i + 1);
    printf("\n");
  } else
    puts("NO");
  scanf(" ");
  return 0;
}
