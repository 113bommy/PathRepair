#include <bits/stdc++.h>
using namespace std;
int n, i, j, t;
int a[1000011], b[1000011];
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
  scanf("%d", &t);
  for (i = 1; i <= t; ++i) scanf("%d", &j), a[j] = -a[j];
  if (a[n] > 0) a[n] = -a[n];
  t = 1;
  b[t] = a[n];
  for (i = n - 1; i; --i)
    if (a[i] < 0)
      b[++t] = a[i];
    else if (a[i] + b[t] == 0)
      --t;
    else
      a[i] = -a[i], b[++t] = a[i];
  if (t)
    printf("NO\n");
  else {
    printf("YES\n");
    for (i = 1; i < n; ++i) printf("%d ", a[i]);
    printf("%d\n", a[n]);
  }
  return 0;
}
