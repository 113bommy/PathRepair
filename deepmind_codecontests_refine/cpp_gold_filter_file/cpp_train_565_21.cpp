#include <bits/stdc++.h>
const int MAXN = 2010;
int n;
char s[MAXN];
int a[MAXN];
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  int t = 0;
  for (int i = 1; i <= n; ++i) {
    s[n + i] = s[i];
    if (s[i] == 'H') ++t;
  }
  a[0] = 0;
  for (int i = 1; i <= 2 * n; ++i) {
    if (s[i] == 'H')
      a[i] = a[i - 1] + 1;
    else
      a[i] = a[i - 1];
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i)
    if (a[i + t] - a[i] > ans) ans = a[i + t] - a[i];
  printf("%d\n", t - ans);
}
