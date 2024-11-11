#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, j;
  int a[1100];
  int hash[1100];
  memset(hash, 0, sizeof(hash));
  scanf("%d%d", &n, &k);
  for (i = 1; i <= k; i++) {
    cin >> a[i];
    hash[a[i]] = 1;
  }
  for (i = 1; i <= k; i++) {
    int z = 0;
    for (j = 1; j <= 1100; j++) {
      if (hash[j] == 0) {
        printf("%d ", j);
        hash[j] = 1;
        z++;
      }
      if (z == n - 1) break;
    }
    printf("%d", a[i]);
    printf("\n");
  }
  return 0;
}
