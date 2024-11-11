#include <bits/stdc++.h>
using namespace std;
void read(int &x) {
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
}
struct Point {
  int x, y, z;
} L[2000000 + 1], R[2000000 + 1];
int a[2000000 + 1];
int n, m;
int main() {
  read(n), read(m);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= n; i++)
    if (!L[a[i]].x) L[a[i]].x = i;
  for (int i = n; i >= 1; i--)
    if (!R[a[i]].x) R[a[i]].x = i;
  L[m].z = L[m].x ? L[m].x : n + 1;
  for (int i = m - 1; i >= 1; i--)
    L[i].z = L[i].x ? min(L[i + 1].z, L[i].x) : L[i + 1].z;
  R[1].z = R[1].x ? R[1].x : 0;
  for (int i = 2; i <= m; i++)
    R[i].z = R[i].x ? max(R[i].x, R[i - 1].z) : R[i - 1].z;
  for (int i = 2, x = R[1].x ? R[1].x : 0; i <= m; i++) {
    L[i].y = L[i - 1].y || (L[i].x ? (L[i].x < x) : 0);
    if (R[i].x && R[i].x > x) x = R[i].x;
  }
  for (int i = m - 1, x = L[m].x ? L[m].x : n + 1; i; i--) {
    R[i].y = R[i + 1].y || (R[i].x ? (R[i].x > x) : 0);
    if (L[i].x && L[i].x < x) x = L[i].x;
  }
  long long ans = 0;
  for (int i = 1; i <= m; i++) {
    if (i > 1 && L[i - 1].y) break;
    int l = i, r = m, mid = 0, k = m + 1;
    while (l <= r) {
      mid = l + r >> 1;
      if ((mid == m || !R[mid + 1].y) &&
          (i == 1 || mid == m || L[mid + 1].z > R[i - 1].z))
        r = (k = mid) - 1;
      else
        l = mid + 1;
    }
    ans += m - k + 1;
  }
  printf("%lld\n", ans);
  return 0;
}
