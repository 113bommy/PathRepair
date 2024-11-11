#include <bits/stdc++.h>
using namespace std;
const int maxint = -1u >> 1;
long long cal(long long y, long long x) {
  long long i, j, k = 0;
  while (x >= y) {
    k++;
    x /= y;
  }
  return k;
}
long long qp(long long x, long long y) {
  if (y == 0 || y == -1) return 1;
  if (y == 1) return x;
  long long res = qp(x, y / 2);
  if (y % 2 == 1)
    return res * res * x;
  else
    return res * res;
}
priority_queue<long long> q;
int main() {
  long long i, j, k, l, r, x, y, m, n, ans = 0, lef1, rig1, lef2, rig2;
  scanf("%I64d %I64d %I64d %I64d", &x, &y, &l, &r);
  lef1 = cal(x, l);
  rig1 = cal(x, r);
  lef2 = cal(y, l);
  rig2 = cal(y, r);
  for (i = 0; i <= rig1; i++) {
    for (j = 0; j <= rig2; j++) {
      k = qp(y, j);
      m = qp(x, i);
      if (m + k > r) break;
      if (m + k < l) continue;
      q.push(m + k);
    }
  }
  for (i = 0; i <= rig2; i++) {
    for (j = 0; j <= rig1; j++) {
      m = qp(x, j);
      k = qp(y, i);
      if (m + k > r) break;
      if (m + k < l) continue;
      q.push(m + k);
    }
  }
  if (q.empty()) ans = r - l + 1;
  r++;
  k = -1;
  while (!q.empty()) {
    k = q.top();
    q.pop();
    ans = max(ans, r - k - 1);
    r = k;
  }
  if (k != -1) ans = max(ans, k - l);
  printf("%I64d\n", ans);
  return 0;
}
