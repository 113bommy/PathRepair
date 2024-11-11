#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int cp, p[30], c[30], pc[30];
long double a[N];
char s[N];
void decompose(int x) {
  int i;
  for (i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      cp++;
      p[cp] = i;
      pc[cp] = 1;
      while (x % i == 0) {
        x /= i;
        c[cp]++;
        pc[cp] *= i;
      }
    }
  }
  if (x > 1) {
    cp++;
    p[cp] = x;
    c[cp] = 1;
    pc[cp] = x;
  }
}
int main() {
  int i, j, k;
  int n;
  long double x;
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (i = 1; i <= n; i++) a[i] = s[i] - 'a';
  decompose(n);
  for (i = 1; i <= cp; i++) {
    for (j = 1; j <= n / p[i]; j++) {
      x = 0.0;
      for (k = j; k <= n; k += n / p[i]) x += a[k];
      x /= (long double)p[i];
      for (k = j; k <= n; k += n / p[i]) a[k] -= x;
    }
  }
  for (i = 1; i <= n; i++)
    if (fabs(a[i]) >= 1e-9) {
      printf("NO\n");
      return 0;
    }
  printf("YES\n");
}
