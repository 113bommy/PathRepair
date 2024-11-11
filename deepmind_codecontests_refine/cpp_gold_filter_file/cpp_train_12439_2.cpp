#include <bits/stdc++.h>
using namespace std;
using namespace std;
int pf[5000514], p[5000514], pt = 0;
int fac[5000514];
void getprime() {
  pt = 0;
  for (int i = 2; i < 5000514; i++) {
    if (pf[i] == 0) p[pt++] = pf[i] = i;
    for (int j = 0; j < pt && 1ll * i * p[j] < 5000514; j++) {
      pf[i * p[j]] = p[j];
      if (i % p[j] == 0) break;
    }
  }
  fac[1] = 0;
  for (int i = 2; i < 5000514; i++) {
    fac[i] = fac[i / pf[i]] + 1;
  }
}
long long int sum[5000514];
int a, b;
void sol() {
  scanf("%d %d", &(a), &(b));
  printf("%I64d\n", sum[a] - sum[b]);
}
int main() {
  getprime();
  sum[0] = 0;
  for (int i = 0; i < (5000514); i++)
    if (i) sum[i] = sum[i - 1] + fac[i];
  int t;
  if (scanf("%d", &(t)) != EOF) {
    for (int ti = 1; ti <= t; ti++) sol();
  }
  return 0;
}
