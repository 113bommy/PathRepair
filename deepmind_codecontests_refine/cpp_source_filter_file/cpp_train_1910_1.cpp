#include <bits/stdc++.h>
using namespace std;
const int maxn = 251;
int f[1000001];
long long x[maxn], y[maxn];
int n, m;
void solve(int i, int j) {
  long long a, b, c, x0;
  a = y[i] - y[j];
  if (a == 0) return;
  b = x[j] - x[i];
  c = x[j] * y[i] - x[i] * y[j];
  if (c % a) return;
  x0 = c / a;
  int s = 1;
  if (x0 >= 1 && x0 <= n) {
    for (int k = 0; k < j; k++)
      if (a * x[k] + b * y[k] == c) s++;
    f[x0] = max(f[x0], s);
  }
}
int main() {
  int i, j;
  scanf("%d%d", &n, &m);
  for (i = 0; i < m; i++) scanf("%I64d%I64d", &x[i], &y[i]);
  for (i = 2; i < m; i++)
    for (j = 1; j < i; j++) solve(i, j);
  for (j = 0, i = 1; i <= n; i++) j += f[i] + 1;
  printf("%d\n", j);
  return 0;
}
