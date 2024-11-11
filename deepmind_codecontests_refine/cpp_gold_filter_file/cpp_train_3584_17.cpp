#include <bits/stdc++.h>
int x[100100];
void Solve1(int n) {
  if (n == 5) {
    puts("2 3 1");
    puts("1 2 2");
    puts("1 4 1");
    puts("4 5 1");
    puts("3 5");
    puts("3 4");
    return;
  }
  int k = n / 2, sum = 5;
  x[k - 1] = 1;
  for (int i = k - 2; i > 1; i--) {
    x[i] = sum - x[i + 1];
    sum += 2;
  }
  for (int i = 2; i < k; i++) printf("1 %d %d\n", i, x[i]);
  printf("1 %d 2\n", k);
  printf("1 %d 1\n", 2 * k);
  printf("%d %d 1\n", 2 * k, 2 * k + 1);
  for (int i = 2; i <= k; i++) printf("%d %d 1\n", i, i + k - 1);
  for (int i = k + 1; i < 2 * k; i++) printf("%d %d\n", i, i + 1);
  printf("%d %d\n", 2 * k - 1, 2 * k + 1);
}
void Solve2(int n) {
  if (n == 6) {
    puts("1 2 3");
    puts("1 3 1");
    puts("1 5 1");
    puts("2 4 1");
    puts("5 6 2");
    puts("3 4");
    puts("4 5");
    puts("4 6");
    return;
  }
  int k = n / 2, sum = 7;
  x[3] = 5;
  for (int i = 4; i < k; i++) {
    x[i] = sum - x[i - 1];
    sum += 2;
  }
  for (int i = 3; i < k; i++) printf("2 %d %d\n", i, x[i]);
  puts("1 2 3");
  printf("2 %d 1\n", 2 * k - 1);
  printf("%d %d 2\n", 2 * k - 1, 2 * k);
  for (int i = 1; i < k; i++) printf("%d %d 1\n", i, 2 * k - 1 - i);
  for (int i = k; i < 2 * k - 1; i++) printf("%d %d\n", i, i + 1);
  printf("%d %d\n", 2 * k - 2, 2 * k);
}
int main() {
  int n;
  scanf("%d", &n);
  if (n & 1)
    Solve1(n);
  else
    Solve2(n);
}
