#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 20;
long long a[MAXN];
int main() {
  int n, k;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%I64d", &a[i]);
  }
  long long ans = 0;
  long long orl = 0, nor = 0;
  for (int i = 0, j = n; i < j; ++i) {
    orl += a[i];
    while (i < j && nor < orl) {
      nor += a[j - 1];
      --j;
    }
    if (orl == nor) ans = orl;
  }
  printf("%I64d\n", ans);
  return 0;
}
