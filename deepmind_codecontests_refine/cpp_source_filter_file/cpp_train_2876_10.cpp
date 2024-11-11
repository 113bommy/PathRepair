#include <bits/stdc++.h>
const long long N = 500010;
const long long MOD = 1e9 + 7;
long long n, q;
long long a[N];
struct Block {
  long long l, r;
  Block() : l(0), r(0) {}
  Block(long long _l, long long _r) : l(_l), r(_r) {}
  bool operator<(const Block& rhs) const {
    return l != rhs.l ? l < rhs.l : r < rhs.r;
  }
};
std::vector<long long> que[N];
std::vector<Block> block;
long long l[N], r[N];
long long sum[N];
long long pos[N];
long long sze;
long long ans[N];
long long FastPow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % MOD;
    a = 1ll * a * a % MOD;
    b >>= 1;
  }
  return res;
}
void Check(long long& x) {
  while (x < 0) x += MOD;
  x %= MOD;
}
long long F(long long l, long long r) {
  long long res = 0;
  for (long long i = l; i <= r; ++i) res = res * 2 + a[i];
  return res;
}
long long G(long long l, long long r) {
  if (l > r) return 0;
  long long res = (sum[l] - sum[r + 1] * FastPow(2, r - l + 1)) % MOD;
  Check(res);
  return res;
}
signed main() {
  scanf("%lld%lld", &n, &q);
  for (long long i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  for (long long i = n; i >= 1; --i) sum[i] = (sum[i + 1] * 2 + a[i]) % MOD;
  for (long long i = 1; i <= q; ++i) {
    scanf("%lld%lld", &l[i], &r[i]);
    que[r[i]].push_back(i);
  }
  for (long long i = 1; i <= n; ++i) {
    if (a[i] <= 0) {
      block.push_back(Block(i, i));
      Check(pos[sze] = (pos ? pos[sze - 1] : 0) + a[i]);
      ++sze;
    } else {
      long long tot = a[i];
      bool flag = true;
      for (long long j = (long long)block.size() - 1; j >= 0; --j) {
        Block pre = block[j];
        block.pop_back();
        if (pre.r - pre.l + 1 >= 30) break;
        tot *= FastPow(2, pre.r - pre.l + 1);
        tot += F(pre.l, pre.r);
        if (tot <= 0) {
          Check(pos[j] = (j ? pos[j - 1] : 0) + G(pre.l, i));
          block.push_back(Block(pre.l, i));
          flag = false;
          break;
        }
        if (tot >= MOD) break;
      }
      if (flag) {
        block.clear();
        pos[0] = G(0, i);
        block.push_back(Block(0, i));
      }
    }
    sze = block.size();
    for (long long j : que[i]) {
      long long p =
          std::upper_bound(block.begin(), block.end(), Block(l[j], N)) -
          block.begin();
      if (p < (long long)block.size()) {
        ans[j] = G(l[j], block[p].l - 1);
        Check(ans[j] += 2ll * (pos[sze - 1] - (p ? pos[p - 1] : 0)));
      } else {
        ans[j] = G(l[j], i);
      }
    }
  }
  for (long long i = 1; i <= q; ++i) printf("%lld\n", ans[i]);
  return 0;
}
