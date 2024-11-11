#include <bits/stdc++.h>
using namespace std;
struct node {
  int v, lz;
  node *l, *r;
  node(int s, int e) : v(0), lz(0) {
    int m = (s + e) / 2;
    if (s != e) {
      l = new node(s, m);
      r = new node(m + 1, e);
    }
  }
  int val(int s, int e) {
    if (s != e) {
      l->lz += lz;
      r->lz += lz;
    }
    v += lz;
    lz = 0;
    return v;
  }
  void add(int s, int e, int x, int y, int z) {
    assert(s <= e and s >= 0 and e <= (int)4e6 and x >= 0 and y <= (int)4e6);
    int m = (s + e) / 2;
    if (s == x && e == y) {
      lz += z;
      return;
    } else if (y <= m)
      l->add(s, m, x, y, z);
    else if (x > m)
      r->add(m + 1, e, x, y, z);
    else
      l->add(s, m, x, m, z), r->add(m + 1, e, m + 1, y, z);
    v = max(l->val(s, m), r->val(m + 1, e));
  }
} * root;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, r;
  cin >> n >> r;
  pair<int, int> p[n];
  for (int i = 0; i <= n - 1; ++i) {
    cin >> p[i].first >> p[i].second;
    p[i].first += 1e6;
    p[i].second += 1e6;
  }
  const int G = (int)2e6;
  sort(p, p + n, [](pair<int, int> a, pair<int, int> b) {
    return (a.first - a.second) < (b.first - b.second);
  });
  root = new node(0, 2 * G);
  int s = 0, e = 0, ans = 0;
  for (; e < n; ++e) {
    root->add(0, 2 * G, max(0, p[e].first + p[e].second - 2 * r),
              p[e].first + p[e].second, 1);
    while ((p[e].first - p[e].second) - (p[s].first - p[e].second) > 2 * r) {
      root->add(0, 2 * G, max(0, p[s].first + p[s].second - 2 * r),
                p[s].first + p[s].second, -1);
      ++s;
    }
    ans = max(ans, root->val(0, 2 * G));
  }
  cout << ans << '\n';
}
