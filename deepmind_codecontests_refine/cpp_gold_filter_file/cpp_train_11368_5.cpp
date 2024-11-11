#include <bits/stdc++.h>
int n;
int p[1000], P = 0;
char c[1011];
int x[1011] = {0};
int al[200] = {0};
int posi[1011], POSI = 0;
char ans[1011];
int main() {
  int i, j, k, r, t, tt;
  for (i = 0; i < 1001; i++) ans[i] = 'C';
  char C;
  p[0] = 2;
  P = 1;
  for (i = 3; i <= 1000; i++) {
    k = 1;
    for (j = 0; j < P; j++) {
      if (i % p[j] == 0) {
        k = 0;
        break;
      }
    }
    if (k == 1) {
      p[P] = i;
      P++;
    }
  }
  scanf("%s", c);
  n = strlen(c);
  for (i = 0; i < P; i++) {
    k = p[i];
    if (k * 2 > n) break;
    t = 1;
    while (k * t <= n) {
      x[k * t] = 1;
      t++;
    }
  }
  k = 0;
  for (i = 1; i <= n; i++) {
    if (x[i] == 1) {
      posi[k] = i;
      k++;
    }
  }
  for (i = 0; i < n; i++) {
    al[c[i]]++;
  }
  t = -1;
  for (i = 0; i < 199; i++) {
    if (al[i] > t) {
      t = al[i];
      r = i;
    }
  }
  if (t >= k) {
    printf("YES\n");
    for (i = 0; i < k; i++) {
      ans[posi[i] - 1] = (char)(r);
      C = r;
      for (j = 0; j < n; j++) {
        if (c[j] == r) {
          c[j] = 'A';
          break;
        }
      }
    }
    for (i = 0; i < n; i++) {
      tt = 0;
      if (ans[i] == (char)(r)) {
        i = i;
      } else {
        for (j = 0; j < n; j++) {
          if (c[j] != 'A' && c[j] != 'B') {
            ans[i] = c[j];
            c[j] = 'B';
            break;
          }
        }
      }
    }
    for (i = 0; i < n; i++) printf("%c", ans[i]);
  } else
    printf("NO");
  scanf(" ");
  return 0;
}
