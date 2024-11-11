#include <bits/stdc++.h>
long n, m, way, number, s, f, t, flag;
int main() {
  scanf("%d %d", &n, &m);
  for (long i = 0; i < n; i++) {
    scanf("%d %d %d", &s, &f, &t);
    number = 0;
    way = 0;
    flag = 0;
    number = t % (2 * m - 2);
    if (number > (m - 1)) {
      way = 0;
      number = m - number % (m - 1);
      flag = 1;
    }
    if ((number == m - 1) && (!flag)) {
      way = 0;
      number = m;
      flag = 1;
    }
    if ((number < (m - 1)) && (!flag)) {
      way = 1;
      number++;
    }
    if (s == f) {
      printf("0\n");
      continue;
    }
    if ((s < f) && (way == 1) && (number <= s)) {
      printf("%d\n", f - number + t);
      continue;
    }
    if ((s < f) && (way == 1) && (number > s)) {
      printf("%d\n", m - number + m - 1 + f - 1 + t);
      continue;
    }
    if ((s < f) && (way == 0)) {
      printf("%d\n", number - 1 + f - 1 + t);
      continue;
    }
    if ((s > f) && (way == 1)) {
      printf("%d\n", m - number + m - f + t);
      continue;
    }
    if ((s > f) && (way == 0) && (number >= s)) {
      printf("%d\n", number - f + t);
      continue;
    }
    if ((s > f) && (way == 0) && (number < s)) {
      printf("%d\n", number - 1 + m - 1 + m - f + t);
      continue;
    }
  }
}
