#include <bits/stdc++.h>
using namespace std;
long long pot[35];
int numbits(long long n) {
  int conta = 0;
  for (int i = 0; i <= 33; i++) {
    if (n & pot[i]) conta++;
  }
  return conta;
}
int main() {
  pot[0] = 1;
  for (int i = 1; i <= 33; i++) pot[i] = 2 * pot[i - 1];
  long long n, p;
  scanf("%lld %lld", &n, &p);
  if (p == 0)
    printf("%d\n", numbits(n));
  else if (p < 0) {
    int k = 0;
    bool teste = true;
    while (teste) {
      if (numbits(n - k * p) <= k) {
        printf("%d\n", k);
        teste = false;
      } else
        k++;
    }
  } else {
    int k = 0;
    bool funfa = false;
    while (k <= (n / (p + 1)) && funfa == false) {
      if (numbits(n - k * p) <= k) {
        printf("%d\n", k);
        funfa = true;
      }
      k++;
    }
    if (!funfa) printf("-1\n");
  }
}
