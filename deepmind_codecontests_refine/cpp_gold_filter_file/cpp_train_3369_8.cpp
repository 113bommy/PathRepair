#include <bits/stdc++.h>
using namespace std;
long long int mat[110][110];
int main() {
  long long int k;
  scanf("%lld", &k);
  memset(mat, 0, sizeof(mat));
  long long int i = 0, v = 1, j = 0;
  while (k > 0) {
    if (k < i) i = 0, v++;
    mat[v][i] = 1;
    mat[i][v] = 1;
    k -= i;
    i++;
    if (i >= v && k > 0) i = 0, v++;
  }
  printf("%lld\n", v + 1);
  for (i = 0; i <= v; i++) {
    for (j = 0; j <= v; j++) {
      printf("%lld", mat[i][j]);
    }
    printf("\n");
  }
  return 0;
}
