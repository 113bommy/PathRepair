#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000000;
long long Sum[MAXN + 1];
int isprime[MAXN + 1];
int prime[MAXN + 1];
void getPrime() {
  memset(prime, 0, sizeof(prime));
  memset(isprime, 0, sizeof(isprime));
  for (int i = 2; i <= MAXN; i++) {
    if (!prime[i]) prime[++prime[0]] = i, isprime[i]++;
    for (int j = 1; j <= prime[0] && prime[j] <= MAXN / i; j++) {
      prime[prime[j] * i] = 1;
      isprime[prime[j] * i] = (isprime[i] + 1);
    }
  }
}
int main() {
  getPrime();
  memset(Sum, 0, sizeof(Sum));
  for (int i = 1; i <= 5000000; i++) {
    Sum[i] = Sum[i - 1] + isprime[i];
  }
  int t, a, b;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &a, &b);
    printf("%I64d\n", Sum[a] - Sum[b]);
  }
  return 0;
}
