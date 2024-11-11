#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long A, B, C, L[4], R[4];
long long a[N][4];
int n, t;
bool check(long long x) {
  for (int i = 0; i < 4; i++) L[i] = a[1][i] - x, R[i] = a[1][i] + x;
  for (int i = 2; i <= n; i++)
    for (int j = 0; j < 4; j++) {
      L[j] = max(L[j], a[i][j] - x);
      R[j] = min(R[j], a[i][j] + x);
    }
  for (int i = 0; i < 2; i++) {
    long long l0 = L[0] + ((L[0] & 1) == i), r0 = R[0] - ((R[0] & 1) == i);
    long long l1 = L[1] + ((L[1] & 1) == i), r1 = R[1] - ((R[1] & 1) == i);
    long long l2 = L[2] + ((L[2] & 1) == i), r2 = R[2] - ((R[2] & 1) == i);
    long long l3 = L[3] + ((L[3] & 1) == i), r3 = R[3] - ((R[3] & 1) == i);
    if (l0 > r0 || l1 > r1 || l2 > r2 || l3 > r3 || l1 + l2 + l3 > r0) continue;
    if (l1 + l2 + l3 < l0) l1 = min(r1, l0 - l2 - l3);
    if (l1 + l2 + l3 < l0) l2 = min(r2, l0 - l1 - l3);
    if (l1 + l2 + l3 < l0) l3 = min(r3, l0 - l1 - l2);
    if (l1 + l2 + l3 < l0) continue;
    A = (l2 + l3) / 2, B = (l3 + l1) / 2, C = (l1 + l2) / 2;
    return true;
  }
  return false;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      long long x, y, z;
      scanf("%lld%lld%lld", &x, &y, &z);
      a[i][0] = x + y + z, a[i][1] = -x + y + z;
      a[i][2] = x - y + z, a[i][3] = x + y - z;
    }
    long long l = 0, r = 4e18;
    while (l < r) {
      long long mid = (l + r) >> 1;
      if (check(mid))
        r = mid;
      else
        l = ++mid;
    }
    printf("%lld %lld %lld\n", A, B, C);
  }
  return 0;
}
