#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int n, k;
int e[N + 5][N + 5];
int main() {
  scanf("%d %d", &n, &k);
  int c = 1;
  for (int t = 1; t < n; t *= k, c++)
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
        if (i / t % k != j / t % k) e[i][j] = c;
  printf("%d\n", c - 1);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) printf("%d ", e[i][j]);
  printf("\n");
  return 0;
}
