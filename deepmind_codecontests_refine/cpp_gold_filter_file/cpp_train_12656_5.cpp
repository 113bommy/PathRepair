#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 7;
const int M = 1007;
const int inf = 1e9 + 7;
const long long linf = 1e18 + 7;
const double pi = acos(-1);
const double eps = 1e-7;
const bool multipleTest = 0;
struct node {
  int val;
  int lz;
  int mx;
};
node tree[N * 4];
void update(int i, int l, int r, int u, int v, int val);
void updatelz(int i, int l, int r) {
  if (tree[i].lz) {
    int g = (l + r) >> 1, nxt = i << 1;
    update(nxt, l, g, l, g, tree[i].lz);
    update(nxt + 1, g + 1, r, g + 1, r, tree[i].lz);
    tree[i].lz = 0;
  }
}
void update(int i, int l, int r, int u, int v, int val) {
  if (l == u && r == v) {
    tree[i].mx += val;
    tree[i].lz += val;
    return;
  }
  int g = (l + r) >> 1, nxt = i << 1;
  updatelz(i, l, r);
  if (u <= g) update(nxt, l, g, u, min(g, v), val);
  if (g < v) update(nxt + 1, g + 1, r, max(u, g + 1), v, val);
  tree[i].mx = max(tree[nxt].mx, tree[nxt + 1].mx);
}
int get(int i, int l, int r, int u, int v) {
  if (u <= l && r <= v) return tree[i].mx;
  if (u > r || v < l) return -inf;
  updatelz(i, l, r);
  int g = (l + r) >> 1, nxt = i << 1;
  int ans = ::get(nxt, l, g, u, v);
  ans = max(ans, ::get(nxt + 1, g + 1, r, u, v));
  tree[i].mx = max(tree[nxt].mx, tree[nxt + 1].mx);
  return ans;
}
int n;
int val[N];
void solve() {
  int sum = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int p, t;
    scanf("%d%d", &p, &t);
    if (t == 0) {
      update(1, 1, n, 1, p, -1);
      sum--;
    } else {
      update(1, 1, n, 1, p, 1);
      scanf("%d", val + p);
      ++sum;
    }
    int lo = 1, hi = n, res = -1;
    while (lo <= hi) {
      int g = (lo + hi) >> 1;
      if (::get(1, 1, n, g, n) > 0) {
        res = g;
        lo = g + 1;
      } else
        hi = g - 1;
    }
    if (res != -1)
      printf("%d\n", val[res]);
    else
      printf("%d\n", res);
  }
}
int main() {
  int Test = 1;
  if (multipleTest) {
    cin >> Test;
  }
  for (int i = 0; i < Test; ++i) {
    solve();
  }
}
