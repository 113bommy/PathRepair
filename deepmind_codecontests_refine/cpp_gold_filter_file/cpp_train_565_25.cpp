#include <bits/stdc++.h>
int main() {
  int n, sumh = 0, sumt = 0;
  char s[1010];
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; i < n; i++)
    if (s[i] == 'H')
      sumh++;
    else
      sumt++;
  int max = 0;
  if (sumt < sumh) {
    for (int i = 0; i < n; i++) {
      int l = 0;
      for (int j = 0; j < sumt; j++)
        if (s[(i + j) % n] == 'T') l++;
      if (l > max) max = l;
    }
    printf("%d\n", sumt - max);
  } else {
    max = 0;
    for (int i = 0; i < n; i++) {
      int l = 0;
      for (int j = 0; j < sumh; j++)
        if (s[(i + j) % n] == 'H') l++;
      if (l > max) max = l;
    }
    printf("%d\n", sumh - max);
  }
}
