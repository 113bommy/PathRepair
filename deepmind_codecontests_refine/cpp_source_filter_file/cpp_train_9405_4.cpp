#include <bits/stdc++.h>
char c[1000009], d[10009];
int arr[1000];
int main() {
  int n, i, j, k, l, m, o, p, z, x, y;
  scanf("%d", &n);
  while (n--) {
    scanf("%s", &c);
    getchar();
    j = strlen(c);
    if (c[0] == 'R' && (c[1] < 64)) {
      l = 0;
      for (i = 2; i < j; i++) {
        if (c[i] == 'C') {
          l = 1;
          break;
        }
      }
      if (l == 0) {
        printf("R");
        for (i = 1; i < j; i++) printf("%c", c[i]);
        printf("C");
        printf("%d\n", c[0]);
      } else {
        k = 0;
        for (l = i + 1; l < j; l++) {
          m = c[l] - 48;
          k *= 10;
          k += m;
        }
        l = 26;
        m = 26;
        for (i = 1;; i++) {
          if (l >= k) {
            l -= m;
            break;
          }
          m *= 26;
          l += m;
        }
        z = k - l;
        m /= 26;
        p = 0;
        for (o = 0; o < i; o++) {
          x = z / m;
          if (z % m == 0) {
            d[p++] = 64 + x;
            x--;
          } else
            d[p++] = 65 + x;
          z -= (x * m);
          m /= 26;
          printf("%c", d[p - 1]);
        }
        for (i = 1; c[i] != 'C'; i++) printf("%c", c[i]);
        printf("\n");
      }
    } else {
      k = 1;
      l = 0;
      for (i = 0; c[i] > 60; i++) {
        p = 1;
      }
      p = 1;
      for (z = i - 1; z >= 0; z--) {
        k = c[z] - 64;
        k *= p;
        l += k;
        p *= 26;
      }
      printf("R");
      for (i = i; i < j; i++) printf("%c", c[i]);
      printf("C");
      printf("%d\n", l);
    }
  }
}
