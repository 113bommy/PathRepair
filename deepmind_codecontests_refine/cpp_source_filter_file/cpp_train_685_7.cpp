#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
struct SQRT {
  int bsz;
  vector<long long> A, B;
  int n;
  void init(int n_) {
    n = n_;
    A.assign(n + 1, 0);
    bsz = sqrt(n) + 10;
    B.assign(bsz, 0);
  }
  void add(int idx, long long v) {
    A[idx] += v;
    B[bsz] += v;
  }
  long long query(int idx) {
    int bl = idx / bsz;
    long long ret = 0;
    for (int i = 0; i < bl; i++) ret += B[i];
    for (int i = bl * bsz; i <= idx; i++) ret += A[i];
    return ret;
  }
  long long query(int l, int r) { return query(r) - query(l - 1); }
} S;
int sp[N];
int a[N];
vector<int> occ[N];
vector<pair<int, int>> Query[N];
set<int> pos[N];
tuple<int, int, int> queries[N];
const int B = 100;
long long res[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]].insert(i);
  }
  S.init(n);
  for (int qi = 1; qi <= q; qi += B) {
    int ql = qi, qr = min(qi + B - 1, q);
    vector<int> imp;
    memset(sp, 0, sizeof sp);
    for (int i = ql; i <= qr; i++) {
      int t, x, y;
      cin >> t >> x >> y;
      queries[i] = (make_tuple(t, x, y));
      if (t == 1) {
        sp[a[x]] = true;
        sp[y] = true;
      }
      if (t == 2) {
        Query[x].push_back({y, i});
      }
    }
    for (int i = n; i >= 1; i--) {
      if (!sp[a[i]]) {
        occ[a[i]].push_back(i);
      }
    }
    for (int i = 1; i <= n; i++) {
      if (occ[i].size() > 0) S.add(occ[i].back(), occ[i].back());
    }
    for (int i = 1; i <= n; i++) {
      for (auto t : Query[i]) {
        int r = t.first, idx = t.second;
        res[idx] -= S.query(i, r);
      }
      Query[i].clear();
      if (!sp[a[i]]) {
        S.add(occ[a[i]].back(), -occ[a[i]].back());
        occ[a[i]].pop_back();
        if (occ[a[i]].size() > 0) S.add(occ[a[i]].back(), occ[a[i]].back());
      }
    }
    for (int i = ql; i <= qr; i++) {
      int t = get<0>(queries[i]);
      int l = get<1>(queries[i]);
      int r = get<2>(queries[i]);
      if (t == 2) Query[r].push_back(make_pair(l, i));
    }
    for (int i = 1; i <= n; i++) {
      if (!sp[a[i]]) {
        occ[a[i]].push_back(i);
      }
    }
    for (int i = 1; i <= n; i++) {
      if (occ[i].size() > 0) S.add(occ[i].back(), occ[i].back());
    }
    for (int i = n; i >= 1; i--) {
      for (auto t : Query[i]) {
        int l = t.first, idx = t.second;
        res[idx] += S.query(l, i);
      }
      Query[i].clear();
      if (!sp[a[i]]) {
        S.add(occ[a[i]].back(), -occ[a[i]].back());
        occ[a[i]].pop_back();
        if (occ[a[i]].size() > 0) S.add(occ[a[i]].back(), occ[a[i]].back());
      }
    }
    for (int i = 1; i <= n; i++) {
      if (sp[i]) imp.push_back(i);
    }
    for (int i = ql; i <= qr; i++) {
      int t = get<0>(queries[i]);
      int l = get<1>(queries[i]);
      int r = get<2>(queries[i]);
      if (t == 1) {
        pos[a[l]].erase(l);
        a[l] = r;
        pos[a[l]].insert(l);
      } else {
        for (int x : imp) {
          auto it = pos[x].lower_bound(l);
          if (it != pos[x].end() && (*it) <= r) {
            res[i] -= *it;
            it = pos[x].upper_bound(r);
            it--;
            res[i] += *it;
          }
        }
      }
    }
  }
  for (int i = 1; i <= q; i++) {
    if (get<0>(queries[i]) == 2) {
      cout << res[i] << "\n";
    }
  }
  return 0;
}
