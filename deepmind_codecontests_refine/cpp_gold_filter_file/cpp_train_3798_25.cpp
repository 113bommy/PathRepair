#include <bits/stdc++.h>
using namespace std;
struct Tree {
  int n;
  vector<int> data;
  Tree(int n_) {
    n = n_;
    data.assign(n * 4, -1);
  }
  void setValue(int pos, int value) { setValue(1, 0, n - 1, pos, value); }
  void setValue(int v, int l, int r, int pos, int value) {
    if (pos > r || pos < l) return;
    if (l == r) {
      data[v] = value;
      return;
    } else {
      int med((l + r) >> 1);
      setValue(v + v, l, med, pos, value);
      setValue(v + v + 1, med + 1, r, pos, value);
      data[v] = min(data[v + v], data[v + v + 1]);
    }
  }
  int getMin(int from, int to) {
    int res = getMin(1, 0, n - 1, from, to);
    return res;
  }
  int getMin(int v, int l, int r, int from, int to) {
    if (from > r || to < l) return 1050000000;
    if (from <= l && to >= r)
      return data[v];
    else {
      int med((l + r) >> 1);
      return min(getMin(v + v, l, med, from, to),
                 getMin(v + v + 1, med + 1, r, from, to));
    }
  }
};
struct Query {
  int X1, Y1;
  int x2, y2;
  int n;
  bool operator<(const Query& other) const { return x2 < other.x2; }
};
int n, m, k, q;
vector<bool> ans;
vector<Query> Q;
vector<pair<int, int> > d;
void go() {
  Tree T(max(n, m) + 1);
  sort((Q).begin(), (Q).end());
  sort((d).begin(), (d).end());
  int i(0), j(0);
  while (i < ((int)Q.size()) || j < ((int)d.size())) {
    if (j == ((int)d.size()) ||
        (i != ((int)Q.size()) && Q[i].x2 < d[j].first)) {
      int sm(T.getMin(Q[i].Y1, Q[i].y2));
      if (sm >= Q[i].X1) {
        ans[Q[i].n] = true;
      }
      ++i;
    } else {
      T.setValue(d[j].second, d[j].first);
      ++j;
    }
  }
}
void solve() {
  scanf("%d%d%d%d", &n, &m, &k, &q);
  d.resize(k);
  ans.assign(q, false);
  Q.resize(q);
  for (int i(0), _l((int)(k)-1); i <= _l; ++i)
    scanf("%d%d", &d[i].first, &d[i].second);
  for (int i(0), _l((int)(q)-1); i <= _l; ++i) {
    scanf("%d%d%d%d", &Q[i].X1, &Q[i].Y1, &Q[i].x2, &Q[i].y2);
    Q[i].n = i;
  }
  go();
  for (int i(0), _l((int)(k)-1); i <= _l; ++i) swap(d[i].first, d[i].second);
  for (int i(0), _l((int)(q)-1); i <= _l; ++i)
    swap(Q[i].X1, Q[i].Y1), swap(Q[i].x2, Q[i].y2);
  go();
  for (int i(0), _l((int)(q)-1); i <= _l; ++i)
    cout << (ans[i] ? "YES" : "NO") << endl;
}
int main() {
  clock_t tm = clock();
  cerr << setprecision(10);
  solve();
  cerr << setprecision(3) << (clock() - tm + 0.) / CLOCKS_PER_SEC << endl;
  return 0;
}
