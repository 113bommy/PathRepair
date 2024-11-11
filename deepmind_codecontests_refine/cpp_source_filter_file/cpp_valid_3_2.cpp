#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
void read(T &x) {
  char ch;
  x = 0;
  int f = 1;
  while (isspace(ch = getchar_unlocked()))
    ;
  if (ch == '-') ch = getchar_unlocked(), f = -1;
  do x = x * 10 + (ch - '0');
  while (isdigit(ch = getchar_unlocked()));
  x *= f;
}
template <class T, class... A>
void read(T &x, A &...args) {
  read(x);
  read(args...);
}
const int N = 200005;
int a[N], b[N];
struct stack_elem {
  int val, mx;
  stack_elem() = default;
  stack_elem(int _v, int _m) : val(_v), mx(_m) {}
};
vector<stack_elem> S;
int bound[N];
struct suffix_bit {
  int t[N];
  void insert(int p, int v) {
    for (; p; p ^= p & -p) t[p] += v;
  }
  int query(int p) {
    int s = 0;
    for (; p < N; p += p & -p) s += t[p];
    return s;
  }
} T;
int fa[N], mn[N];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void join(int x, int y) {
  x = find(x);
  y = find(y);
  fa[x] = y;
  if (mn[x] <= mn[y])
    T.insert(mn[y], -1);
  else
    T.insert(mn[x], -1);
  mn[y] = min(mn[y], mn[x]);
}
int main() {
  int n, m, lim;
  read(n, m, lim);
  for (int i = 1; i <= n; ++i) read(a[i]);
  for (int i = 1; i <= m; ++i) read(b[i]);
  memset(bound, 0x3f, sizeof(bound));
  for (int i = 1; i <= n; ++i) {
    S.emplace_back(a[i], a[i]);
    while (S.size() > 1 && S.back().val < end(S)[-2].val) {
      int mx = max(S.back().mx, end(S)[-2].mx);
      S.pop_back();
      S.back().val = a[i];
      S.back().mx = mx;
    }
    if (S.size() > 1) bound[i] = min(bound[i], S.back().mx);
  }
  S.clear();
  for (int i = n; i >= 1; --i) {
    S.emplace_back(a[i], a[i]);
    while (S.size() > 1 && S.back().val <= end(S)[-2].val) {
      int mx = max(S.back().mx, end(S)[-2].mx);
      S.pop_back();
      S.back().val = a[i];
      S.back().mx = mx;
    }
    if (S.size() > 1) bound[i] = min(bound[i], S.back().mx);
  }
  vector<int> P(n), Q(m);
  iota(begin(P), end(P), 1);
  sort(begin(P), end(P), [](int x, int y) { return a[x] > a[y]; });
  iota(begin(Q), end(Q), 1);
  sort(begin(Q), end(Q), [](int x, int y) { return b[x] < b[y]; });
  auto it = begin(Q);
  int res = 0;
  for (int i : P) {
    for (; it != end(Q) && a[i] + b[*it] <= lim; ++it) {
      fa[*it] = *it;
      mn[*it] = b[*it];
      T.insert(b[*it], 1);
      if (fa[*it - 1]) join(*it, *it - 1);
      if (fa[*it + 1]) join(*it, *it + 1);
    }
    int L = max(lim - bound[i], 0);
    res += T.query(L + 1);
  }
  printf("%d\n", res);
  return 0;
}
