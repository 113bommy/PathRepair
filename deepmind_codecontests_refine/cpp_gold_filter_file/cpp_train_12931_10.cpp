#include <bits/stdc++.h>
int main() {
  long long int n, m, q, k;
  scanf("%lld %lld", &n, &m);
  char s[n + 1][11], t[m + 1][11], buffer;
  for (long long i = 0; i < n; i++) {
    scanf("%s", s[i]);
    buffer = getchar();
  }
  for (long long j = 0; j < m; j++) {
    scanf("%s", t[j]);
    buffer = getchar();
  }
  scanf("%lld", &q);
  for (long long h = 0; h < q; h++) {
    scanf("%lld", &k);
    printf("%s", s[(k - 1) % n]);
    printf("%s", t[(k - 1) % m]);
    printf("\n");
  }
  return 0;
}
