#include <bits/stdc++.h>
using namespace std;
bool debug = 1;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long long ln, lk, lm;
long long a[3105];
long long x[3105], y[3105], t1, t2, b[3105];
int tot;
int main() {
  scanf("%d%d", &n, &k);
  for (int(i) = 0; (i) < (int)(n); (i)++) scanf("%lld", a + i);
  for (int i = 0, j; i < n; i++) {
    for (j = i; j < n && a[j] < a[j + 1]; j++)
      ;
    if (i == j) continue;
    while (t1 && x[t1] > a[i]) {
      b[++tot] = x[t1--] - y[t2--];
    }
    x[++t1] = a[i];
    while (t2 && y[t2] < a[j]) {
      b[++tot] = x[t1--] - y[t2--];
    }
    y[++t2] = a[j];
  }
  while (t2) b[++tot] = x[t1--] - y[t2--];
  k = min(tot, k);
  nth_element(b + 1, b + k, b + tot + 1);
  long long ans = 0;
  for (int(i) = 1; (i) <= (int)(k); (i)++) ans -= b[i];
  printf("%lld\n", ans);
  return 0;
}
