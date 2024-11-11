#include <bits/stdc++.h>
const long double pi = 3.1415926535898;
const long long mod = 1e9 + 7;
using namespace std;
long long tree[4000001][4], lazy[4000001];
string s;
void build(long long l, long long r, long long k) {
  if (l == r) {
    if (s[l] == '4') {
      tree[k][0]++;
    } else {
      tree[k][1]++;
    }
    return;
  }
  long long mid = (l + r) / 2;
  build(l, mid, 2 * k + 1);
  build(mid + 1, r, 2 * k + 2);
  tree[k][0] = tree[2 * k + 1][0] + tree[2 * k + 2][0];
  tree[k][1] = tree[2 * k + 1][1] + tree[2 * k + 2][1];
  tree[k][2] = max({tree[2 * k + 1][0] + tree[2 * k + 2][1],
                    tree[2 * k + 1][0] + tree[2 * k + 2][2],
                    tree[2 * k + 1][2] + tree[2 * k + 2][1]});
  tree[k][3] = max({tree[2 * k + 1][1] + tree[2 * k + 2][0],
                    tree[2 * k + 1][1] + tree[2 * k + 2][3],
                    tree[2 * k + 1][3] + tree[2 * k + 2][0]});
  return;
}
void update(long long l, long long r, long long k, long long x, long long y) {
  if (lazy[k]) {
    lazy[k] = 0;
    swap(tree[k][2], tree[k][3]);
    swap(tree[k][0], tree[k][1]);
    if (l != r) {
      lazy[2 * k + 1] = 1 - lazy[2 * k + 1];
      lazy[2 * k + 2] = 1 - lazy[2 * k + 2];
    }
  }
  if (x > r || y < l) {
    return;
  }
  if (x <= l && r <= y) {
    swap(tree[k][2], tree[k][3]);
    swap(tree[k][0], tree[k][1]);
    lazy[2 * k + 1] = 1 - lazy[2 * k + 1];
    lazy[2 * k + 2] = 1 - lazy[2 * k + 2];
    return;
  }
  long long mid = (l + r) / 2;
  update(l, mid, 2 * k + 1, x, y);
  update(mid + 1, r, 2 * k + 2, x, y);
  tree[k][0] = tree[2 * k + 1][0] + tree[2 * k + 2][0];
  tree[k][1] = tree[2 * k + 1][1] + tree[2 * k + 2][1];
  tree[k][2] = max({tree[2 * k + 1][0] + tree[2 * k + 2][1],
                    tree[2 * k + 1][0] + tree[2 * k + 2][2],
                    tree[2 * k + 1][2] + tree[2 * k + 2][1]});
  tree[k][3] = max({tree[2 * k + 1][1] + tree[2 * k + 2][0],
                    tree[2 * k + 1][1] + tree[2 * k + 2][3],
                    tree[2 * k + 1][3] + tree[2 * k + 2][0]});
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, q, x, y;
  cin >> n >> q;
  cin >> s;
  string t;
  build(0, n - 1, 0);
  while (q--) {
    cin >> t;
    if (t == "count") {
      cout << max({tree[0][2], tree[0][1], tree[0][0]}) << "\n";
      continue;
    } else {
      cin >> x >> y;
      x--;
      y--;
      update(0, n - 1, 0, x, y);
    }
  }
  return 0;
}
