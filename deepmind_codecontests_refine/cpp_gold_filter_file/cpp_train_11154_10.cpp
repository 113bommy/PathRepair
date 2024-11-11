#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
const long double eps = 0.2;
struct node {
  long long x, y;
} q[N << 1], p;
long long Q, n, L, R, l, r, op, a, b;
long long sumb, sumk;
long double cross(node p, node a, node b) {
  return (long double)(a.x - p.x) * (b.y - p.y) -
         (long double)(a.y - p.y) * (b.x - p.x);
}
void addL(long long x, long long y) {
  p = (node){x, y};
  while (r - l >= 1 && cross(p, q[l], q[l + 1]) < -eps) l++;
  q[--l] = p;
}
void addR(long long x, long long y) {
  p = (node){x, y};
  while (r - l >= 1 && cross(p, q[r], q[r - 1]) > eps) r--;
  q[++r] = p;
}
long long f(long long p) { return q[p].y + sumb + q[p].x * sumk; }
void qry() {
  long long low = l, high = r, mid, fl, fr, now, best = 2e18, id = 0;
  while (high - low > 4) {
    mid = (low + high) >> 1;
    fl = f(mid), fr = f(mid + 1);
    if (fl <= fr)
      high = mid + 1;
    else
      low = mid;
  }
  for (int i = (low); i <= (high); i++) {
    now = f(i);
    if (now < best) {
      best = now;
      id = q[i].x;
    }
  }
  printf("%lld %lld\n", id - L + 1, best);
}
int main() {
  scanf("%lld%lld", &n, &Q);
  L = 1, R = n;
  l = N + 1, r = N;
  addL(L, 0);
  if (n >= 2) addR(R, 0);
  while (Q--) {
    scanf("%lld", &op);
    if (op == 1) {
      scanf("%lld", &a);
      addL(L - 1, -sumb - sumk * (L - 1));
      L -= a;
      if (a >= 2) addL(L, -sumb - sumk * L);
    } else if (op == 2) {
      scanf("%lld", &a);
      addR(R + 1, -sumb - sumk * (R + 1));
      R += a;
      if (a >= 2) addR(R, -sumb - sumk * R);
    } else {
      scanf("%lld%lld", &a, &b);
      sumb += a - L * b, sumk += b;
    }
    qry();
  }
  return 0;
}
