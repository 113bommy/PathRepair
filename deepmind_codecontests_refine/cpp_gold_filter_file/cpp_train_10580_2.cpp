#include <bits/stdc++.h>
using namespace std;
int n, m;
long long seed, vmax, a[100005], t[100005];
struct info {
  int l, r;
  long long val;
  bool operator<(const info &p) const { return r < p.r; }
} A[100005], B[100005];
struct node {
  long long val;
  int size;
  bool operator<(const node &p) const { return val < p.val; }
} q[100005];
multiset<info> s;
multiset<info>::iterator it;
long long Pow(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long rnd() {
  long long ret = seed;
  seed = (seed * 7 + 13) % 1000000007;
  return ret;
}
int main() {
  int op, l, r, x, y;
  scanf("%d%d%I64d%I64d", &n, &m, &seed, &vmax);
  for (int i = 1; i <= n; i++)
    a[i] = (rnd() % vmax) + 1, s.insert((info){i, i, a[i]});
  s.insert((info){n + 1, n + 1, 0});
  while (m--) {
    op = (rnd() % 4) + 1;
    l = (rnd() % n) + 1;
    r = (rnd() % n) + 1;
    if (l > r) swap(l, r);
    if (op == 3)
      x = (rnd() % (r - l + 1)) + 1;
    else
      x = (rnd() % vmax) + 1;
    if (op == 4) y = (rnd() % vmax) + 1;
    it = s.lower_bound((info){l, l, 0});
    if (op == 1) {
      int l1 = 0, l2 = 0;
      for (; (*it).l <= r; ++it) {
        info tmp = *it;
        B[++l2] = tmp;
        if (tmp.l < l && r < tmp.r) {
          A[++l1] = (info){tmp.l, l - 1, tmp.val};
          A[++l1] = (info){l, r, tmp.val + x};
          A[++l1] = (info){r + 1, tmp.r, tmp.val};
          continue;
        }
        if (tmp.l < l && tmp.r >= l) {
          A[++l1] = (info){tmp.l, l - 1, tmp.val};
          A[++l1] = (info){l, tmp.r, tmp.val + x};
          continue;
        }
        if (tmp.l <= r && tmp.r > r) {
          A[++l1] = (info){tmp.l, r, tmp.val + x};
          A[++l1] = (info){r + 1, tmp.r, tmp.val};
          continue;
        }
        A[++l1] = (info){tmp.l, tmp.r, tmp.val + x};
      }
      for (int i = 1; i <= l2; i++) s.erase(B[i]);
      for (int i = 1; i <= l1; i++) s.insert(A[i]);
    }
    if (op == 2) {
      int l1 = 0, l2 = 0;
      for (; (*it).l <= r; ++it) {
        info tmp = *it;
        B[++l2] = tmp;
        if (tmp.l < l && tmp.r >= l) A[++l1] = (info){tmp.l, l - 1, tmp.val};
        if (tmp.l <= r && tmp.r > r) A[++l1] = (info){r + 1, tmp.r, tmp.val};
      }
      A[++l1] = (info){l, r, x};
      for (int i = 1; i <= l2; i++) s.erase(B[i]);
      for (int i = 1; i <= l1; i++) s.insert(A[i]);
    }
    if (op == 3) {
      int tot = 0, sum = 0;
      for (; (*it).l <= r; ++it)
        q[++tot] = (node){(*it).val, min((*it).r, r) - max((*it).l, l) + 1};
      sort(q + 1, q + tot + 1);
      for (int i = 1; i <= tot; sum += q[i].size, i++)
        if (sum + q[i].size >= x) {
          printf("%I64d\n", q[i].val);
          break;
        }
    }
    if (op == 4) {
      int ans = 0;
      for (; (*it).l <= r; ++it) {
        int num = min((*it).r, r) - max((*it).l, l) + 1;
        ans += (long long)Pow((*it).val, x, y) * num % y;
        if (ans >= y) ans -= y;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
