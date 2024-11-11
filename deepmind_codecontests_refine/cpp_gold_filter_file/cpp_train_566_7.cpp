#include <bits/stdc++.h>
int N, x, y;
int gcd(int a, int b) {
  int c;
  while (b) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}
char hitter[2000000];
char *name[2] = {"Vanya", "Vova"};
int main() {
  int d, i, lives, h1, h2;
  scanf("%d %d %d\n", &N, &x, &y);
  d = gcd(x, y);
  x /= d;
  y /= d;
  h1 = y;
  h2 = x;
  for (i = 0; i < x + y - 2; i++) {
    if (h1 < h2) {
      hitter[i] = 0;
      h2 -= h1;
      h1 = y;
    } else {
      hitter[i] = 1;
      h1 -= h2;
      h2 = x;
    }
  }
  for (i = 0; i < N; i++) {
    scanf("%d\n", &lives);
    lives %= (x + y);
    if (lives == 0 || lives == x + y - 1)
      printf("Both\n");
    else
      printf("%s\n", name[hitter[lives - 1]]);
  }
  return 0;
}
