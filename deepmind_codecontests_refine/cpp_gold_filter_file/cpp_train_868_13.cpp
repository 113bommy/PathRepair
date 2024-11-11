#include <bits/stdc++.h>
using namespace std;
FILE *fi = fopen("file.in", "r");
FILE *fo = fopen("file.out", "w");
int cmp(void const *x, void const *y) {
  long a = *(long *)x;
  long b = *(long *)y;
  return a - b;
}
long n, m, d1, d2, d3, t1, t2, t3, k, t;
char s[5000100];
long sum[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
long x[5000100];
int main() {
  for (int i = 1; i <= 13; i++) sum[i] += sum[i - 1];
  scanf("%ld %ld", &n, &m);
  gets(s);
  while (gets(s)) {
    sscanf(s, "%d-%d-%d %d:%d:%d: %*s", &d1, &d2, &d3, &t1, &t2, &t3);
    x[t++] = ((((sum[d2 - 1] + d3) * 24 + t1) * 60) + t2) * 60 + t3;
    if (t >= m && x[t - 1] - x[t - m] < n) {
      k = 1;
      s[19] = 0;
      printf("%s\n", s);
      break;
    }
  }
  if (!k) printf("-1\n");
  getchar();
  getchar();
}
