#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
struct node {
  int l, r, lmax, rmax, totmax, totmin, lcnt, rcnt, ans;
  node()
      : l(0),
        r(0),
        lmax(0),
        rmax(0),
        totmax(0),
        totmin(0),
        lcnt(0),
        rcnt(0),
        ans(0) {}
  node(int l, int r, int lmax, int rmax, int totmax, int totmin, int lcnt,
       int rcnt, int ans)
      : l(l),
        r(r),
        lmax(lmax),
        rmax(rmax),
        totmax(totmax),
        totmin(totmin),
        lcnt(lcnt),
        rcnt(rcnt),
        ans(ans) {}
};
node operator+(node l, node r) {
  node ret = node(0, 0, 0, 0, 0, 0, 0, 0, 0);
  ret.l = l.l;
  ret.r = r.r;
  ret.totmin = min(l.totmin, r.totmin);
  ret.totmax = max(l.totmax, r.totmax);
  if (ret.totmin == l.totmin)
    ret.lmax = l.lmax, ret.lcnt = l.lcnt, ret.ans += l.ans;
  else
    ret.lmax = max(l.totmax, r.lmax), ret.lcnt = (l.r - l.l + 1) + r.lcnt;
  if (ret.totmin == r.totmin)
    ret.rmax = r.rmax, ret.rcnt = r.rcnt, ret.ans += r.ans;
  else
    ret.rmax = max(l.rmax, r.totmax), ret.rcnt = (r.r - r.l + 1) + l.rcnt;
  if (l.totmin == r.totmin)
    ret.ans += l.rcnt + r.lcnt + 1 - max(l.rmax, r.rmax);
  return ret;
}
struct seg {
  int N;
  vector<node> A;
  vector<int> L;
  void init_node(int here, int l, int r) {
    if (l == r) {
      A[here] = node(l, r, 0, 0, 0, 0, 0, 0, 0);
      return;
    }
    int mid = (l + r) / 2;
    init_node((here << 1 | 0), l, mid);
    init_node((here << 1 | 1), mid + 1, r);
    A[here] = A[(here << 1 | 0)] + A[(here << 1 | 1)];
  }
  seg() {}
  seg(int N) : N(N) {
    A.resize(N * 4, node());
    L.resize(N * 4);
    init_node(1, 0, N - 1);
  }
  void f(int here, int l, int r) {
    A[here].totmin += L[here];
    if (l != r) {
      L[(here << 1 | 0)] += L[here];
      L[(here << 1 | 1)] += L[here];
    }
    L[here] = 0;
  }
  void update_p(int here, int l, int r, int pos, int val) {
    f(here, l, r);
    if (pos < l || r < pos) return;
    if (l == r) {
      A[here].totmax = val;
      A[here].lmax = val;
      A[here].rmax = val;
      return;
    }
    int mid = (l + r) / 2;
    update_p((here << 1 | 0), l, mid, pos, val);
    update_p((here << 1 | 1), mid + 1, r, pos, val);
    A[here] = A[(here << 1 | 0)] + A[(here << 1 | 1)];
  }
  void update(int here, int l, int r, int x, int y, int val) {
    f(here, l, r);
    if (y < l || r < x) return;
    if (x <= l && r <= y) {
      L[here] += val;
      f(here, l, r);
      return;
    }
    int mid = (l + r) / 2;
    update((here << 1 | 0), l, mid, x, y, val);
    update((here << 1 | 1), mid + 1, r, x, y, val);
    A[here] = A[(here << 1 | 0)] + A[(here << 1 | 1)];
  }
};
int N, M;
int A[MAXN];
set<int> S[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> N >> M;
  for (int i = 1; i <= N; i++) cin >> A[i];
  for (int i = 1; i <= N; i++) S[A[i]].insert(i);
  seg SEG = seg(N + 1);
  for (int i = 1; i <= 200000; i++)
    if (S[i].size()) {
      int l = *S[i].begin();
      int r = *S[i].rbegin();
      SEG.update_p(1, 0, N, l, S[i].size());
      if (l < r) SEG.update(1, 0, N, l, r - 1, 1);
    }
  cout << SEG.A[1].ans << '\n';
  for (int i = 1; i <= M; i++) {
    int a, b;
    cin >> a >> b;
    if (A[a] != b) {
      int pc = A[a];
      SEG.update_p(1, 0, N, *S[pc].begin(), 0);
      if (*S[pc].begin() < *S[pc].rbegin())
        SEG.update(1, 0, N, *S[pc].begin(), *S[pc].rbegin() - 1, -1);
      S[pc].erase(a);
      if (S[pc].size()) {
        SEG.update_p(1, 0, N, *S[pc].begin(), S[pc].size());
        if (*S[pc].begin() < *S[pc].rbegin())
          SEG.update(1, 0, N, *S[pc].begin(), *S[pc].rbegin() - 1, 1);
      }
      A[a] = b;
      if (S[b].size()) {
        SEG.update_p(1, 0, N, *S[b].begin(), 0);
        if (*S[b].begin() < *S[b].rbegin())
          SEG.update(1, 0, N, *S[b].begin(), *S[b].rbegin() - 1, -1);
      }
      S[b].insert(a);
      SEG.update_p(1, 0, N, *S[b].begin(), S[b].size());
      if (*S[b].begin() < *S[b].rbegin())
        SEG.update(1, 0, N, *S[b].begin(), *S[b].rbegin() - 1, 1);
    }
    cout << SEG.A[1].ans << '\n';
  }
  return 0;
}
