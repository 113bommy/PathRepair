#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d\n", &n);
  char s[n];
  gets(s);
  int a[n], k = 0, i, max = 0;
  for (i = 0; i < n; i++) a[i] = 0;
  for (i = 0; i < n; i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') a[k]++;
    if (s[i] == ' ') k++;
  }
  for (i = 0; i <= k; i++) {
    if (a[i] > max) max = a[i];
  }
  printf("%d", max);
}
