#include <bits/stdc++.h>
using namespace std;
long long int ll[4], rr[4];
long long int ans_x, ans_y, ans_z;
bool check(long long int r) {
  long long int L[4], R[4];
  int k, i;
  for (k = 0; k < 4; k++) {
    L[k] = ll[k] - r;
    R[k] = rr[k] + r;
  }
  for (k = 0; k < 4; k++) {
    if (L[k] > R[k]) return false;
  }
  for (i = 0; i < 2; i++) {
    long long int l[k], r[k];
    for (k = 0; k < 4; k++) {
      l[k] = L[k];
      r[k] = R[k];
    }
    for (k = 0; k < 4; k++) {
      if (abs(l[k]) % 2 != i) l[k]++;
      if (abs(r[k]) % 2 != i) r[k]--;
    }
    l[0] = max(l[0], l[1] + l[2] + l[3]);
    r[0] = min(r[0], r[1] + r[2] + r[3]);
    if (l[0] > r[0]) continue;
    if (l[1] > r[1]) continue;
    if (l[2] > r[2]) continue;
    if (l[3] > r[3]) continue;
    long long int s1 = l[1], s2 = l[2], s3 = l[3];
    s1 = min(r[1], l[0] - s2 - s3);
    s2 = min(r[2], l[0] - s1 - s3);
    s3 = min(r[3], l[0] - s1 - s2);
    ans_x = (s2 + s3) / 2;
    ans_y = (s1 + s3) / 2;
    ans_z = (s1 + s2) / 2;
    return true;
  }
  return false;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 4; i++) {
      ll[i] = -1e100;
      rr[i] = 1e100;
    }
    for (int i = 0; i < n; i++) {
      long long int x, y, z;
      scanf("%lld%lld%lld", &x, &y, &z);
      ll[0] = max(ll[0], x + y + z);
      rr[0] = min(rr[0], x + y + z);
      ll[1] = max(ll[1], -x + y + z);
      rr[1] = min(rr[1], -x + y + z);
      ll[2] = max(ll[2], x - y + z);
      rr[2] = min(rr[2], x - y + z);
      ll[3] = max(ll[3], x + y - z);
      rr[3] = min(rr[3], x + y - z);
    }
    long long int l = -1, r = 1e18, m;
    while (l + 1 != r) {
      m = (l + r) / 2;
      if (check(m))
        r = m;
      else
        l = m;
    }
    printf("%lld %lld %lld\n", ans_x, ans_y, ans_z);
  }
}
