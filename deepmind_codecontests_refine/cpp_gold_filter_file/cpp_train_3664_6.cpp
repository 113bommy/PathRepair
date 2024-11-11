#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
const int inf = 2e9;
struct RMQ {
  pair<int, int> a[N * 2];
  int n;
  RMQ(int n, int *pot) : n(n) {
    for (int i = 0; i < n; i++) a[n + i] = {pot[i], i};
    for (int i = n - 1; i > 0; i--) a[i] = min(a[i << 1], a[i << 1 | 1]);
  }
  void update(int pos, int x) {
    a[pos + n] = {x, pos};
    for (int i = (pos + n) >> 1; i; i >>= 1)
      a[i] = min(a[i << 1], a[i << 1 | 1]);
  }
  int query(int l, int r) {
    pair<int, int> res = {inf, -1};
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = min(res, a[l++]);
      if (r & 1) res = min(res, a[--r]);
    }
    return res.second;
  }
};
int n, p;
int t[N];
int minPref[N];
long long sol[N];
int main() {
  scanf("%d%d", &n, &p);
  for (int i = 0; i < n; i++) scanf("%d", t + i);
  RMQ tree(n, t);
  pair<int, int> sorted[n];
  for (int i = 0; i < n; i++) sorted[i] = {t[i], i};
  sort(sorted, sorted + n);
  set<int> S;
  int ind = 0;
  auto update = [&](long long x) {
    while (ind < n && sorted[ind].first <= x) {
      if (!sol[sorted[ind].second]) S.insert(sorted[ind].second);
      ind++;
    }
  };
  int pos = tree.query(0, n);
  long long cur = t[pos] + p;
  sol[pos] = cur;
  tree.update(pos, inf);
  for (int i = 0; i < (n - 1); i++) {
    int left = tree.query(0, pos);
    if (left != -1 && t[left] <= cur) {
      pos = left;
      cur += p;
    } else {
      update(cur);
      auto right_it = S.lower_bound(pos);
      if (right_it != S.end()) {
        int right = *right_it;
        pos = right;
        cur += p;
      } else {
        pos = tree.query(0, n);
        cur = max(cur, (long long)t[pos]) + p;
      }
    }
    sol[pos] = cur;
    S.erase(pos);
    tree.update(pos, inf);
  }
  for (int i = 0; i < n; i++) printf("%lld ", sol[i]);
  printf("\n");
  return 0;
}
