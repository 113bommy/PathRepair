#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int f[N];
int main() {
  int T, n, m;
  f[1] = 2;
  for (int i = 2; i <= 10000; i++) {
    f[i] = f[i - 1] + 2 * i + (i - 1);
  }
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int num = 0;
    while (n >= 2) {
      int p = lower_bound(f + 1, f + 10000 + 1, n) - f;
      if (f[p] != n) p--;
      n -= f[p];
      num++;
    }
    printf("%d\n", num);
  }
  return 0;
}
