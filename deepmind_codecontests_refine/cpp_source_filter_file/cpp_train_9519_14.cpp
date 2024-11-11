#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int w[3], v[3], m, k, f[maxn + 100];
int main() {
  cin >> w[1] >> w[2] >> v[1] >> m >> k;
  v[2] = 1;
  if (v[1] * m - k <= 0) {
    printf("%d\n", 0);
    return 0;
  }
  for (int i = 1; i <= 2; i++) {
    for (int j = w[i]; j <= maxn; j++) {
      f[j] = max(f[j], f[j - w[i]] + v[i]);
    }
  }
  for (int j = 0; j <= maxn; j++) {
    if (f[j] > v[1] * m - k) {
      printf("%d", j);
      return 0;
    }
  }
  return 0;
}
