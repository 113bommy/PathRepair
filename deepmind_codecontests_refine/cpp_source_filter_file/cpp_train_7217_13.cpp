#include <bits/stdc++.h>
using namespace std;
int MAX, n;
double a[21][21], f[530000];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%lf", &a[i][j]);
    }
  }
  MAX = (1 << n) - 1;
  f[MAX] = 1;
  for (int i = MAX - 1; i; i--) {
    int cnt = 0, tmp = i;
    while (tmp) {
      cnt += (tmp & 1);
      tmp >>= 1;
    }
    for (int j = 1; j <= n; j++) {
      if ((1 << j - 1) & i) continue;
      for (int k = 1; k <= n; k++) {
        if (!((1 << k - 1) & i)) continue;
        f[i] += (double)f[i | (1 << j - 1)] * a[k][j] / (cnt * (cnt + 1) / 2);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%.3lf ", f[1 << i - 1]);
  }
}
