#include <bits/stdc++.h>
using namespace std;
int taked[32];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int x;
  for (int i = 1; i <= k; i++) {
    scanf("%d", &x);
    taked[x] = i;
  }
  for (int i = 1; i <= k; i++) {
    int c = 1;
    for (int j = 1; j <= n * k; j++)
      if (taked[j] == i) printf("%d", j);
    for (int j = 1; j <= n * k; j++)
      if (taked[j] == 0 && c < n) {
        printf(" %d", j);
        taked[j] = i;
        c++;
      }
    printf("\n");
  }
  return 0;
}
