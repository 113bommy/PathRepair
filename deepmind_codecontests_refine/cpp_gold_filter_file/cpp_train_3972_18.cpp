#include <bits/stdc++.h>
#pragma GCC optimize(                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           \
    "-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", \
    3)
#pragma GCC target("avx", "sse2")
const double esp = 1e-6;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int inf = 1e9;
using namespace std;
long long read() {
  char ch = getchar();
  long long x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int N = 6e5 + 10;
const int diff = 3e5;
int Q;
struct node {
  int pos, to, h;
  long long cntx, cnty;
  node(int pos, int to, int h, long long cntx, long long cnty) {
    this->pos = pos, this->to = to, this->h = h, this->cntx = cntx,
    this->cnty = cnty;
  }
};
struct DSU {
  int par[N], height[N];
  stack<node> st;
  long long cntx[N], cnty[N];
  long long sum = 0;
  DSU() {
    for (int i = 1; i <= 6e5 + 1; i++) {
      par[i] = i, height[i] = 1;
      if (i <= 3e5)
        cntx[i] = 1;
      else
        cnty[i] = 1;
    }
  }
  int find(int x) { return x == par[x] ? x : find(par[x]); }
  int unit(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return 0;
    if (height[x] < height[y]) swap(x, y);
    node sttemp(y, x, height[y], cntx[y], cnty[y]);
    st.push(sttemp);
    sum -= cntx[x] * cnty[x];
    sum -= cntx[y] * cnty[y];
    cntx[x] += cntx[y];
    cnty[x] += cnty[y];
    sum += cntx[x] * cnty[x];
    par[y] = x;
    height[x] += height[y];
    return 1;
  }
  void del() {
    node temp = st.top();
    st.pop();
    par[temp.pos] = temp.pos;
    height[temp.to] -= temp.h;
    sum -= cntx[temp.to] * cnty[temp.to];
    cntx[temp.to] -= temp.cntx;
    cnty[temp.to] -= temp.cnty;
    sum += cntx[temp.to] * cnty[temp.to];
    sum += cntx[temp.pos] * cnty[temp.pos];
  }
} dsu;
struct SEG {
  vector<pair<int, int> > tr[N << 2];
  void update(int l, int r, int root, int lf, int rt, pair<int, int> val) {
    if (lf <= l && r <= rt) {
      tr[root].push_back(val);
      return;
    }
    int mid = (l + r) >> 1;
    if (lf <= mid) update(l, mid, root << 1, lf, rt, val);
    if (rt > mid) update(mid + 1, r, root << 1 | 1, lf, rt, val);
  }
  void query(int l, int r, int root) {
    for (auto k : tr[root]) {
      dsu.unit(k.first, k.second + diff);
    }
    if (l == r) {
      printf("%lld ", dsu.sum);
      return;
    }
    int topp = dsu.st.size();
    int mid = (l + r) >> 1;
    query(l, mid, root << 1);
    while (dsu.st.size() > topp) dsu.del();
    query(mid + 1, r, root << 1 | 1);
    while (dsu.st.size() > topp) dsu.del();
  }
} sgt;
map<pair<int, int>, pair<int, int> > mp;
struct nd {
  int x, y, st, ed;
};
vector<nd> query;
int main() {
  Q = read();
  int x, y;
  int n = 6e5;
  for (int i = 1; i <= Q; i++) {
    x = read(), y = read();
    if (mp[{x, y}].first) {
      query.push_back(nd{x, y, mp[{x, y}].first, i - 1});
      mp[{x, y}].first = 0;
    } else {
      mp[{x, y}].first = i;
    }
  }
  for (auto k : mp) {
    if (k.second.first)
      query.push_back(nd{k.first.first, k.first.second, k.second.first, Q});
  }
  for (auto k : query) {
    sgt.update(1, Q, 1, k.st, k.ed, make_pair(k.x, k.y));
  }
  sgt.query(1, Q, 1);
  return 0;
}
