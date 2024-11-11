#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:100000000")
int f[100500], x[100500];
int use[100500], win[100500];
int main() {
  f[0] = 0;
  f[1] = 0;
  f[2] = 0;
  int n, i, j;
  scanf("%d", &n);
  for (i = 3; i <= n; ++i) {
    win[i] = -1;
    for (j = 2; j * j + j <= 2 * i; ++j) {
      if ((2 * i + j - j * j) % (2 * j) == 0) {
        int a0 = (2 * i + j - j * j) / (2 * j);
        use[x[a0 + j - 1] ^ x[a0 - 1]] = i;
        if ((x[a0 + j - 1] ^ x[a0 - 1]) == 0 && win[i] == -1) win[i] = j;
      }
    }
    for (j = 0; use[j] == i; ++j)
      ;
    f[i] = j;
    x[i] = x[i - 1] ^ f[i];
  }
  if (f[n] == 0)
    printf("%d\n", -1);
  else
    printf("%d\n", win[n]);
  return 0;
}
