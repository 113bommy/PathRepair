#include <bits/stdc++.h>
int main(int argc, const char* argv[]) {
  float a = 0, b = 0, c = 0, n = 0;
  int s = 0, f = 0;
  do {
    scanf("%f", &n);
  } while (n < 1 || n > 10000);
  for (a = 1; a <= n; a++) {
    for (b = 1; b <= n; b++) {
      c = sqrt(a * a + b * b);
      f = c;
      if (a <= b && b <= c && c <= n && f - c == 0) {
        s++;
      }
    }
  }
  printf("%d\n", s);
  return 0;
}
