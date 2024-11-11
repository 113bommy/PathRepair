#include <bits/stdc++.h>
using namespace std;
const long long maxn = 5000 + 100;
const long long maxk = 5000 + 100;
struct pii {
  long long x, v, y;
  pii(long long xx = 0, long long vv = 0, long long yy = 0) {
    x = xx;
    v = vv;
    y = yy;
  }
  bool operator<(const pii& b) const {
    if (x == b.x) return v < b.v;
    return x < b.x;
  }
};
vector<pii> v;
long long n;
int main() {
  long long k, x, y, m, ans = 0, a, b;
  scanf("%I64d", &n);
  for (long long i = 1; i <= n; i++) {
    long long cur = 0;
    scanf("%I64d%I64d%I64d%I64d%I64d", &k, &a, &x, &y, &m);
    v.push_back(pii(cur, a, i));
    for (long long j = 2; j <= k; j++) {
      b = (a * x + y) % m;
      if (b < a) {
        cur++;
      }
      v.push_back(pii(cur, b, i));
      a = b;
    }
    ans = max(ans, cur);
  }
  printf("%I64d\n", ans);
  sort(v.begin(), v.end());
  for (long long i = 0; i < v.size(); i++) {
    printf("%I64d %I64d\n", v[i].v, v[i].y);
  }
  return 0;
}
