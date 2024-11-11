#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:65000000")
using namespace std;
long long n, m;
long long mas[22][10005];
long long ans[22][10005];
int main() {
  scanf("%I64d", &(n));
  --n;
  scanf("%I64d", &(m));
  for (long long i = 1; i <= n; ++i) mas[0][i] = 1;
  for (int k = 1; k <= m; ++k) {
    for (int j = 0; j <= n; ++j) {
      ans[k][j] =
          lower_bound(mas[k - 1], mas[k - 1] + n + 1, j - mas[k - 1][j]) -
          mas[k - 1];
      mas[k][j] = mas[k - 1][j] + mas[k - 1][ans[k][j]];
    }
    for (int j = n; j >= 0; --j)
      printf("%I64d%c", n - ans[k][j] + 1, j == 0 ? '\n' : ' ');
  }
  return 0;
}
