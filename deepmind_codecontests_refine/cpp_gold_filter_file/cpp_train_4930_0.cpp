#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2000022;
long long qq[maxn], hh[maxn], a[maxn], ans[maxn];
long long s[maxn];
long long i, j, n, m, left, right;
long long readl() {
  long long data = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch <= '9' && ch >= '0') {
    data = data * 10 + ch - '0';
    ch = getchar();
  }
  return data;
}
void prepare() {
  long long top = 0;
  for (i = 1; i <= n; i++) {
    while (top > 0 && a[i] <= a[s[top]]) top--;
    s[++top] = i;
    if (top == 1)
      qq[i] = 0;
    else
      qq[i] = s[top - 1];
  }
  top = 0;
  for (i = n; i >= 1; i--) {
    while (top > 0 && a[i] < a[s[top]]) top--;
    s[++top] = i;
    if (top == 1)
      hh[i] = n + 1;
    else
      hh[i] = s[top - 1];
  }
}
void calc() {
  for (i = 0; i <= n * 2; i++) ans[i] = 0;
  for (i = 1; i <= n; i++) {
    long long p = i - qq[i] - 1, q = hh[i] - i - 1;
    if (p > q) swap(p, q);
    ans[1] += a[i];
    ans[p + 2] -= a[i];
    ans[q + 2] -= a[i];
    ans[p + q + 3] += a[i];
  }
  for (i = 2; i <= n; i++) ans[i] += ans[i - 1];
  for (i = 2; i <= n; i++) ans[i] += ans[i - 1];
}
int main() {
  n = readl();
  for (i = 1; i <= n; i++) a[i] = readl();
  prepare();
  calc();
  m = readl();
  for (i = 1; i <= m; i++) {
    long long x = readl();
    printf("%.9lf\n", ans[x] / (double)(n - x + 1));
  }
  return 0;
}
