#include <bits/stdc++.h>
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int genre[11];
  int i;
  for (i = 1; i <= m; i++) {
    genre[i] = 0;
  }
  for (i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    genre[a]++;
  }
  long long options = 0;
  for (i = 1; i < m; i++) {
    if (genre[i] > 0) {
      options += genre[i] * (n - genre[i]);
      n = n - genre[i];
    }
  }
  printf("%lld\n", options);
  return 0;
}
