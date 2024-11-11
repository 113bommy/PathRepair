#include <bits/stdc++.h>
using namespace std;
long long a[500001], l[801], r[801], block[500001], tag[500001], sz, kcnt;
struct k {
  long long val, pos;
} K[500001];
bool cmp(k a, k b) {
  return (a.val < b.val || (a.val == b.val && a.pos < b.pos));
}
long long n, q, type, lq, rq, xq, yq;
signed main() {
  scanf("%lld%lld", &n, &q);
  sz = sqrt(n);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    block[i] = (i - 1) / sz + 1;
    K[i] = (k){a[i], i};
    kcnt = max(kcnt, (i - 1) / sz + 1);
  }
  for (long long i = 1; i <= kcnt; i++) {
    l[i] = 1 + (i - 1) * sz;
  }
  for (long long i = 1; i <= kcnt; i++) {
    r[i] = sz * i;
  }
  r[kcnt] = n;
  for (long long i = 1; i <= kcnt; i++) {
    sort(K + l[i] + 1, K + r[i] + 1, cmp);
  }
  for (long long i = 1; i <= q; i++) {
    scanf("%lld", &type);
    if (type == 1) {
      scanf("%lld%lld%lld", &lq, &rq, &xq);
      if (block[lq] == block[rq]) {
        for (long long i = l[block[lq]]; i <= r[block[lq]]; i++) {
          if (lq <= K[i].pos && K[i].pos <= rq) {
            K[i].val += xq;
          }
        }
        sort(K + l[block[lq]], K + 1 + r[block[rq]], cmp);
      } else {
        for (long long i = block[lq] + 1; i <= block[rq] - 1; i++) {
          tag[i] += xq;
        }
        for (long long i = l[block[lq]]; i <= r[block[lq]]; i++) {
          if (lq <= K[i].pos && K[i].pos <= rq) {
            K[i].val += xq;
          }
        }
        sort(K + l[block[lq]], K + 1 + r[block[lq]], cmp);
        for (long long i = l[block[rq]]; i <= r[block[rq]]; i++) {
          if (lq <= K[i].pos && K[i].pos <= rq) {
            K[i].val += xq;
          }
        }
        sort(K + l[block[rq]], K + 1 + r[block[rq]], cmp);
      }
    } else {
      scanf("%lld", &yq);
      long long mml = 1000000, mmr = 0;
      for (long long i = 1; i <= kcnt; i++) {
        long long lp = l[i], rp = r[i];
        while (lp < rp) {
          long long mid = (lp + rp) >> 1;
          if (K[mid].val >= yq - tag[i])
            rp = mid;
          else
            lp = mid + 1;
        }
        if (K[lp].val == yq - tag[i]) mml = min(mml, K[lp].pos);
        lp = l[i], rp = r[i];
        while (lp < rp) {
          long long mid = (lp + rp + 1) >> 1;
          if (K[mid].val <= yq - tag[i])
            lp = mid;
          else
            rp = mid - 1;
        }
        if (K[lp].val == yq - tag[i]) mmr = max(mmr, K[lp].pos);
      }
      printf("%lld\n", (mmr - mml) >= 0 ? mmr - mml : -1);
    }
  }
}
