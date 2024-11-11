#include <bits/stdc++.h>
using namespace std;
int n, a[100010];
const int s = 316;
int res[100010][320];
int getans(int p, int k) {
  int ret = 0;
  while (p <= n) {
    p = p + a[p] + k;
    ret++;
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= s; j++) {
      if (i + a[i] + j > n)
        res[i][j] = 1;
      else
        res[i][j] = res[i + a[i] + j][j] + 1;
    }
  }
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int p, k;
    scanf("%d%d", &p, &k);
    if (p <= s) {
      printf("%d\n", res[p][k]);
    } else {
      printf("%d\n", getans(p, k));
    }
  }
  return 0;
}
