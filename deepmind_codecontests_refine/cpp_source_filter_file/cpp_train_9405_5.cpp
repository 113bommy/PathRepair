#include <bits/stdc++.h>
using namespace std;
char a[1000010];
char b[1000010];
char c[1000010];
int main(void) {
  int n, m, T, t, k, B, C1, ln;
  long long C;
  char z[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
              'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  scanf("%d", &t);
  while (t--) {
    memset(a, 0, sizeof(a));
    scanf("%s", a);
    B = 0;
    C = 0;
    C1 = 0;
    T = 0;
    ln = strlen(a);
    for (int i = 1; i < ln - 1; i++) {
      if ((a[i + 1] == 'C') && (a[i] <= '9' && a[i] >= '0')) {
        T = 1;
        break;
      }
    }
    if (T == 1) {
      k = 0;
      for (int i = 1; i < ln; i++) {
        if (a[i] == 'C') {
          k = 1;
          continue;
        }
        if (k == 1) {
          C *= 10;
          C += a[i] - 48;
        } else {
          b[B] = a[i];
          B++;
        }
      }
      while (C > 0) {
        if (C % 26 != 0)
          c[C1] = z[(C % 26) - 1];
        else {
          c[C1] = 'Z';
          C -= 26;
        }
        C /= 26;
        C1++;
      }
      for (int i = C1 - 1; i >= 0; i--) printf("%c", c[i]);
      for (int i = 0; i < B; i++) printf("%c", b[i]);
      printf("\n");
    } else {
      k = 0;
      for (int i = 0; i < ln; i++) {
        if (a[i] <= 'Z' && a[i] >= 'A' && k == 0) {
          C *= 26;
          C += a[i] - 64;
        } else
          k = 1;
        if (k == 1) {
          c[C1] = a[i];
          C1++;
        }
      }
      printf("R");
      for (int i = 0; i < C1; i++) printf("%c", c[i]);
      printf("C%lld\n", c, C);
    }
  }
  return 0;
}
