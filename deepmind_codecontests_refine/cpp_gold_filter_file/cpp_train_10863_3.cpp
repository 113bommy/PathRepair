#include <bits/stdc++.h>
const int N = 200009;
double ans, sum1[29], sum2[29];
char s[N], q[N];
int i, x, y, n;
int main() {
  scanf("%d%s%s", &n, s, q);
  for (i = 0; i < n; i++) {
    x = s[i] - 'A';
    sum1[x] += (i + 1);
    y = q[i] - 'A';
    ans += (n - i) * 1.0 * (sum1[y] + sum2[x]);
    sum2[y] += (i + 1);
  }
  printf("%lf", (double)ans / n / (n + 1) / ((n << 1) | 1) * 6);
}
