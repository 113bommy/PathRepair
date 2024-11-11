#include <bits/stdc++.h>
int main(void) {
  long long int k;
  int n, pow1, cont = 0, pow2;
  scanf("%d %lli\n", &n, &k);
  scanf("%d", &pow1);
  for (int i = 1; i < n; i++) {
    scanf("%d", &pow2);
    if (pow1 < pow2) {
      pow1 = pow2;
      cont = 1;
    } else
      cont++;
    if (cont >= k) break;
  }
  printf("%d", pow1);
}
