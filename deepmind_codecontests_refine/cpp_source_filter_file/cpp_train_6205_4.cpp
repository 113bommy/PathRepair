#include <bits/stdc++.h>
using namespace std;
int n, q, fa[100010], dep[100010], val[100010];
class option {
 public:
  int p1, v1, d1, f1, p2, v2, d2, f2;
};
vector<option> v;
inline int getf(int x) { return x == fa[x] ? x : fa[x]; }
inline int getval(int x) {
  if (x == fa[x]) return val[x];
  return val[x] ^ getval(fa[x]);
}
inline void rollback() {
  option p = v.back();
  fa[p.p1] = p.f1;
  fa[p.p2] = p.f2;
  val[p.p1] = p.v1;
  val[p.p2] = p.v2;
  dep[p.p1] = p.d1;
  dep[p.p2] = p.d2;
  v.pop_back();
}
inline int Modify(int x, int y) {
  int ti = getf(x), tj = getf(y);
  int v1 = getval(x), v2 = getval(y);
  if (ti == tj) {
    if (v1 == v2) return 1;
    return 0;
  } else {
    v.push_back(
        (option){ti, val[ti], dep[ti], fa[ti], tj, val[tj], dep[tj], fa[tj]});
    if (dep[ti] > dep[tj]) swap(ti, tj);
    fa[ti] = tj;
    val[ti] = v1 ^ v2 ^ 1;
    if (dep[ti] == dep[tj]) dep[tj]++;
    return -1;
  }
}
class sgt {
 public:
  vector<pair<int, int> > dat[400010];
  void modify(int p, int l, int r, int ml, int mr, pair<int, int> v) {
    if (ml <= l && r <= mr) {
      dat[p].push_back(v);
      return;
    }
    int mid = (l + r) >> 1;
    if (ml <= mid) modify((p << 1), l, mid, ml, mr, v);
    if (mr > mid) modify(((p << 1) | 1), mid + 1, r, ml, mr, v);
  }
  void query(int p, int l, int r, int flag) {
    int ccnt = 0;
    for (auto &x : dat[p]) {
      int tmp = Modify(x.first, x.second);
      if (tmp == -1)
        ccnt++;
      else
        flag |= tmp;
    }
    if (l == r) {
      if (flag)
        puts("NO");
      else
        puts("YES");
    } else {
      int mid = (l + r) >> 1;
      query((p << 1), l, mid, flag);
      query(((p << 1) | 1), mid + 1, r, flag);
    }
    for (int i = 0; i < ccnt; i++) rollback();
  }
} T;
map<pair<int, int>, int> mp;
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1, ti, tj; i <= q; i++) {
    scanf("%d%d", &ti, &tj);
    if (mp.find(make_pair(ti, tj)) != mp.end())
      T.modify(1, 1, q, mp[make_pair(ti, tj)], i - 1, make_pair(ti, tj)),
          mp.erase(make_pair(ti, tj));
    else
      mp[make_pair(ti, tj)] = i;
  }
  for (auto &x : mp) T.modify(1, 1, q, x.second, q, x.first);
  T.query(1, 1, q, 0);
  return 0;
}
