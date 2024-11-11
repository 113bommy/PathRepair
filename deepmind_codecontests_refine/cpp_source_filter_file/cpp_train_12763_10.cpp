#include <bits/stdc++.h>
using namespace std;
const int N = 1000010, mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double eps = 1e-6;
int n;
int p[N], te[N];
long long ztot, zcnt, ftot, fcnt;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
    if (p[i] - i > 0) {
      zcnt++;
      ztot += p[i] - i;
      te[p[i] - i]++;
    } else {
      fcnt++;
      ftot += (i - p[i]);
    }
  }
  long long ans = ftot + ztot, id = 0;
  for (int i = 1; i < n; i++) {
    ztot -= zcnt;
    zcnt -= te[i];
    ftot += fcnt;
    fcnt += te[i];
    int x = p[n - i + 1];
    ftot -= n + 1 - x;
    fcnt--;
    if (x > 1)
      te[x - 1 + i]++, ztot += x - 1, zcnt++;
    else
      fcnt++;
    if (ans > ztot + ftot) ans = ztot + ftot, id = i;
  }
  printf("%lld %lld\n", ans, id);
  return 0;
}
