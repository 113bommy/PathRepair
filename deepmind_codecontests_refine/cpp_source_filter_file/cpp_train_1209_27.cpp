#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
int n, q;
long long a[maxn];
long long ans[maxn];
int pos[maxn];
int block;
int num[maxn];
int L, R;
long long s0;
struct query {
  int l, r;
  int loc;
  int id;
  bool operator<(const query &res) const {
    if (loc == res.loc)
      return r < res.r;
    else
      return loc < res.loc;
  }
} Query[maxn << 1];
void init() {
  block = (int)sqrt(n);
  memset(num, 0, sizeof(num));
  memset(pos, 0, sizeof(pos));
  s0 = 0;
  L = R = 1;
}
void add(long long x) {
  s0 = s0 + 2 * (long long)num[x] * x + x;
  num[x]++;
}
void sub(long long x) {
  s0 = s0 - 2 * (long long)num[x] * x + x;
  num[x]--;
}
int main() {
  scanf("%d%d", &n, &q);
  init();
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    pos[i] = i / block;
  }
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &Query[i].l, &Query[i].r);
    Query[i].loc = pos[Query[i].l];
    Query[i].id = i;
  }
  sort(Query + 1, Query + q + 1);
  add(a[1]);
  for (int i = 1; i <= q; i++) {
    int l = Query[i].l;
    int r = Query[i].r;
    while (L < l) {
      sub(a[L]);
      L++;
    }
    while (L > l) {
      L--;
      add(a[L]);
    }
    while (R < r) {
      R++;
      add(a[R]);
    }
    while (R > r) {
      sub(a[R]);
      R--;
    }
    ans[Query[i].id] = s0;
  }
  for (int i = 1; i <= q; i++) {
    printf("%I64d\n", ans[i]);
  }
  return 0;
}
