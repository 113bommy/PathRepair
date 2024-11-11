#include <bits/stdc++.h>
using namespace std;
void speed() { ios::sync_with_stdio(false); }
struct node {
  long long l, r;
  bool operator<(const node &A) const {
    if (l == A.l) return r < A.r;
    return l < A.l;
  }
} l[1000005], r[1000005], h[1000005], d[1000005];
long long n;
long long totl = 0, totr = 0, toth = 0, totd = 0;
long long le, re, he, de;
long long check(long long a, long long b, long long x, long long y) {
  if (a > b || x > b || y < a) return 0ll;
  return min(b, y) - max(a, x) + 1;
}
long long ask() {
  long long sum = 0;
  long long l1 = de, r1 = he - 1, l2 = le, r2 = re - 1, l3 = de + 1, r3 = he,
            l4 = le + 1, r4 = re;
  for (long long i = 1; i <= n; i++) {
    if (i <= totl)
      sum += check(l1, r1, l[i].l, l[i].r), l1 = max(l1, l[i].r + 1);
    if (i <= toth)
      sum += check(l2, r2, h[i].l, h[i].r), l2 = max(l2, h[i].r + 1);
    if (i <= totr)
      sum += check(l3, r3, r[i].l, r[i].r), l3 = max(l3, r[i].r + 1);
    if (i <= totd)
      sum += check(l4, r4, d[i].l, d[i].r), l4 = max(l4, d[i].r + 1);
  }
  return (re - le + he - de) * 2 - sum;
}
int main() {
  speed();
  scanf("%lld%lld%lld%lld", &le, &he, &re, &de);
  if (le > re) swap(le, re);
  if (de > he) swap(de, he);
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    long long x, y, len;
    scanf("%lld%lld%lld", &x, &y, &len);
    if (len >= x - le)
      l[++totl].l = y - floor(sqrt(len * len - (x - le) * (x - le))),
      l[totl].r = y + floor(sqrt(len * len - (x - le) * (x - le)));
    if (len >= x - re)
      r[++totr].r = y - floor(sqrt(len * len - (x - re) * (x - re))),
      r[totr].r = y + floor(sqrt(len * len - (x - re) * (x - re)));
    if (len >= y - he)
      h[++toth].l = x - floor(sqrt(len * len - (y - he) * (y - he))),
      h[toth].r = x + floor(sqrt(len * len - (y - he) * (y - he)));
    if (len >= y - de)
      d[++totd].l = x - floor(sqrt(len * len - (y - de) * (y - de))),
      d[totd].r = x + floor(sqrt(len * len - (y - de) * (x - de)));
  }
  sort(l + 1, l + totl + 1);
  sort(r + 1, r + totr + 1);
  sort(h + 1, h + toth + 1);
  sort(d + 1, d + totd + 1);
  printf("%lld\n", ask());
  return 0;
}
