#include <bits/stdc++.h>
using namespace std;
void open() {
  freopen("fence.in", "r", stdin);
  freopen("fence.out", "w", stdout);
}
int n, m;
class Query {
 public:
  int l, r, w;
  void read() { scanf("%d%d%d", &l, &r, &w); }
} d[300000];
class Array {
 public:
  int pos, val;
  void read(int p) {
    scanf("%d", &val);
    pos = p;
  }
} a[300000];
class Re {
 public:
  int m, p, s;
  Re(int M = 0, int P = 0, int S = 0) {
    m = M;
    p = P;
    s = S;
  }
};
bool operator<(Array a, Array b) { return a.val > b.val; }
class segment_tree {
 public:
  int l[500000], r[500000], ans, uto[500000];
  int pre[500000], suf[500000], len[500000];
  vector<int> vec;
  void main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) a[i].read(i);
    sort(a + 1, a + n + 1);
    build(1, 1, n);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) d[i].read();
    for (int i = 1; i <= m; ++i) vec.push_back(i);
    cdq(vec, 1, n);
    for (int i = 1; i <= m; ++i) printf("%d\n", a[uto[i]].val);
  }

 private:
  void build(int x, int L, int R) {
    l[x] = L;
    r[x] = R;
    if (L == R) return;
    build((x << 1), L, ((l[x] + r[x]) >> 1));
    build(((x << 1) | 1), ((l[x] + r[x]) >> 1) + 1, R);
  }
  void updata(int x) {
    len[x] = max(len[(x << 1)], len[((x << 1) | 1)]);
    len[x] = max(pre[((x << 1) | 1)] + suf[(x << 1)], len[x]);
    if (len[(x << 1)] == r[(x << 1)] - l[(x << 1)] + 1)
      pre[x] = len[(x << 1)] + pre[((x << 1) | 1)];
    else
      pre[x] = pre[(x << 1)];
    if (len[((x << 1) | 1)] == r[((x << 1) | 1)] - r[((x << 1) | 1)] + 1)
      suf[x] = len[((x << 1) | 1)] + suf[(x << 1)];
    else
      suf[x] = suf[((x << 1) | 1)];
  }
  void insert(int x, int pos, int val) {
    if (l[x] == r[x] && l[x] == pos) {
      len[x] = pre[x] = suf[x] = val;
      return;
    }
    if (pos <= ((l[x] + r[x]) >> 1))
      insert((x << 1), pos, val);
    else
      insert(((x << 1) | 1), pos, val);
    updata(x);
  }
  Re query(int x, int L, int R) {
    if (l[x] >= L && r[x] <= R) {
      ans = max(ans, len[x]);
      return Re(len[x], pre[x], suf[x]);
    }
    Re ll, rr, re;
    if (L <= ((l[x] + r[x]) >> 1)) ll = query((x << 1), L, R);
    if (R > ((l[x] + r[x]) >> 1)) rr = query(((x << 1) | 1), L, R);
    if (ll.p == min(((l[x] + r[x]) >> 1), R) - max(L, l[x]) + 1)
      re.p = ll.p + rr.p;
    else
      re.p = ll.p;
    if (rr.s == min(R, r[x]) - max(((l[x] + r[x]) >> 1), L))
      re.s = rr.s + ll.s;
    else
      re.s = rr.s;
    re.m = max(ll.m, rr.m);
    re.m = max(re.m, ll.s + rr.p);
    ans = max(ans, re.m);
    return re;
  }
  void cdq(vector<int> q, int L, int R) {
    vector<int> ql, qr;
    int sz = q.size();
    if (L == R) {
      for (int i = 0; i < sz; ++i) uto[q[i]] = L;
      return;
    }
    int MID = (L + R) >> 1;
    for (int i = L; i <= MID; ++i) insert(1, a[i].pos, 1);
    for (int i = 0; i < sz; ++i) {
      ans = 0;
      query(1, d[q[i]].l, d[q[i]].r);
      if (ans >= d[q[i]].w)
        ql.push_back(q[i]);
      else
        qr.push_back(q[i]);
    }
    cdq(qr, MID + 1, R);
    for (int i = L; i <= MID; ++i) insert(1, a[i].pos, 0);
    cdq(ql, L, MID);
  }
} diary;
int main() {
  diary.main();
  return 0;
}
