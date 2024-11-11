#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int MAXT = 2e5 + 10;
long long a[MAXN];
long long cnt[MAXN];
long long ans[MAXT];
int L, R;
long long res;
struct node {
  int l, r, bid, id;
  bool operator<(const node &other) const {
    if (other.bid == bid) return r < other.r;
    return bid < other.bid;
  }
} q[MAXT];
void query(int l, int r, int is) {
  if (is) {
    for (int i = l; i < L; i++) {
      res += ((cnt[a[i]] << 1) + 1) * a[i];
      cnt[a[i]]++;
    }
    for (int i = R + 1; i <= r; i++) {
      res += ((cnt[a[i]] << 1) + 1) * a[i];
      cnt[a[i]]++;
    }
    for (int i = L; i < l; i++) {
      cnt[a[i]]--;
      res -= ((cnt[a[i]] << 1) + 1) * a[i];
    }
    for (int i = r + 1; i <= R; i++) {
      cnt[a[i]]--;
      res -= ((cnt[a[i]] << 1) + 1) * a[i];
    }
  } else {
    for (int i = l; i <= r; i++) {
      res += ((cnt[a[i]] << 1) + 1) * a[i];
      cnt[a[i]]++;
    }
  }
  L = l;
  R = r;
  ans[q[is].id] = res;
}
int main() {
  int n, t;
  cin >> n >> t;
  int bsize = sqrt(n + 0.5);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  for (int i = 0; i < t; i++) {
    scanf("%I64d%I64d", &q[i].l, &q[i].r);
    q[i].bid = q[i].l / bsize;
    q[i].id = i;
  }
  sort(q, q + t);
  for (int i = 0; i < t; i++) query(q[i].l, q[i].r, i);
  for (int i = 0; i < t; i++) printf("%I64d\n", ans[i]);
  return 0;
}
