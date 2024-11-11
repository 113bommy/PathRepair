#include <bits/stdc++.h>
using namespace std;
int n, f[2][200];
int main() {
  f[0][0] = f[1][1] = 1;
  int t = 1;
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    t = i & 1;
    for (int j = 1; j <= i; ++j) f[t][j] = (f[t][j] + f[t ^ 1][j - 1]) & 1;
  }
  printf("%d\n", n);
  for (int i = 0; i <= n; ++i) printf("%d ", f[t][i]);
  printf("\n%d\n", n - 1);
  for (int i = 0; i < n; ++i) printf("%d ", f[t ^ 1][i]);
  return 0;
}
