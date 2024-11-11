#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int tree[N * 4];
void update(int rt, int l, int r, int p, int v) {
  if (l == r) {
    tree[rt] = v;
    return;
  }
  int lc = 2 * rt, rc = lc + 1, m = l + r >> 1;
  if (p <= m)
    update(lc, l, m, p, v);
  else
    update(rc, m + 1, r, p, v);
  tree[rt] = tree[lc] + tree[rc];
}
int query(int rt, int l, int r, int b, int e) {
  if (l > e || r < b) return 0;
  if (l >= b && r <= e) return tree[rt];
  int lc = 2 * rt, rc = lc + 1, m = l + r >> 1;
  return query(lc, l, m, b, e) + query(rc, m + 1, r, b, e);
}
std::vector<int> getOrder(std::vector<int> v) {
  int n = v.size();
  for (int i = 0; i < n; i++) update(1, 0, v.size() - 1, i, 1);
  std::vector<int> ret(n, 0);
  for (int i = 0; i < n; i++) {
    if (v[i] == 0) {
      update(1, 0, n - 1, v[i], 0);
      continue;
    }
    ret[i] = query(1, 0, n - 1, 0, v[i] - 1);
    update(1, 0, n - 1, v[i], 0);
  }
  return ret;
}
void printPermutation(std::vector<int> v) {
  int n = v.size();
  for (int i = 0; i < n; i++) update(1, 0, v.size() - 1, i, 1);
  std::vector<int> ret(n, 0);
  for (int i = 0; i < n; i++) {
    int lo = 0, hi = n - 1;
    while (hi - lo > 2) {
      int m = lo + hi >> 1;
      if (query(1, 0, n - 1, 0, m) >= v[i] + 1)
        hi = m;
      else
        lo = m + 1;
    }
    for (int now = lo; now <= hi; now++) {
      if (query(1, 0, n - 1, now, now) &&
          query(1, 0, n - 1, 0, now) == v[i] + 1) {
        update(1, 0, n - 1, now, 0);
        ret[i] = now;
        break;
      }
    }
  }
  for (int i = 0; i < n; i++) cout << ret[i] << ' ';
  cout << endl;
}
int main() {
  int n, x;
  cin >> n;
  std::vector<int> a(n), b(n), s(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  a = getOrder(a);
  b = getOrder(b);
  for (int i = n - 1, maxD = 1; i >= 0; i--, maxD++) {
    s[i] += a[i] + b[i];
    if (s[i] < maxD)
      continue;
    else {
      s[i] -= maxD;
      if (i - 1 >= 0) s[i - 1]++;
    }
  }
  printPermutation(s);
  return 0;
}
