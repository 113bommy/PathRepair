#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
struct node {
  long long val, id;
  bool operator<(const node& o) const {
    if (val == o.val) return id < o.id;
    return val < o.val;
  }
};
node make_node(long long v, long long i) {
  node res;
  res.val = v;
  res.id = i;
  return res;
}
node max(node c, node b) {
  if (c < b)
    return b;
  else
    return c;
}
node tree[N * 20];
long long n, a[N];
void build(long long i, long long l, long long r) {
  if (l == r) {
    tree[i] = make_node(a[l], l);
    return;
  }
  build(2 * i, l, (l + r) / 2);
  build(2 * i + 1, (l + r) / 2 + 1, r);
  tree[i] = max(tree[2 * i], tree[2 * i + 1]);
}
void input() {
  cin >> n;
  for (long long i = 0; i < n - 1; i++) {
    cin >> a[i];
    a[i]--;
  }
  build(1, 0, n - 1);
}
node get(long long i, long long l, long long r, long long L, long long R) {
  if (r < L || l > R) return make_node(-1, -1);
  if (L <= l && r <= R)
    return tree[i];
  else {
    node left = get(2 * i, l, (l + r) / 2, L, R);
    node right = get(2 * i + 1, (l + r) / 2 + 1, r, L, R);
    return max(left, right);
  }
}
void compute_end_to_begin() {
  long long dp[N];
  dp[n - 1] = 0;
  for (long long i = n - 2; i >= 0; i--) {
    node M = get(1, 0, n - 1, i + 1, a[i]);
    long long am = M.val;
    long long m = M.id;
    dp[i] = dp[m] + (n - 1 - a[i]) + m - i;
  }
  long long sum = 0;
  for (long long i = 0; i <= n - 2; i++) sum += dp[i];
  cout << sum << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  input();
  compute_end_to_begin();
}
