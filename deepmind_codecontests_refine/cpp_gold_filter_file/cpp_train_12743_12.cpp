#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
int main() {
  int n;
  scanf("%d", &n);
  int intpart, facpart, sum = 0, zeronum = 0;
  for (int i = 0; i < n * 2; ++i) {
    scanf("%d.%d", &intpart, &facpart);
    sum += facpart;
    if (facpart != 0) ++zeronum;
  }
  int L = max(0, zeronum - n);
  int R = min(zeronum, n);
  int ans = INF;
  for (int i = L; i <= R; ++i) ans = min(ans, abs(sum - i * 1000));
  printf("%d.%03d\n", ans / 1000, ans % 1000);
  return 0;
}
