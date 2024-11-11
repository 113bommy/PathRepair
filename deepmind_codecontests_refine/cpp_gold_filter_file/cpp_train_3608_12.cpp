#include <bits/stdc++.h>
int main() {
  long n, i, somme = 0, s = 0;
  int tab[200000];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &tab[i]);
    somme = somme + tab[i];
  }
  i = 0;
  do {
    s = s + tab[i];
    i = i + 1;
  } while (s < ((somme + 1) / 2));
  printf("%d\n", i);
  return 0;
}
