#include <bits/stdc++.h>
using namespace std;
int n, m, k, q;
pair<int, int> rock[200010];
priority_queue<int, vector<int>, greater<int> > v[100010];
int res[200010];
struct record {
  int lx, rx, ly, ry, id;
  record(int _lx, int _rx, int _ly, int _ry, int _id)
      : lx(_lx), rx(_rx), ly(_ly), ry(_ry), id(_id) {}
  record() {}
  bool operator<(const record& a) const { return lx < a.lx; }
} query[200010];
struct tree {
  int l, r;
  tree *lt, *rt;
  int mmin, mmax;
  tree(int _l, int _r) : l(_l), r(_r) {
    if (r - l == 1) {
      if (v[l].empty()) {
        mmin = mmax = 10000000;
      } else
        mmin = mmax = v[l].top();
    } else {
      int mid = (l + r) >> 1;
      lt = new tree(l, mid);
      rt = new tree(mid, r);
      mmin = min(lt->mmin, rt->mmax);
      mmax = max(lt->mmax, rt->mmax);
    }
  }
  bool check(int a, int b, int h) {
    if (a <= l && r <= b) {
      return h >= mmax;
    } else {
      bool res = true;
      int mid = (l + r) >> 1;
      if (a < mid) res = res && lt->check(a, b, h);
      if (b > mid) res = res && rt->check(a, b, h);
      return res;
    }
  }
  void update(int x) {
    if (mmin >= x) return;
    if (r - l == 1) {
      while (!v[l].empty() && v[l].top() < x) v[l].pop();
      if (!v[l].empty())
        mmin = mmax = v[l].top();
      else
        mmin = mmax = 10000000;
    } else {
      if (lt->mmin < x) lt->update(x);
      if (rt->mmin < x) rt->update(x);
      mmin = min(lt->mmin, rt->mmin);
      mmax = max(lt->mmax, rt->mmax);
    }
  }
};
void f() {
  for (int i = 0; i < m; i++)
    while (!v[i].empty()) v[i].pop();
  for (int i = 0; i < k; i++) v[rock[i].first].push(rock[i].second);
  tree* t = new tree(0, m);
  sort(query, query + q);
  int cur = 0;
  for (int i = 0; i < n; i++) {
    t->update(i);
    while (cur < q && query[cur].lx == i) {
      if (t->check(query[cur].ly, query[cur].ry + 1, query[i].rx))
        res[query[i].id] = 1;
      cur++;
    }
  }
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &q);
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &rock[i].second, &rock[i].first);
    rock[i].first--;
    rock[i].second--;
  }
  for (int i = 0; i < q; i++) {
    scanf("%d%d%d%d", &query[i].lx, &query[i].ly, &query[i].rx, &query[i].ry);
    query[i].lx--;
    query[i].ly--;
    query[i].rx--;
    query[i].ry--;
    query[i].id = i;
  }
  f();
  for (int i = 0; i < k; i++) swap(rock[i].first, rock[i].second);
  for (int i = 0; i < q; i++)
    swap(query[i].lx, query[i].ly), swap(query[i].rx, query[i].ry);
  swap(n, m);
  f();
  for (int i = 0; i < q; i++)
    if (res[i])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  return 0;
}
