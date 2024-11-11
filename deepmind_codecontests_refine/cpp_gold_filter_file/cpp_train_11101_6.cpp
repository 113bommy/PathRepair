#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int main() {
  int n;
  scanf("%d", &n);
  int p[256][256];
  memset(p, 0, sizeof p);
  p[0][0] = 1, p[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    p[i][0] = p[i - 2][0];
    for (int j = 1; j < 256; j++) {
      p[i][j] = (p[i - 1][j - 1] + p[i - 2][j]) % 2;
    }
  }
  printf("%d\n", n);
  for (int i = 0; i <= n; i++) printf("%d ", p[n][i]);
  printf("\n%d\n", n - 1);
  for (int i = 0; i < n; i++) printf("%d ", p[n - 1][i]);
  printf("\n");
}
