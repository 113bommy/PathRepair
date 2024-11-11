#include <bits/stdc++.h>
using namespace std;
int c[2000100];
int l, t;
double calc(int n) {
  int i, j;
  long long s = 0;
  for (i = 0; i < n; i++) {
    c[i + n] = c[i] + l;
  }
  for (i = 0, j = 0; i < n; i++) {
    while (c[j] - c[i] <= t) j++;
    s += j - i - 1;
  }
  return s * 0.5;
}
int main() {
  int n, i, j;
  double a, b, s;
  scanf("%d %d %d", &n, &l, &t);
  t *= 2;
  s = 0.5 * (t / l) * (double)(n - 1) * (double)n;
  t %= l;
  for (i = 0; i < n; i++) {
    scanf("%d", &c[i]);
  }
  a = calc(n);
  for (i = 0, j = n - 1; i < j; i++, j--) {
    swap(c[i], c[j]);
  }
  for (i = 0; i < n; i++) {
    c[i] = l - c[i] - 1;
  }
  b = calc(n);
  printf("%.10f\n", (s + (a + b) / 2) / 2);
  return 0;
}
