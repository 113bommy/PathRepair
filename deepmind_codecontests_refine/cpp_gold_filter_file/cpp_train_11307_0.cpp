#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
struct Query {
  int t, l, r;
  Query(int t = 0, int l = 0, int r = 0) : t(t), l(l), r(r) {}
};
vector<Query> Que;
int n, Q;
int pr[N];
int a[N], aa[N];
int ls[N];
vector<int> vars[N * 4];
vector<long long> T[N * 4];
set<int> ids[N * 4];
long long Tsum[N * 4];
void addSTF(int p, int pos, int n, int val) {
  Tsum[p] += val;
  for (; pos <= n; pos += pos & (-pos)) T[p][pos] += val;
}
void build(int k, int p, int l, int r) {
  for (int i = l; i <= r; i++) {
    if (k == 0) {
      vars[p].push_back(pr[i]);
    } else {
      int pos = int(lower_bound(vars[p].begin(), vars[p].end(), pr[i]) -
                    vars[p].begin());
      assert(pos != vars[p].size());
      pos++;
      addSTF(p, pos, int(vars[p].size()), i - pr[i]);
    }
  }
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(k, p << 1, l, mid);
  build(k, p << 1 | 1, mid + 1, r);
}
void updateST(int k, int p, int l, int r, int pos, int pos2, int val) {
  if (k == 0) {
    vars[p].push_back(pos2);
  } else {
    int mypos = int(lower_bound(vars[p].begin(), vars[p].end(), pos2) -
                    vars[p].begin());
    assert(mypos != vars[p].size());
    mypos++;
    addSTF(p, mypos, int(vars[p].size()), val);
  }
  if (l == r) return;
  int m = (l + r) >> 1;
  if (pos <= m)
    updateST(k, p << 1, l, m, pos, pos2, val);
  else
    updateST(k, p << 1 | 1, m + 1, r, pos, pos2, val);
}
void DeleteST(int k, int l) {
  updateST(k, 1, 1, n, l, pr[l], -(l - pr[l]));
  auto it_np = ids[a[l]].upper_bound(l);
  if (it_np != ids[a[l]].end()) {
    int np = *it_np;
    updateST(k, 1, 1, n, np, pr[np], -(np - pr[np]));
    pr[np] = pr[l];
    updateST(k, 1, 1, n, np, pr[np], np - pr[np]);
  }
  ids[a[l]].erase(l);
  pr[l] = 0;
  a[l] = 0;
}
void InsertST(int k, int l, int val) {
  auto it_np = ids[val].upper_bound(l);
  int pre = 0;
  if (it_np != ids[val].end()) {
    int np = *it_np;
    updateST(k, 1, 1, n, np, pr[np], -(np - pr[np]));
    pre = pr[np];
    pr[np] = l;
    updateST(k, 1, 1, n, np, pr[np], (np - pr[np]));
  } else if (it_np != ids[val].begin()) {
    it_np--;
    pre = *it_np;
  }
  pr[l] = pre;
  a[l] = val;
  updateST(k, 1, 1, n, l, pr[l], (l - pr[l]));
  ids[val].insert(l);
}
long long getSumSTF(int p, int pos) {
  long long ret = 0;
  for (; pos; pos -= pos & (-pos)) ret += T[p][pos];
  return ret;
}
long long getSum(int p, int l, int r, int L, int R, int myL) {
  if (l == L && R == r) {
    int pos =
        int(lower_bound(vars[p].begin(), vars[p].end(), myL) - vars[p].begin());
    return Tsum[p] - getSumSTF(p, pos);
  }
  int mid = (l + r) >> 1;
  long long ret = 0;
  if (L <= mid) ret += getSum(p << 1, l, mid, L, min(mid, R), myL);
  if (mid < R) ret += getSum(p << 1 | 1, mid + 1, r, max(L, mid + 1), R, myL);
  return ret;
}
int main() {
  scanf("%d%d", &n, &Q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &aa[i]);
  }
  for (int i = 1; i <= Q; i++) {
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);
    Que.emplace_back(t, l, r);
  }
  for (int k = 0; k < 2; k++) {
    if (k) {
      for (int i = 1; i <= n; i++) ids[i].clear(), ls[i] = 0;
      for (int i = 0; i < 4 * N; i++)
        if (vars[i].size() >= 1) {
          sort(vars[i].begin(), vars[i].end());
          vars[i].erase(unique(vars[i].begin(), vars[i].end()), vars[i].end());
          T[i].assign(vars[i].size() + 1, 0);
        }
    }
    for (int i = 1; i <= n; i++) a[i] = aa[i];
    for (int i = 1; i <= n; i++) {
      pr[i] = ls[a[i]];
      ls[a[i]] = i;
      ids[a[i]].insert(i);
    }
    build(k, 1, 1, n);
    for (int i = 0; i < Q; i++) {
      int t, l, r;
      t = Que[i].t;
      l = Que[i].l;
      r = Que[i].r;
      if (t == 1) {
        DeleteST(k, l);
        InsertST(k, l, r);
      } else {
        if (k) printf("%I64d\n", getSum(1, 1, n, l, r, l));
      }
    }
  }
  return 0;
}
