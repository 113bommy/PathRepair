#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const int N = 2e6 + 1;
const long long mod = 1e9 + 7;
const int bits = 20;
const long double pi = 3.14159265358979323846;
const int p = 31;
long long tree[4 * N];
long long arr[N];
int flipped[20];
void build(int ss, int se, int si) {
  if (ss == se) {
    tree[si] = arr[ss];
    return;
  }
  int mid = (ss + se) / 2;
  build(ss, mid, 2 * si + 1);
  build(mid + 1, se, 2 * si + 2);
  tree[si] = tree[2 * si + 1] + tree[2 * si + 2];
}
long long query(int qs, int qe, int ss, int se, int si, int level) {
  if (qs > qe || qs > se || qe < ss) {
    return 0;
  }
  if (qs <= ss && qe >= se) {
    return tree[si];
  }
  int mid = (ss + se) / 2;
  if (flipped[level]) {
    return query(qs, qe, ss, mid, 2 * si + 2, level - 1) +
           query(qs, qe, mid + 1, se, 2 * si + 1, level - 1);
  } else {
    return query(qs, qe, ss, mid, 2 * si + 1, level - 1) +
           query(qs, qe, mid + 1, se, 2 * si + 2, level - 1);
  }
}
void update(int qi, int ss, int se, int si, long long v, int level) {
  if (qi > se || qi < ss) {
    return;
  }
  if (se == ss) {
    arr[ss] = v;
    tree[si] = v;
    return;
  }
  int mid = (ss + se) / 2;
  if (flipped[level]) {
    update(qi, ss, mid, 2 * si + 2, v, level - 1);
    update(qi, mid + 1, se, 2 * si + 1, v, level - 1);
  } else {
    update(qi, ss, mid, 2 * si + 1, v, level - 1);
    update(qi, mid + 1, se, 2 * si + 2, v, level - 1);
  }
  tree[si] = tree[2 * si + 1] + tree[2 * si + 2];
}
void solve() {
  int logn, q;
  cin >> logn >> q;
  int n = 1 << logn;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  build(0, n - 1, 0);
  int t, x, k, l, r;
  while (q--) {
    cin >> t;
    if (t == 1) {
      cin >> x >> k;
      update(x - 1, 0, n - 1, 0, k, logn);
    } else if (t == 2) {
      cin >> k;
      for (int i = 0; i <= k; i++) flipped[i] ^= 1;
    } else if (t == 3) {
      cin >> k;
      flipped[k + 1] ^= 1;
    } else if (t == 4) {
      cin >> l >> r;
      cout << query(l - 1, r - 1, 0, n - 1, 0, logn) << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  std::cout << std::fixed << std::setprecision(20);
  ;
  int t = 1;
  while (t--) {
    solve();
  }
}
