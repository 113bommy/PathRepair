#include <bits/stdc++.h>
char a[1005], b[1005];
int na, nb, n;
int main() {
  scanf("%d", &n);
  scanf("%s", a);
  na = strlen(a);
  scanf("%s", b);
  nb = strlen(b);
  int m = na * nb;
  int i = 0, j = 0, k = 0, ansa = 0, ansb = 0;
  while (k < m) {
    if (a[i] == 'R' && b[j] == 'S') ansa++;
    if (a[i] == 'S' && b[j] == 'P') ansa++;
    if (a[i] == 'P' && b[j] == 'R') ansa++;
    if (b[j] == 'R' && a[i] == 'S') ansb++;
    if (b[j] == 'S' && a[i] == 'P') ansb++;
    if (b[j] == 'P' && a[i] == 'R') ansb++;
    i++;
    j++;
    if (i == na) i = 0;
    if (j == nb) j = 0;
    k++;
  }
  ansa = ansa * (n / m);
  ansb = ansb * (n / m);
  m = n % m;
  i = 0;
  j = 0;
  k = 0;
  while (k < m) {
    if (a[i] == 'R' && b[j] == 'S') ansb++;
    if (a[i] == 'S' && b[j] == 'P') ansb++;
    if (a[i] == 'P' && b[j] == 'R') ansb++;
    if (b[j] == 'R' && a[i] == 'S') ansa++;
    if (b[j] == 'S' && a[i] == 'P') ansa++;
    if (b[j] == 'P' && a[i] == 'R') ansa++;
    i++;
    j++;
    if (i == na) i = 0;
    if (j == nb) j = 0;
    k++;
  }
  printf("%d %d\n", ansa, ansb);
}
