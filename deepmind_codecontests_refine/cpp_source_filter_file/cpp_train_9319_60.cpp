#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int v1[1010], v2[1010];
  long long int tam;
  scanf("%lld", &tam);
  for (int i = 0; i < tam; i++) {
    scanf("%lld", &v1[i]);
  }
  for (int i = 0; i < tam; i++) {
    scanf("%lld", &v2[i]);
  }
  long long int sum1 = 0, max1 = 0, sum2 = 0;
  for (int l = 0; l < tam - 1; l++) {
    for (int r = l + 1; r < tam; r++) {
      sum1 |= v1[r];
      sum2 |= v2[r];
      max1 = max(sum1 + sum2, max1);
    }
    max1 = max(sum1 + sum2, max1);
    sum1 = 0;
    sum2 = 0;
  }
  printf("%lld\n", max1);
  return 0;
}
