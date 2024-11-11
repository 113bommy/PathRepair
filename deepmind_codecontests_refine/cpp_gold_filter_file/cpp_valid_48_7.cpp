#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct node {
  long long sum;
  long long maxPref;
  long long minPref;
  long long maxSuff;
  long long minSuff;
  long long maxSum;
  long long minSum;
  node() { sum = maxPref = maxSuff = minPref = minSuff = minSum = maxSum = 0; }
  node(int x) {
    sum = x;
    maxPref = max(0, x);
    maxSuff = max(0, x);
    maxSum = max(0, x);
    minPref = min(0, x);
    minSuff = min(0, x);
    minSum = min(0, x);
  }
};
node lacz(node a, node b) {
  node c;
  c.sum = a.sum + b.sum;
  c.maxPref = max(a.maxPref, a.sum + b.maxPref);
  c.maxSuff = max(b.maxSuff, b.sum + a.maxSuff);
  c.maxSum =
      max({a.maxSum, b.maxSum, a.maxSuff + b.maxPref, c.maxPref, c.maxSuff});
  c.minPref = min(a.minPref, a.sum + b.minPref);
  c.minSuff = min(b.minSuff, b.sum + a.minSuff);
  c.minSum =
      min({a.minSum, b.minSum, a.minSuff + b.minPref, c.minSuff, c.minPref});
  return c;
}
vector<node> tree;
node query(int p, int q, int pocz, int kon, int ind) {
  if (p == pocz && q == kon) return tree[ind];
  int sr = (pocz + kon) / 2;
  if (q <= sr)
    return query(p, q, pocz, sr, 2 * ind);
  else if (p > sr)
    return query(p, q, sr + 1, kon, 2 * ind + 1);
  else {
    return lacz(query(p, sr, pocz, sr, 2 * ind),
                query(sr + 1, q, sr + 1, kon, 2 * ind + 1));
  }
}
int P;
void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n), b(n);
  for (int i = (0); i < (n); ++i) {
    cin >> a[i];
  }
  for (int i = (0); i < (n); ++i) {
    cin >> b[i];
  }
  P = 1;
  while (P < n) {
    P <<= 1;
  }
  tree.resize(2 * P);
  for (int i = (0); i < (n); ++i) {
    tree[P + i] = node(a[i] - b[i]);
  }
  for (int i = ((int)(P)) - 1; i >= (1); --i) {
    tree[i] = lacz(tree[2 * i], tree[2 * i + 1]);
  }
  for (int i = (0); i < (q); ++i) {
    int l, r;
    cin >> l >> r;
    node res = query(l, r, 1, P, 1);
    if (res.sum != 0 || res.maxPref > 0 || res.minSuff < 0) {
      cout << -1 << endl;
    } else {
      cout << max(res.maxSum, -res.minSum) << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
