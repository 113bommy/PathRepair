#include <bits/stdc++.h>
using namespace std;
long long modexpo(long long x, long long p) {
  long long res = 1;
  x = x % 1000000007;
  while (p) {
    if (p % 2) res = res * x;
    p >>= 1;
    x = x * x % 1000000007;
    res %= 1000000007;
  }
  return res;
}
long long max(long long a, long long b) { return (a > b ? a : b); }
long long min(long long a, long long b) { return (a < b ? a : b); }
struct edge {
  long long u, v, w;
  edge(long long a, long long b, long long c) {
    u = a;
    v = b;
    w = c;
  }
};
struct compare {
  bool operator()(const edge a, const edge b) const {
    if (a.u == b.u) {
      if (a.v == b.v) {
        return a.w < b.w;
      }
      return a.v < b.v;
    }
    return a.u < b.u;
  }
};
const long long N = 100005;
long long tree[4 * N], n;
long long ans[N];
void build(long long i, long long l, long long r) {
  if (l > r) {
    return;
  }
  if (l == r) {
    tree[i] = 0;
    return;
  }
  long long mid = (l + r + 1) >> 1;
  build(2 * i, l, mid - 1);
  build(2 * i + 1, mid, r);
  tree[i] = tree[2 * i] + tree[2 * i + 1] + 2;
}
void query(long long i, long long l, long long r, long long rest) {
  if (l > r) {
    return;
  }
  if (l == r) {
    ans[l] = l;
    return;
  }
  if (rest == 0) {
    return;
  }
  if (rest == 2) {
    long long mid = (l + r + 1) >> 1;
    for (long long i = l; i <= r; i++) {
      ans[i] = i;
    }
    (ans[mid - 1] ^= ans[mid] ^= ans[mid - 1] ^= ans[mid]);
    return;
  }
  long long mid = (l + r + 1) >> 1;
  long long need = rest - 2;
  if (tree[2 * i] >= need) {
    query(2 * i, l, mid - 1, need);
  } else {
    query(2 * i, l, mid - 1, tree[2 * i]);
    query(2 * i + 1, mid, r, need - tree[2 * i]);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long k;
  cin >> n >> k;
  if (k % 2 == 0) {
    cout << -1 << "\n";
    return 0;
  }
  if (k == 1) {
    for (long long i = 1; i <= n; i++) {
      cout << i << " ";
    }
    cout << "\n";
    return 0;
  }
  build(1, 1, n);
  if (k - 1 > tree[1]) {
    cout << -1 << "\n";
    return 0;
  }
  query(1, 1, n, k - 1);
  set<long long> st;
  for (long long i = 0; i <= n; i++) {
    st.insert(i);
  }
  for (long long i = 1; i <= n; i++) {
    st.erase(ans[i]);
  }
  for (long long i = 1; i <= n; i++) {
    if (!ans[i]) {
      ans[i] = *st.begin();
      st.erase(st.begin());
    }
  }
  for (long long i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
