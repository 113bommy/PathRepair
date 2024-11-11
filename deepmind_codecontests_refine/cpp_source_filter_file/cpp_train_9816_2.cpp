#include <bits/stdc++.h>
using namespace std;
inline int add(int _a, int _b) {
  if (_a < 0) {
    _a += 1000000007;
  }
  if (_b < 0) {
    _b += 1000000007;
  }
  if (_a + _b >= 1000000007) {
    return _a + _b - 1000000007;
  }
  return _a + _b;
}
inline int mul(int _a, int _b) {
  if (_a < 0) {
    _a += 1000000007;
  }
  if (_b < 0) {
    _b += 1000000007;
  }
  return ((long long int)((long long int)_a * (long long int)_b)) % 1000000007;
}
const int N = 2e5;
vector<long long int> vec, perm, new_vec;
long long int n, q, fac[20], tot, tree[N + 5];
void gen(long long int pos, long long int val, long long int mask) {
  if (pos == perm.size()) return;
  long long int len = (long long int)perm.size() - pos - 1, sum = 0, i, j;
  for (i = 0; i < perm.size(); ++i) {
    if (mask & 1ll << i) continue;
    if (tot >= sum + val + 1 && tot <= sum + val + fac[len]) {
      new_vec.push_back(perm[i]);
      gen(pos + 1, val + sum, mask | 1ll << i);
      return;
    }
    sum += fac[len];
  }
}
void update(long long int p, long long int v) {
  while (p <= n) {
    tree[p] += v;
    p += (p & (-p));
  }
}
long long int query(long long int p) {
  long long int ret = 0;
  while (p) {
    ret += tree[p];
    p ^= (p & (-p));
  }
  return ret;
}
long long int query(long long int l, long long int r) {
  if (l > r) return 0;
  return (query(r) - query(--l));
}
int main() {
  long long int i, j, k;
  scanf("%lld %lld", &n, &q);
  for (i = n, j = 0; i >= 1 && j < 13; ++j, --i) vec.push_back(i);
  for (i = 1, fac[0] = 1; i <= 13; ++i) fac[i] = fac[i - 1] * i;
  reverse(vec.begin(), vec.end());
  perm = vec;
  tot = 0;
  for (i = 1; i <= n; ++i) update(i, i);
  for (k = 0; k < q; ++k) {
    long long int t, l, r, x;
    scanf("%lld", &t);
    if (t == 1) {
      scanf("%lld %lld", &l, &r);
      long long int ret = query(l, r);
      printf("%lld", ret), puts("");
    } else if (t == 2) {
      scanf("%lld", &x);
      tot += x;
      new_vec.clear();
      gen(0, 0, 0);
      for (i = n, j = (long long int)vec.size() - 1; j >= 0; --j, --i) {
        update(i, -vec[j] + new_vec[j]);
      }
      vec = new_vec;
    }
  }
}
