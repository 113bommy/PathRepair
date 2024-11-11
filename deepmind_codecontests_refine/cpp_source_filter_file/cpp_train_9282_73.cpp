#include <bits/stdc++.h>
int cmp123(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int cmp321(const void *a, const void *b) { return (*(int *)b - *(int *)a); }
void scan_and_sort(int table[], int n, int sort) {
  for (int i = 0; i < n; i++) scanf("%d", &table[i]);
  if (sort == 123) qsort(table, n, sizeof(int), cmp123);
  if (sort == 321) qsort(table, n, sizeof(int), cmp321);
  return;
}
int gcd(int a, int b) {
  int tmp;
  while (a % b) {
    tmp = a % b;
    a = b;
    b = tmp;
  }
  return b;
}
int isPrime(int n) {
  int m = sqrt(n);
  for (int i = 2; i <= m; i++)
    if (n % i == 0) return 0;
  return 1;
}
int main(int argc, char const *argv[]) {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  (a >= b && a >= c) ? printf("Yes\n") : printf("No\n");
  return 0;
}
