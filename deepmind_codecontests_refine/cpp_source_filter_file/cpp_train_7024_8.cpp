#include <bits/stdc++.h>
int Max(int a, int b, int c, int d) {
  int max = a;
  if (max < b) max = b;
  if (max < c) max = c;
  if (max < d) max = d;
  return max;
}
int pow(int a, int b) {
  long long r = 1;
  long long p = a;
  while (b) {
    if (b % 2 == 1) r = (r * p) % 1000000007;
    b /= 2;
    r = (r * r) % 1000000007;
  }
  return (int)r;
}
int main() {
  int p[1000] = {0};
  int n;
  scanf("%d%*c", &n);
  int i;
  for (i = 0; i < n; i++) {
    p[getchar()]++;
  }
  int max = 0;
  max = Max(p['A'], p['T'], p['G'], p['C']);
  int sum = 0;
  if (p['A'] == max) sum++;
  if (p['G'] == max) sum++;
  if (p['C'] == max) sum++;
  if (p['T'] == max) sum++;
  printf("%d\n", pow(sum, n));
}
