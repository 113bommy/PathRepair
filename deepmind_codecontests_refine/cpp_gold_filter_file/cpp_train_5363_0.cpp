#include <bits/stdc++.h>
char s[105];
int main() {
  int n, p, q;
  scanf("%d%d%d", &n, &p, &q);
  scanf("%s", s);
  if (n < p && n < q) {
    puts("-1");
    return 0;
  }
  if (n % p == 0) {
    printf("%d\n", n / p);
    for (int i = 0; i < n; i++) {
      if (i % p == 0 && i != 0) printf("\n");
      printf("%c", s[i]);
    }
    return 0;
  }
  if (n % q == 0) {
    printf("%d\n", n / q);
    for (int i = 0; i < n; i++) {
      if (i % q == 0 && i != 0) printf("\n");
      printf("%c", s[i]);
    }
    return 0;
  }
  int pos = 0;
  for (; pos < n + 1; pos += p)
    if ((n - pos) % q == 0) break;
  if (pos >= n)
    puts("-1");
  else {
    int j = 0;
    printf("%d\n", pos / p + (n - pos) / q);
    for (int i = 0; i < pos / p; i++) {
      for (int k = 0; k < p; k++, j++) printf("%c", s[j]);
      printf("\n");
    }
    for (int i = 0; i < (n - pos) / q; i++) {
      for (int k = 0; k < q; k++, j++) printf("%c", s[j]);
      printf("\n");
    }
  }
  return 0;
}
