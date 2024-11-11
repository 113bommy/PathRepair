#include <bits/stdc++.h>
using namespace std;
struct BITree {
  vector<long long> sum;
  int n;
  BITree() {}
  void init(int nn) {
    n = nn;
    for (int i = 0; i <= n; i++) {
      sum.push_back(0LL);
    }
  }
  long long query(int k) {
    long long res = 0;
    while (k > 0) {
      res += sum[k];
      k -= k & -k;
    }
    return res;
  }
  void add(int k, long long x) {
    while (k <= n) {
      sum[k] += x;
      k += k & -k;
    }
  }
};
struct segtree {
  vector<BITree> bit;
  static const int n = (1 << 17);
  vector<int> ids[1 << 18];
  segtree() {}
  void init() {
    for (int i = 0; i < n * 2 - 1; i++) {
      bit.push_back(BITree());
    }
    for (int i = n - 1; i < n * 2 - 1; i++) {
      ids[i].push_back(-1);
      sort(ids[i].begin(), ids[i].end());
      ids[i].erase(unique(ids[i].begin(), ids[i].end()), ids[i].end());
      bit[i].init(ids[i].size());
    }
    for (int i = n - 2; i >= 0; i--) {
      for (int j = 0; j < ids[i * 2 + 1].size(); j++) {
        ids[i].push_back(ids[i * 2 + 1][j]);
      }
      for (int j = 0; j < ids[i * 2 + 2].size(); j++) {
        ids[i].push_back(ids[i * 2 + 2][j]);
      }
      sort(ids[i].begin(), ids[i].end());
      ids[i].erase(unique(ids[i].begin(), ids[i].end()), ids[i].end());
      bit[i].init(ids[i].size());
    }
  }
  void addnode(int k, int val) {
    k += n - 1;
    ids[k].push_back(val);
  }
  void add(int f, int t, int val) {
    int k = f + n - 1;
    int pos = lower_bound(ids[k].begin(), ids[k].end(), t) - ids[k].begin();
    bit[k].add(pos, val);
    while (k > 0) {
      k = (k - 1) / 2;
      pos = lower_bound(ids[k].begin(), ids[k].end(), t) - ids[k].begin();
      bit[k].add(pos, val);
    }
  }
  long long query(int a, int b, int k = 0, int l = 0, int r = n) {
    if (b <= l || r <= a) return 0;
    if (a <= l && r <= b) {
      int lef = lower_bound(ids[k].begin(), ids[k].end(), a) - ids[k].begin();
      int rig = lower_bound(ids[k].begin(), ids[k].end(), b) - ids[k].begin();
      return bit[k].query(rig - 1) - bit[k].query(lef - 1);
    }
    long long vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    long long vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return vl + vr;
  }
};
segtree seg;
int n, m;
int a[100001];
int tmp[100001];
set<int> now[100001];
int typ[100001], p[100001], val[100001];
int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
    now[a[i]].insert(i);
    tmp[i] = a[i];
  }
  for (int i = 0; i < n; i++) {
    set<int>::iterator it = now[a[i]].upper_bound(i);
    if (it != now[a[i]].end()) {
      seg.addnode(i, *it);
    }
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &typ[i], &p[i], &val[i]);
    p[i]--;
    if (typ[i] == 1) {
      val[i]--;
      int prev = a[p[i]];
      if (prev == val[i]) continue;
      now[prev].erase(p[i]);
      set<int>::iterator it = now[prev].upper_bound(p[i]);
      if (it != now[prev].end() && it != now[prev].begin()) {
        it--;
        int f = *it;
        it++;
        seg.addnode(f, *it);
      }
      a[p[i]] = val[i];
      int next = a[p[i]];
      it = now[next].upper_bound(p[i]);
      if (it != now[next].end()) {
        seg.addnode(p[i], *it);
      }
      if (it != now[next].begin()) {
        it--;
        seg.addnode(*it, p[i]);
      }
      now[next].insert(p[i]);
    }
  }
  seg.init();
  for (int i = 0; i < n; i++) {
    now[i].clear();
    a[i] = tmp[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    now[a[i]].insert(i);
    set<int>::iterator it = now[a[i]].upper_bound(i);
    if (it != now[a[i]].end()) {
      seg.add(i, *it, (*it) - i);
    }
  }
  for (int i = 0; i < m; i++) {
    if (typ[i] == 1) {
      int prev = a[p[i]];
      if (val[i] == prev) continue;
      now[prev].erase(p[i]);
      set<int>::iterator it = now[prev].upper_bound(p[i]);
      if (it != now[prev].end()) {
        int va = *it;
        seg.add(p[i], va, p[i] - va);
        if (it != now[prev].begin()) {
          it--;
          seg.add(*it, p[i], (*it) - p[i]);
          seg.add(*it, va, va - (*it));
        }
      } else if (it != now[prev].begin()) {
        it--;
        seg.add(*it, p[i], (*it) - p[i]);
      }
      it = now[val[i]].upper_bound(p[i]);
      if (it != now[val[i]].end()) {
        seg.add(p[i], *it, (*it) - p[i]);
        if (it != now[val[i]].begin()) {
          int np = *it;
          it--;
          seg.add(*it, np, (*it) - np);
          seg.add(*it, p[i], p[i] - (*it));
        }
      } else if (it != now[val[i]].begin()) {
        it--;
        seg.add(*it, p[i], p[i] - (*it));
      }
      now[val[i]].insert(p[i]);
      a[p[i]] = val[i];
    } else {
      printf("%lld\n", seg.query(p[i], val[i]));
    }
  }
  return 0;
}
