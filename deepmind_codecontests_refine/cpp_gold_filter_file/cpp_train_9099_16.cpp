#include <bits/stdc++.h>
using namespace std;
struct S {
  int l, r;
  int* x;
  int getX() { return *x; }
  bool operator<(const S ot) const {
    if (l != ot.l) return l < ot.l;
    return r > ot.r;
  }
};
vector<S> tree[8000];
int mk[1000100], step, ans;
struct Q {
  int type, t;
  int l, r, x;
  int v;
};
int xx[8000], n;
vector<Q> que;
pair<int, int> expand(int v) {
  int inc = 0;
  if (v > 1) {
    while ((1 << inc) < v) ++inc;
  }
  int bef = (v - 1) + inc;
  pair<int, int> at = make_pair(bef + 1, bef + 1);
  if (!(v & (v - 1))) at.second = (bef + 2);
  return at;
}
void answer(int lvl, int v) {
  pair<int, int> at = make_pair(v, v);
  while (lvl <= n) {
    pair<int, int> next =
        make_pair(expand(at.first).first, expand(at.second).second);
    for (int i = 0; i < tree[lvl].size(); ++i) {
      int l = tree[lvl][i].l, r = tree[lvl][i].r, x = tree[lvl][i].getX();
      if (at.first > r || at.second < l) continue;
      if (x && mk[x] != step) ++ans, mk[x] = step;
    }
    at = next;
    ++lvl;
  }
}
void process() {
  int m;
  scanf("%d%d", &n, &m);
  step = 0;
  for (int i = 0; i < m; ++i) {
    Q tmp;
    scanf("%d", &tmp.type);
    if (tmp.type == 1)
      scanf("%d %d %d %d", &tmp.t, &tmp.l, &tmp.r, &tmp.x),
          tree[tmp.t].push_back((S){tmp.l, tmp.r, xx + i}), xx[i] = 0;
    else
      scanf("%d %d", &tmp.t, &tmp.v);
    que.push_back(tmp);
  }
  for (int i = 0; i < n + 1; ++i) sort(tree[i].begin(), tree[i].end());
  for (int i = 0; i < que.size(); ++i) {
    Q tmp = que[i];
    if (tmp.type == 1)
      xx[i] = tmp.x;
    else {
      ans = 0, ++step;
      answer(tmp.t, tmp.v);
      printf("%d\n", ans);
    }
  }
}
int main() { process(); }
