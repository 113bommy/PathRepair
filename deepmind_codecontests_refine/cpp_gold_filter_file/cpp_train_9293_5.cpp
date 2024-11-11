#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
const long long mod = 998244353;
const long long Inf = 1e18;
vector<int> g[N], id, G[N];
int L[N], R[N], n, a[2500000], b[2500000], cnt, LL[N], RR[N], L_[N], R_[N];
struct node {
  int id, d;
} p[2500000];
bool vis[N];
int x_1[N], y_1[N], y_2[N];
long long x_2[N];
int mini[2500000];
inline int solve(const int &l, const int &r, vector<int> &id) {
  vector<int> nl, nr;
  int cnt = 0, mid = l + r >> 1, len = 1, llen, rlen;
  for (auto i : id) {
    int l_ = LL[i], r_ = RR[i];
    if (l_ <= l && r <= r_) {
      id[cnt++] = i;
    } else {
      if (l_ <= mid) nl.push_back(i);
      if (r_ > mid) nr.push_back(i);
    }
  }
  id.resize(cnt);
  if (l < r) {
    llen = solve(l, mid, nl);
    rlen = solve(mid + 1, r, nr);
    int lp = l, rp = mid + 1;
    for (register int i = (l); i < (l + llen + rlen); ++i) {
      if (lp == l + llen)
        b[i] = a[rp++];
      else if (rp == mid + rlen + 1)
        b[i] = a[lp++];
      else if (a[lp] < a[rp])
        b[i] = a[lp++];
      else
        b[i] = a[rp++];
    }
    len = unique(b + l, b + l + llen + rlen) - b - l;
    for (register int i = (l); i < (l + len); ++i) a[i] = b[i];
  }
  for (auto w : id)
    for (auto i : G[w]) {
      int pos = upper_bound(a + l, a + l + len, p[i].d) - a;
      if (pos >= l + len) continue;
      mini[i] = min(mini[i], a[pos]);
    }
  id.clear();
  return len;
}
int main() {
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) g[j].push_back(i);
  }
  long long nn, m, l, r;
  scanf("%lld%lld%lld%lld", &nn, &m, &l, &r);
  for (register int i = (1); i < (m + 1); ++i) {
    L[i] = n + 1;
    for (auto v : g[i]) a[++n] = v;
    R[i] = n;
  }
  for (register int i = (1); i < (nn + 1); ++i) {
    x_1[i] = i;
    long long pl = (l + i - 1) / i, pr = min(m, r / i);
    if (pl > pr) continue;
    LL[i] = L[pl], RR[i] = R[pr];
    L_[i] = pl, R_[i] = pr;
    for (auto v : g[i]) {
      p[++cnt] = (node){i, v};
      mini[cnt] = 1000000;
      G[i].push_back(cnt);
    }
    id.push_back(i);
  }
  for (register int i = (1); i < (N); ++i) g[i].clear();
  solve(1, n, id);
  for (register int i = (1); i < (cnt + 1); ++i) {
    if (vis[p[i].id]) continue;
    if (mini[i] == 1000000) continue;
    int id = p[i].id, k = R_[id] / mini[i];
    y_1[id] = k * mini[i];
    y_2[id] = k * p[i].d;
    x_2[id] = 1ll * x_1[id] * y_1[id] / y_2[id];
    if (x_2[id] <= nn) vis[id] = 1;
  }
  for (register int i = (1); i < (nn + 1); ++i) {
    if (!vis[i])
      printf("-1\n");
    else
      printf("%d %d %lld %d\n", x_1[i], y_1[i], x_2[i], y_2[i]);
  }
}
