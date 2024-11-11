#include <bits/stdc++.h>
using namespace std;
int ft0[200005], ft1[200005], A[200005], B[200005];
int rsq(bool bo, int b) {
  int sum = 0;
  if (bo)
    for (; b; b -= (b & (-b))) sum += ft1[b];
  else
    for (; b; b -= (b & (-b))) sum += ft0[b];
  return sum;
}
void update(int k, int v, bool bo) {
  if (bo)
    for (; k < 200001; k += (k & (-k))) ft1[k] += v;
  else
    for (; k < 200001; k += (k & (-k))) ft0[k] += v;
}
int main() {
  int n, k, a, b, q;
  scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
  while (q--) {
    int x, y, z;
    scanf("%d%d", &x, &y);
    if (x == 1) {
      scanf("%d", &z);
      update(y, min(z, a - A[y]), 1);
      update(y, min(z, b - B[y]), 0);
      A[y] = min(A[y] + z, a);
      B[y] = min(B[y] + z, b);
    } else {
      int Z = k + y - 1;
      int ans = rsq(1, n) - rsq(1, Z);
      ans += rsq(0, y - 1);
      printf("%d\n", ans);
    }
  }
  return 0;
}
