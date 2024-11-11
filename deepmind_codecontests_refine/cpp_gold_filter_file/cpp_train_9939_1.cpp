#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005], c[100005], d[100005];
int main() {
  int n, m, i, j, flag;
  long long ans, w;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[a[i]]++;
  }
  flag = 1;
  for (i = 1; i <= n; i++) {
    if (b[i] & 1) {
      if (n % 2 == 1 && flag == 1)
        flag = 2;
      else if (n % 2 == 0 || flag == 2) {
        flag = 0;
        break;
      }
    }
  }
  if (flag == 0) {
    printf("0\n");
    return 0;
  }
  m = n;
  while (m > 1) {
    if (m > (n + 1) / 2) {
      c[a[m]]++;
      if (c[a[m]] > b[a[m]] / 2) break;
    } else if (n % 2 == 1 && m == n / 2 + 1) {
      if (b[a[m]] & 1)
        ;
      else
        break;
    } else {
      if (a[m] != a[n - m + 1]) break;
    }
    m--;
  }
  w = n - m + 1;
  ans = w;
  d[a[1]]++;
  if (b[a[1]] == 1) {
    printf("%lld\n", ans);
    return 0;
  }
  for (i = 2; i <= n; i++) {
    d[a[i]]++;
    while (m < i) m++;
    if (i <= n / 2 && a[i - 1] != a[n - i + 2]) m = max(m, n - i + 2);
    w = n - m + 1;
    ans += w;
    if (i > (n + 1) / 2 && a[i] != a[n - i + 1]) break;
    if (n % 2 == 1 && i == n / 2 + 1 && b[a[i]] % 2 == 0) break;
    if (i <= n / 2 && d[a[i]] > b[a[i]] / 2) break;
    if (i > (n + 1) / 2 && b[a[i]] - d[a[i]] > b[a[i]] / 2) break;
    if (i <= n / 2 && b[a[i]] == 1) break;
  }
  printf("%lld\n", ans);
  return 0;
}
