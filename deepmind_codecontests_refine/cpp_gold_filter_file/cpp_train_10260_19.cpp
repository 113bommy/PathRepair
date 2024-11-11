#include <bits/stdc++.h>
using namespace std;
inline int IN() {
  char c;
  register int first = 0;
  for (; (c = getchar()) < 48 && c ^ '-' || c > 57;)
    ;
  bool f = c == '-';
  if (f) (c = getchar());
  for (; c > 47 && c < 58; (c = getchar()))
    first = (first << 3) + (first << 1) + c - 48;
  if (f) first = -first;
  return first;
}
inline void glance() { freopen("ha.in", "r", stdin); }
const int frc = 512;
int n, M;
struct Info {
  int l, r, id;
} p[100010];
typedef int Arr[300010];
Arr a, tt, cnt, pre, nxt, ans;
inline void del(int first) {
  int &u = cnt[first], v = pre[u];
  --tt[u];
  if (tt[u] == 0) {
    nxt[pre[u]] = nxt[u];
    pre[nxt[u]] = pre[u];
    nxt[u] = pre[u] = 0;
  }
  --u;
  ++tt[u];
  if (tt[u] == 1) {
    nxt[u] = nxt[v];
    pre[u] = v;
    pre[nxt[u]] = nxt[pre[u]] = u;
  }
}
inline void ins(int first) {
  int &u = cnt[first], v = nxt[u];
  --tt[u];
  if (tt[u] == 0) {
    nxt[pre[u]] = nxt[u];
    pre[nxt[u]] = pre[u];
    nxt[u] = pre[u] = 0;
  }
  ++u;
  ++tt[u];
  if (tt[u] == 1) {
    pre[u] = pre[v];
    nxt[u] = v;
    pre[nxt[u]] = nxt[pre[u]] = u;
  }
}
deque<pair<int, int> > Q[2];
inline int huff() {
  Q[0].resize(0);
  Q[1].resize(0);
  for (int u = nxt[0]; u ^ n + 1; u = nxt[u]) Q[0].push_back({u, tt[u]});
  for (int ans = 0;;) {
    if (Q[0].size() && Q[1].size() && Q[0][0].first == Q[1][0].first) {
      Q[1][0].second += Q[0][0].second;
      Q[0].pop_front();
      continue;
    }
    int a = Q[0].size()
                ? Q[1].size() ? Q[0][0].first < Q[1][0].first ? 0 : 1 : 0
                : 1;
    pair<int, int> it = Q[a].front();
    Q[a].pop_front();
    if (it.second > 1) {
      ans += it.second / 2 * it.first * 2;
      Q[1].push_back({it.first * 2, it.second / 2});
      if (it.second & 1) Q[a].push_front({it.first, 1});
      continue;
    } else {
      int b = Q[0].size()
                  ? Q[1].size() ? Q[0][0].first < Q[1][0].first ? 0 : 1 : 0
                  : 1;
      if (!Q[b].size()) return ans;
      pair<int, int> ti = Q[b].front();
      Q[b].pop_front();
      ans += it.first + ti.first;
      Q[1].push_back({it.first + ti.first, 1});
      if (ti.second > 1) Q[b].push_front({ti.first, ti.second - 1});
      continue;
    }
  }
}
int main() {
  n = IN();
  for (int _r = n, i = 1; i <= _r; ++i) a[i] = IN();
  M = IN();
  for (int _r = M, i = 1; i <= _r; ++i)
    p[i].l = IN(), p[i].r = IN(), p[i].id = i;
  sort(p + 1, p + M + 1, [](const Info& A, const Info& B) {
    return A.l / frc == B.l / frc ? A.r < B.r : A.l < B.l;
  });
  int l = 1, r = 0;
  nxt[0] = n + 1;
  pre[n + 1] = 0;
  tt[0] = tt[n + 1] = n * 3;
  for (int _r = M, i = 1; i <= _r; ++i) {
    int L = p[i].l, R = p[i].r;
    for (; l < L; ++l) del(a[l]);
    for (; l > L; --l) ins(a[l - 1]);
    for (; r < R; ++r) ins(a[r + 1]);
    for (; r > R; --r) del(a[r]);
    ans[p[i].id] = huff();
  }
  for (int _r = M, i = 1; i <= _r; ++i) printf("%d\n", ans[i]);
}
