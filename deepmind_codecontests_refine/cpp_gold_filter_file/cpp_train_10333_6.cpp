#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 11234;
bool is[MAX];
int n;
int f(int in) { return n - (n - 1) / in - 1 - in + 1; }
int main() {
  scanf("%d", &n);
  int x = 2;
  for (int i = 2; i < n; i++)
    if (f(x) < f(i)) x = i;
  if (0) printf("x=%d\n", x);
  while (1) {
    int p = 0;
    for (int i = 0; i < n; i++)
      if (i % x)
        if (!is[i]) p++;
    if (p < x) {
      int sum = 0;
      for (int i = 0; i < n; i++) sum += is[i];
      if (0) printf("S %d\n", sum);
      printf("0\n");
      return 0;
    }
    printf("%d", p);
    for (int i = 0; i < n; i++)
      if (i % x)
        if (!is[i]) {
          printf(" %d", i + 1);
          is[i] = 1;
        }
    printf("\n");
    fflush(stdout);
    int in;
    scanf("%d", &in);
    in--;
    for (int i = 0; i < p; i++) is[(in + i) % n] = 0;
  }
  return 0;
}
