#include <bits/stdc++.h>
using ll = long long;
int main() {
  int n, m, h = 0;
  std::cin >> n;
  while ((1 << h) < n) h++;
  std::vector<ll> tree(2 * n), inc(n, 0);
  for (int i = 0; i < n; i++) std::cin >> tree[n + i];
  std::cin >> m;
  for (int i = n - 1; i > 0; i--)
    tree[i] = std::min(tree[2 * i], tree[2 * i + 1]);
  auto apply = [&](int p, int x) {
    tree[p] += x;
    if (p < n) inc[p] += x;
  };
  auto push = [&](int p) {
    while (p /= 2) tree[p] = std::min(tree[2 * p], tree[2 * p + 1]) + inc[p];
  };
  auto pull = [&](int p) {
    for (int s = h; s > 0; s--) {
      int i = p >> s;
      if (inc[i] != 0) {
        apply(2 * i, inc[i]);
        apply(2 * i + 1, inc[i]);
        inc[i] = 0;
      }
    }
  };
  auto p = [&]() {
    return;
    printf("# tree");
    for (ll x : tree) printf(" %lld", x);
    printf("\n");
    printf("# inc");
    for (ll x : inc) printf(" %lld", x);
    printf("\n\n");
  };
  auto do_inc = [&](int _l, int _r, int x) {
    p();
    for (int l = _l + n, r = _r + n; l < r; l /= 2, r /= 2) {
      if (l & 1) apply(l++, x);
      if (r & 1) apply(--r, x);
    }
    p();
    push(_l + n);
    push(_r - 1 + n);
    p();
  };
  auto query = [&](int _l, int _r) {
    pull(_l + n);
    pull(_r - 1 + n);
    ll mn = 1e9;
    for (int l = _l + n, r = _r + n; l < r; l /= 2, r /= 2) {
      if (l & 1) mn = std::min(mn, tree[l++]);
      if (r & 1) mn = std::min(mn, tree[--r]);
    }
    return mn;
  };
  {
    std::string tmp;
    getline(std::cin, tmp);
  }
  for (int i = 0; i < m; i++) {
    int l, r, v;
    std::string ln;
    getline(std::cin, ln);
    std::stringstream ss(ln);
    ss >> l >> r;
    if (!(ss >> v)) {
      ll res;
      if (l <= r) {
        res = query(l, r + 1);
      } else {
        res = std::min(query(l, n), query(0, r + 1));
      }
      std::cout << res << "\n";
    } else {
      if (l <= r) {
        do_inc(l, r + 1, v);
      } else {
        do_inc(l, n, v);
        do_inc(0, r + 1, v);
      }
    }
  }
}
