#include <bits/stdc++.h>
using namespace std;
const long long inf = 4 * 1e18;
struct point {
  long long x[3];
};
point pt[110000], ans;
int n, t;
long long low, high, mid, xp[8];
double mat[10][4];
long long lo[3], hi[3];
bool check(long long dist) {
  int i, j, s, p, q;
  long long a1, b1, c1, a2, b2, c2;
  double a, b, c;
  for (i = 0; i < 8; i++) {
    xp[i] = inf;
    for (j = 0; j < n; j++) {
      long long now = dist;
      for (s = 0; s < 3; s++) {
        if (i & (1 << s))
          now += pt[j].x[s];
        else
          now -= pt[j].x[s];
      }
      if (xp[i] > now) xp[i] = now;
    }
  }
  for (i = 7; i >= 4; i--) {
    if (xp[i] < -xp[7 - i]) return false;
  }
  long long vl;
  vl = min(xp[7] + xp[4], xp[5] + xp[6]);
  if (vl < 0)
    vl = (vl - 1) / 2;
  else
    vl = vl / 2;
  hi[2] = vl;
  vl = max(-xp[0] - xp[3], -xp[2] - xp[1]);
  if (vl < 0)
    vl = vl / 2;
  else
    vl = (vl + 1) / 2;
  lo[2] = vl;
  if (lo[2] > hi[2]) return false;
  long long nlo[3], nhi[3];
  for (vl = lo[2]; vl <= hi[2]; vl++) {
    ans.x[2] = vl;
    nhi[1] = min(xp[7] - vl, xp[3] + vl);
    nlo[1] = max(-xp[0] - vl, -xp[4] + vl);
    nhi[0] = min(xp[5] - vl, xp[1] + vl);
    nlo[0] = max(-xp[2] - vl, -xp[6] + vl);
    if (nlo[1] > nhi[1]) continue;
    if (nlo[0] > nhi[0]) continue;
    hi[0] = nhi[0] + nhi[1];
    if (hi[0] < 0)
      hi[0] = (hi[0] - 1) / 2;
    else
      hi[0] = hi[0] / 2;
    lo[0] = nlo[0] + nlo[1];
    if (lo[0] < 0)
      lo[0] /= 2;
    else
      lo[0] = (lo[0] + 1) / 2;
    if (lo[0] > hi[0]) continue;
    for (long long sv = lo[0]; sv <= hi[0]; sv++) {
      ans.x[0] = sv;
      hi[1] = min(nhi[1] - sv, -nlo[0] + sv);
      lo[1] = max(nlo[1] - sv, -nhi[0] + sv);
      if (lo[1] <= hi[1]) {
        ans.x[1] = lo[1];
        return true;
      }
    }
  }
  return false;
}
int main() {
  int i, j, s, p, q, tst;
  scanf("%d", &t);
  for (tst = 0; tst < t; tst++) {
    scanf("%d", &n);
    for (i = 0; i < n; i++)
      scanf("%I64d%I64d%I64d", &pt[i].x[0], &pt[i].x[1], &pt[i].x[2]);
    low = 0;
    high = inf;
    while (low <= high) {
      mid = (low + high) >> 1;
      if (check(mid))
        high = mid - 1;
      else
        low = mid + 1;
    }
    check(low);
    printf("%I64d %I64d %I64d\n", ans.x[0], ans.x[1], ans.x[2]);
  }
}
