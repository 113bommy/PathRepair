#include <bits/stdc++.h>
using namespace std;
int n, m, k;
long long C[1005][1005];
int main() {
  scanf("%d %d %d", &n, &m, &k);
  int M = max(n, m);
  for (int n = 0; n <= M; n++)
    for (int r = 0; r <= 2 * k; r++) {
      if (r == 0)
        C[n][r] = 1;
      else if (n == 0)
        C[n][r] = 0;
      else
        C[n][r] = (C[n - 1][r - 1] + C[n - 1][r]) % 1000000007;
    }
  printf("%d\n", (int)((C[n - 1][2 * k] * C[m - 1][2 * k]) % 1000000007));
  return 0;
}
