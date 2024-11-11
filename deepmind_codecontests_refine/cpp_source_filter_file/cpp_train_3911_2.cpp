#include <bits/stdc++.h>
const int MaxN = 4e5 + 50;
template <class t>
inline void read(t &s) {
  s = 0;
  register int f = 1;
  register char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
  s *= f;
  return;
}
template <class t, class... A>
inline void read(t &x, A &...a) {
  read(x);
  read(a...);
}
template <class t>
inline void write(t x) {
  if (x < 0) putchar('-'), x = -x;
  int buf[21], top = 0;
  while (x) buf[++top] = x % 10, x /= 10;
  if (!top) buf[++top] = 0;
  while (top) putchar(buf[top--] ^ '0');
  return;
}
inline void setIn(std::string s) {
  freopen(s.c_str(), "r", stdin);
  return;
}
inline void setOut(std::string s) {
  freopen(s.c_str(), "w", stdout);
  return;
}
inline void setIO(std::string s = "") {
  setIn(s + ".in");
  setOut(s + ".out");
  return;
}
template <class t>
inline bool checkmin(t &x, t y) {
  if (x > y) {
    x = y;
    return 1;
  }
  return 0;
}
template <class t>
inline bool checkmax(t &x, t y) {
  if (x < y) {
    x = y;
    return 1;
  }
  return 0;
}
inline int lowbit(int x) { return x & (-x); }
struct Edge {
  int u, v;
} E[MaxN];
int n, m, S, T, ds, dt;
struct DSU {
  int f[MaxN];
  inline void reset() {
    for (int i = 1; i <= n; ++i) f[i] = i;
  }
  inline int getf(int x) { return f[x] == x ? x : f[x] = getf(f[x]); }
  inline int merge(int x, int y) {
    if (getf(x) == getf(y)) return 0;
    return f[f[x]] = f[y], 1;
  }
  inline bool check() {
    for (int i = (1); i <= (n); ++i)
      if (getf(i) != getf(1)) return 0;
    return 1;
  }
} dsu;
std::vector<int> A, B, C;
std::vector<std::pair<int, int> > ans;
int ia[MaxN], ib[MaxN];
inline void print() {
  std::puts("Yes");
  for (auto i : ans)
    write(i.first), std::putchar(32), write(i.second), std::puts("");
  exit(0);
}
signed main(void) {
  read(n, m), dsu.reset();
  for (int i = (1); i <= (m); ++i) read(E[i].u, E[i].v);
  read(S, T, ds, dt);
  for (int i = (1); i <= (m); ++i)
    if (E[i].v == S) std::swap(E[i].u, E[i].v);
  for (int i = (1); i <= (m); ++i)
    if (E[i].u == T) std::swap(E[i].u, E[i].v);
  for (int i = (1); i <= (m); ++i) dsu.merge(E[i].u, E[i].v);
  if (!dsu.check()) return std::puts("No"), 0;
  dsu.reset();
  register int ok = 0;
  for (int i = (1); i <= (m); ++i)
    if (E[i].u != S && E[i].v != T)
      if (dsu.merge(E[i].u, E[i].v))
        ans.push_back(std::make_pair(E[i].u, E[i].v));
  for (int i = (1); i <= (m); ++i)
    if (E[i].u != S && E[i].v != T)
      ;
    else if (E[i].u == S && E[i].v == T)
      ok = 1;
    else if (E[i].u == S)
      ia[dsu.getf(E[i].v)] = E[i].v;
    else if (E[i].v == T)
      ib[dsu.getf(E[i].u)] = E[i].u;
  for (int i = 1; i <= n; ++i)
    if (dsu.getf(i) == i) {
      if (ia[i] && ib[i])
        C.push_back(i);
      else if (ia[i])
        A.push_back(i);
      else if (ib[i])
        B.push_back(i);
    }
  if (ds < (int)A.size() || dt < (int)B.size()) return std::puts("No"), 0;
  ds -= (int)A.size(), dt -= (int)B.size();
  for (auto i : A) ans.push_back(std::make_pair(i, S));
  for (auto i : B) ans.push_back(std::make_pair(i, T));
  if (ok && ds >= 1 && dt >= 1 && ds + dt - 2 >= (int)C.size()) {
    ans.push_back(std::make_pair(S, T)), --ds, --dt;
    for (auto i : C)
      if (ds)
        ans.push_back(std::make_pair(ia[i], S)), --ds;
      else if (dt)
        ans.push_back(std::make_pair(ib[i], T)), --dt;
    print();
  }
  if (ds >= 1 && dt >= 1 && (int)C.size() && ds + dt - 2 >= (int)C.size() - 1) {
    ans.push_back(std::make_pair(S, ia[C.back()])),
        ans.push_back(std::make_pair(T, ib[C.back()])), --ds, --dt;
    C.pop_back();
    for (auto i : C)
      if (ds)
        ans.push_back(std::make_pair(ia[i], S)), --ds;
      else if (dt)
        ans.push_back(std::make_pair(ib[i], T)), --dt;
    print();
  }
  std::puts("No");
  return 0;
}
