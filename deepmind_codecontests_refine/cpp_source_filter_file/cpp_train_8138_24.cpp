#include <bits/stdc++.h>
using namespace std;
using namespace std;
long long c[500005];
long long n, m;
long long lowbit(long long x) { return x & (-x); }
void add(long long pos, long long x) {
  while (pos <= n) {
    c[pos] += x;
    pos += lowbit(pos);
  }
}
long long query(long long pos) {
  long long res = 0;
  while (pos > 0) {
    res += c[pos];
    pos -= lowbit(pos);
  }
  return res;
}
long long updata(long long x, long long y, long long k) {
  if (x > y) {
    return 0ll;
  }
  add(x, k);
  add(y + 1, -k);
  return 0ll;
}
int main() {
  memset(c, 0, sizeof(c));
  ;
  scanf("%lld%lld", &m, &n);
  long long x = 0, y;
  for (long long i = 1; i <= n; i++) {
    add(i, 0);
  }
  long long xx, yy;
  scanf("%lld", &xx);
  for (int i = 2; i <= n; i++) {
    scanf("%lld", &yy);
    int xxx, yyy;
    if (xx < yy) {
      updata(1, n, yy - xx);
      updata(xx + 1, yy - 1, -1);
      updata(xx, xx, xx - 1);
      updata(yy, yy, xx + xx - yy);
    } else if (xx == yy) {
    } else if (xx > yy) {
      swap(xx, yy);
      updata(1, n, yy - xx);
      updata(xx + 1, yy - 1, -1);
      updata(xx, xx, xx - 1);
      updata(yy, yy, xx + xx - yy);
      swap(xx, yy);
    }
    xx = yy;
  }
  for (long long i = 1; i <= m; i++) {
    printf("%lld ", query(i));
  }
  return 0;
}
