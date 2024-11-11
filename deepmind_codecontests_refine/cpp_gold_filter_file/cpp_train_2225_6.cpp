#include <bits/stdc++.h>
using namespace std;
const int M1 = 111111;
int N;
int f[M1];
int d[M1];
int main() {
  scanf("%d", &N);
  int res = 1;
  for (int i = 0; i != N; ++i) {
    int tmp;
    int dlen = 0, mx = 0;
    scanf("%d", &tmp);
    for (int j = 2; j * j <= tmp; ++j) {
      if (0 == tmp % j) {
        d[dlen++] = j;
        if (f[j] + 1 > mx) mx = f[j] + 1;
        while (0 == tmp % j) tmp /= j;
      }
    }
    if (tmp > 1) {
      d[dlen++] = tmp;
      if (f[tmp] + 1 > mx) mx = f[tmp] + 1;
    }
    for (int j = 0; j != dlen; ++j) f[d[j]] = mx;
    if (res < mx) res = mx;
  }
  printf("%d\n", res);
  return 0;
}
