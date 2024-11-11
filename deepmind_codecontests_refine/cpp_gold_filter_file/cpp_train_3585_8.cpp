#include <bits/stdc++.h>
int cmp(const void *a, const void *b) { return (*(int *)b - *(int *)a); }
int main() {
  int n, k, i, c = 0;
  char s[201], ch;
  scanf("%d", &(n));
  scanf("%s", (s));
  for (i = 0; i < n; i++)
    if (s[i] == 'x') c++;
  k = n / 2;
  if (c > k)
    ch = 'X';
  else
    ch = 'x';
  k = abs(k - c);
  printf("%d", (k)), printf("\n");
  for (i = 0; i < n; i++) {
    if (k) {
      if (s[i] != ch) s[i] = ch, k--;
    } else
      break;
  }
  printf("%s", (s));
  printf("\n");
  return 0;
}
