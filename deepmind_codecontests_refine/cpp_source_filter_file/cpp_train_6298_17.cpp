#include <bits/stdc++.h>
using namespace std;
const int nm = 100010;
int n, m, k;
int l[nm], r[nm];
long long d[nm];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%I64d", &l[i], &r[i], &d[i]);
  }
  long long res = 0;
  for (int i = 1; i <= k; ++i) {
    int u;
    scanf("%d", &u);
    for (int j = 1; j <= m; ++j) {
      if (u >= l[j] && u <= r[j]) {
        res += (long long)(u - l[j] + 1);
      }
    }
  }
  printf("%I64d\n", res);
}
