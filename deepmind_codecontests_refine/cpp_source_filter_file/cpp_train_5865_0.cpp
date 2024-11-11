#include <bits/stdc++.h>
long long a[204800], b[102400], l, c, t, s;
int n, v1, v2, i, j, k;
long long m(long long a, long long b) { return a < b ? a : b; }
long long M(long long a, long long b) { return a < b ? b : a; }
int main() {
  for (scanf("%d%d%d%d", &n, &l, &v1, &v2), c = l * v2, l *= v1 + v2; ++i <= n;
       a[i] *= v1 + v2)
    scanf("%d", a + i);
  for (; ++j <= n;) a[i++] = a[j] + l * 2;
  a[0] = a[n] - l * 2;
  for (i = j = 1; i <= n; ++i) {
    for (; a[j + 1] < a[i - 1] + c; ++j)
      ;
    if (a[i] > a[i - 1] + c) b[0] += a[i] - a[i - 1] - c;
    for (k = j; a[k] < a[i] + c; ++k)
      b[k - i + 1] += m(a[i], a[k + 1] - c) - M(a[i - 1], a[k] - c);
  }
  for (i = 0; i <= n; ++i) printf("%.16lf\n", b[i] * 0.5 / l);
  return 0;
}
