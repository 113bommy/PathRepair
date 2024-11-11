#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3, mod = 1e9 + 7;
int n, K, L, x[maxn + 5], y[maxn + 5], c[maxn + 5], m, py[maxn + 5], cur, hei;
int Q, M, X[maxn + 5], Y[maxn + 5], st[maxn + 5], lc[maxn + 5], rc[maxn + 5];
long long A;
vector<int> vec[maxn + 5];
set<pair<int, int> > S;
inline void red(int &x) { x += x >> 31 & mod; }
template <class type>
inline void cmax(type &x, type y) {
  x < y ? x = y : 0;
}
template <class type>
inline void cmin(type &x, type y) {
  x > y ? x = y : 0;
}
inline bool comp(int i, int j) {
  return x[i] == x[j] ? y[i] < y[j] : x[i] < x[j];
}
struct rect {
  int l, r, h;
  rect(int l = 0, int r = 0, int h = 0) : l(l), r(r), h(h) {}
  bool operator<(const rect &o) const { return l < o.l; }
} foo[3 * maxn + 5];
void work(int x, int l, int r) {
  if (Y[x] > cur) foo[++Q] = rect(X[l - 1] + 1, X[r + 1] - 1, Y[x] - cur);
  if (lc[x]) work(lc[x], l, x - 1);
  if (rc[x]) work(rc[x], x + 1, r);
}
int F(int x) { return 1ll * x * (x + 1) / 2 % mod; }
void insert(int x, int y) {
  auto it = S.lower_bound(pair<int, int>(x + 1, 0));
  while (it != S.begin()) {
    if ((--it)->second > y) break;
    int L = 0, D = 0;
    if (it != S.begin()) {
      auto it0 = it;
      L = (--it0)->first;
    }
    auto it0 = it;
    ++it0;
    if (it0 != S.end()) {
      D = it0->second;
    }
    A -= 1ll * (it->first - L) * (it->second - D);
    S.erase(it);
    it = S.lower_bound(pair<int, int>(x + 1, 0));
  }
  it = S.lower_bound(pair<int, int>(x, 0));
  if (it != S.end() && it->second >= y) return;
  int L = 0, D = 0;
  if (it != S.end()) D = it->second;
  if (it != S.begin()) L = (--it)->first;
  A += 1ll * (x - L) * (y - D);
  S.insert(pair<int, int>(x, y));
}
int main() {
  scanf("%d %d %d", &n, &K, &L);
  for (int i = (1); i <= int(n); i++) {
    scanf("%d %d %d", &x[i], &y[i], &c[i]);
    x[i]++, y[i]++, py[i] = y[i];
  }
  sort(py + 1, py + n + 1);
  m = unique(py + 1, py + n + 1) - (py + 1);
  int ans = 0;
  for (int k = (1); k <= int(m); k++) {
    cur = py[k], hei = L + 1 - cur;
    for (int i = (1); i <= int(K); i++) vector<int>().swap(vec[i]);
    for (int i = (1); i <= int(n); i++)
      if (y[i] >= py[k]) vec[c[i]].push_back(i);
    bool fl = false;
    for (int i = (1); i <= int(K); i++)
      if (vec[i].empty()) {
        fl = true;
        break;
      }
    if (fl) break;
    Q = 0;
    for (int i = (1); i <= int(K); i++) {
      sort(vec[i].begin(), vec[i].end(), comp);
      M = 0;
      for (int j = (0); j <= int(vec[i].size() - 1); j++)
        if (!j || x[vec[i][j]] != x[vec[i][j - 1]]) {
          X[++M] = x[vec[i][j]], Y[M] = y[vec[i][j]];
        }
      sort(X + 1, X + M + 1);
      X[0] = 0, X[M + 1] = L + 1;
      for (int i = (1); i <= int(M); i++) lc[i] = rc[i] = 0;
      int rt = 1, top = 0;
      for (int i = (1); i <= int(M); i++) {
        if (Y[i] <= Y[rt]) rt = i;
        int x = 0;
        while (top && Y[st[top]] >= Y[i]) x = st[top--];
        if (top) rc[st[top]] = i;
        lc[i] = x;
        st[++top] = i;
      }
      work(rt, 1, M);
      for (int i = (1); i <= int(M + 1); i++)
        if (X[i] > X[i - 1] + 1) {
          foo[++Q] = rect(X[i - 1] + 1, X[i] - 1, hei);
        }
    }
    sort(foo + 1, foo + Q + 1);
    foo[Q + 1].l = L + 1;
    set<pair<int, int> >().swap(S), A = 0;
    int res = 0;
    for (int i = (1); i <= int(Q); i++) {
      insert(foo[i].r, foo[i].h);
      int x = foo[i].l;
      while (!S.empty()) {
        auto it = S.begin();
        int y = min(it->first + 1, foo[i + 1].l);
        red(res += A % mod * (y - x) % mod - mod);
        red(res -= 1ll * (x + y - 3) * (y - x) / 2 % mod * it->second % mod);
        x = y;
        if (it->first + 1 > foo[i + 1].l) break;
        int D = 0;
        auto it0 = it;
        it0++;
        if (it0 != S.end()) D = it0->second;
        A -= 1ll * it->first * (it->second - D);
        S.erase(it);
      }
    }
    red(res = 1ll * F(L) * hei % mod - res);
    red(ans += 1ll * (py[k] - py[k - 1]) * res % mod - mod);
  }
  printf("%d\n", ans);
  return 0;
}
