#include <bits/stdc++.h>
int a[20000];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); i++) scanf("%d", &a[i + 1]);
  char c = 'a';
  for (int k = n - 1; k >= 0; k--) {
    int x = a[k];
    for (int j = 0; j < (int)(x); j++) {
      for (int cnt = 0; cnt < (int)(k); cnt++) printf("%c", c);
      if (c == 'a')
        c = 'b';
      else
        c = 'a';
    }
    for (int j = k; j > 0; j--) a[j] -= (k - j + 1) * x;
  }
}
