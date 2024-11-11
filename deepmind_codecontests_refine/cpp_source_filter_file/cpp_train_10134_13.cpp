#include <bits/stdc++.h>
int n, a, d, i, j, top;
double t, s[100010];
int v[100010], st[100010], r[100010];
int main() {
  scanf("%d%d%d", &n, &a, &d);
  for (i = 1; i <= n; ++i) {
    scanf("%d%d", &st[i], &v[i]);
    t = v[i] * 1.0 / a;
    if (v[i] / 2 * t > d)
      t = sqrt(2 * a * d * 1.0) / a;
    else
      t += d * 1.0 / v[i] - t / 2;
    t += st[i];
    if (t > s[top]) s[++top] = t;
    r[top] = i;
  }
  for (i = 1; i <= top; ++i) {
    for (j = r[i - 1] + 1; j <= r[i]; ++j) printf("%.10lf\n", s[i]);
  }
}
