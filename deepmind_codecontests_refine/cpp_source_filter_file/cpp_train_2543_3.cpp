#include <bits/stdc++.h>
using namespace std;
static inline void WRITE(int a) { printf("%d\n", a); }
static inline void WRITE2(int a, int b) { printf("%d %d\n", a, b); }
const int S9 = 1000000007, S6 = 1000007, S5 = 100007, S4 = 10007, S3 = 1007,
          S2 = 107;
const double E2 = 0.01, E4 = 0.0001, E6 = 0.000001, E8 = 0.00000001;
const int MOD = S9;
int tab[S3], roz[S3];
long long wyn[S3];
int main() {
  int(n);
  scanf("%d", &(n));
  ;
  for (int(i) = 0; (i) < (n); ++(i)) scanf("%d", &tab[i + 1]);
  wyn[1] = 2;
  for (int i = 2; i <= n; i++) {
    wyn[i] = (wyn[i - 1] * 2 + 2 - wyn[tab[i] - 1]) % MOD;
  }
  printf("%lld\n", wyn[n]);
}
