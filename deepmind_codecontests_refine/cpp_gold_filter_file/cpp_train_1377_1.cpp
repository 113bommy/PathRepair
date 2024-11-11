#include <bits/stdc++.h>
int main() {
  int t, j;
  scanf("%d", &t);
  for (j = 1; j <= t; j++) {
    int n, d = 0, i;
    char a[100000], b[100000], c[100000];
    scanf("%s %s %s", a, b, c);
    n = strlen(a);
    for (i = 0; i < n; i++) {
      if (a[i] == c[i] || b[i] == c[i]) d++;
      if (a[i] == b[i] && b[i] != c[i]) break;
    }
    if (d == n)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
