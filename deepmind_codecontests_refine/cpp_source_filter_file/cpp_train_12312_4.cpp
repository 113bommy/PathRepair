#include <bits/stdc++.h>
using namespace std;
long long maxa = 0, mina = 0x3f3f3f3f, maxb = 0, minb = 0x3f3f3f3f,
          mxd = -0x3f3f3f3f, mnd = 0x3f3f3f3f;
long long ansb = 0, ansn = 0;
char s[500005];
bool check(long long mid) {
  long long minx = max(0ll, maxa - mid), maxx = mina + mid,
            miny = max(0ll, maxb - mid), maxy = minb + mid, maxd = mnd + mid,
            mind = mxd - mid;
  if (minx > maxx || miny > maxy || mind > maxd) return false;
  if (miny - maxx > maxd || maxy - minx < mind) return false;
  if (maxd >= maxy - minx && mind <= miny - maxx)
    ansn = maxx, ansb = maxy;
  else if (maxd <= maxy - maxx)
    ansn = maxx, ansb = maxx + maxd;
  else if (maxd <= maxy - minx)
    ansn = maxy - maxd, ansb = maxy;
  else if (mind >= maxy - maxx)
    ansn = maxy - mind, ansb = maxy;
  else if (mind >= miny - maxx)
    ansn = maxx, ansb = maxx + mind;
  return true;
}
int main() {
  long long i, n, j, k, t;
  scanf("%lld", &n);
  for (i = 1; i <= n; i++) {
    scanf("%s", s);
    k = strlen(s);
    long long a = 0, b = 0;
    for (j = 0; j < k; j++) {
      if (s[j] == 'N')
        a++;
      else
        b++;
    }
    mina = min(mina, a), maxa = max(a, maxa);
    minb = min(minb, b), maxb = max(b, maxb);
    mxd = max(mxd, b - a), mnd = min(mnd, b - a);
  }
  long long l = 0, r = 1;
  while (l < r) {
    long long mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  check(l);
  printf("%lld\n", l);
  for (i = 1; i <= ansb; i++) printf("B");
  for (i = 1; i <= ansn; i++) printf("N");
  printf("\n");
}
