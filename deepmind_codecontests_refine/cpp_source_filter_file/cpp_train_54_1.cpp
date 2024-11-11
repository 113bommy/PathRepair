#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
struct Tree {
  int n;
  int t[4 * 100001 + 1];
  void build(int sz);
  void build(int i, int l, int r);
  void add(int pos, int val);
  void add(int pos, int val, int i, int l, int r);
  int get_kth(int k);
  int get_kth(int k, int i, int l, int r);
};
void Tree::build(int sz) {
  n = sz;
  build(1, 0, n - 1);
}
void Tree::build(int i, int l, int r) {
  if (l == r) {
    t[i] = 0;
    return;
  }
  int m = (l + r) / 2;
  build(i * 2, l, m);
  build(i * 2 + 1, m + 1, r);
  t[i] = t[i * 2] + t[i * 2 + 1];
}
void Tree::add(int pos, int val) { add(pos, val, 1, 0, n - 1); }
void Tree::add(int pos, int val, int i, int l, int r) {
  t[i] += val;
  if (l == r) return;
  int m = (l + r) / 2;
  if (pos <= m)
    add(pos, val, i * 2, l, m);
  else
    add(pos, val, i * 2 + 1, m + 1, r);
}
int Tree::get_kth(int k) { return get_kth(k, 1, 0, n - 1); }
int Tree::get_kth(int k, int i, int l, int r) {
  assert(k >= 0 && k < t[i]);
  if (l == r) return l;
  int m = (l + r) / 2;
  if (k < t[i * 2])
    return get_kth(k, i * 2, l, m);
  else
    return get_kth(k - t[i * 2], i * 2 + 1, m + 1, r);
}
int rev(int x) {
  char s[64];
  int r = 0;
  for (int i = (sprintf(s, "%d", x)) - 1; i >= 0; --i) r = r * 10 + s[i] - '0';
  return r;
}
Tree t;
int maxx, maxy, w;
map<double, vector<int> > g;
void solution() {
  cin >> maxx >> maxy >> w;
  for (int i = 1; i <= maxy; i++) {
    double ratio = rev(i) * 1. / i;
    g[ratio].push_back(i);
  }
  t.build(maxy + 1);
  int x = -1, y, into = 0;
  for (int i = 1; i <= maxx; i++) {
    double ratio = i * 1. / rev(i);
    vector<int>& v = g[ratio];
    for (int j = 0, _n = ((int)((v).size())); j < _n; ++j) t.add(v[j], +1);
    into += (int)((v).size());
    if (into < w) continue;
    int val = t.get_kth(w);
    if (x == -1 || i * val < x * y) x = i, y = val;
  }
  if (x == -1)
    puts("-1");
  else
    printf("%d %d\n", x, y);
}
int main() {
  solution();
  return 0;
}
