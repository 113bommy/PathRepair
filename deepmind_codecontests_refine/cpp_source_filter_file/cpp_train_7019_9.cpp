#include <bits/stdc++.h>
using namespace std;
const int MAXB = 16;
const int MAXN = 100005;
long long sol;
int n, q;
int a[MAXN];
struct loga {
  int l[MAXN];
  int sum(int x) {
    int ret = 0;
    for (; x > 0; x -= x & -x) ret += l[x];
    return ret;
  }
  int query(int lo, int hi) { return sum(hi) - sum(lo - 1); }
  int maxL(int x) {
    int lo = 1;
    int hi = x;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (query(mid, x) == (x - mid + 1))
        hi = mid;
      else
        lo = mid + 1;
    }
    return lo;
  }
  int maxR(int x) {
    int lo = x;
    int hi = n;
    while (lo < hi) {
      int mid = (lo + hi + 1) / 2;
      if (query(x, mid) == (mid - x + 1))
        lo = mid;
      else
        hi = mid - 1;
    }
    return lo;
  }
  void update(int x, int val) {
    for (; x <= MAXN - 5; x += x & -x) l[x] += val;
  }
};
loga L[MAXB + 5];
int main(void) {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &a[i]);
    for (int j = 0; j < MAXB; j++) {
      if ((a[i] & (1 << j)) == 0) continue;
      L[j].update(i, 1);
      int l = i - L[j].maxL(i) + 1;
      sol += (long long)l * (1 << j);
    }
  }
  for (int i = 0; i < q; i++) {
    int p, x;
    scanf("%d%d", &p, &x);
    for (int j = 0; j < MAXB; j++) {
      if ((a[p] & (1 << j)) == (x & (1 << j))) continue;
      if ((a[p] & (1 << j)) != 0)
        sol -= (long long)(1 << j) * (p - L[j].maxL(p) + 1) *
               (L[j].maxR(p) - p + 1);
      if ((a[p] & (1 << j)) == 0)
        L[j].update(p, 1);
      else
        L[j].update(p, -1);
      if ((x & (1 << j)) != 0)
        sol += (long long)(1 << j) * (p - L[j].maxL(p) + 1) *
               (L[j].maxR(p) - p + 1);
    }
    a[p] = x;
    printf("%I64d\n", sol);
  }
  return 0;
}
