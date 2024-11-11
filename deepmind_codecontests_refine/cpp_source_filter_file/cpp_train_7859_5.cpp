#include <bits/stdc++.h>
template <typename T>
inline T abs(T a) {
  return a < 0 ? -a : a;
}
template <typename T>
inline T min(T a, T b) {
  return a < b ? a : b;
}
template <typename T>
inline T max(T a, T b) {
  return a > b ? a : b;
}
template <typename T>
inline void swap(T& a, T& b) {
  T t = a;
  a = b, b = t;
}
template <typename T>
inline bool umin(T& mn, T u) {
  return u < mn ? mn = u, true : false;
}
template <typename T>
inline bool umax(T& mx, T u) {
  return u > mx ? mx = u, true : false;
}
template <typename T>
inline void read(T& r) {
  char c;
  r = 0;
  bool flag = false;
  do c = getchar();
  while (c != '-' && (c < '0' || c > '9'));
  if (c == '-') flag = true, c = getchar();
  do r = r * 10 + c - '0', c = getchar();
  while (c >= '0' && c <= '9');
  if (flag) r *= -1;
}
template <typename T1, typename T2>
inline void read(T1& r, T2& s) {
  read(r), read(s);
}
template <typename T1, typename T2, typename T3>
inline void read(T1& r, T2& s, T3& t) {
  read(r), read(s), read(t);
}
template <typename T1, typename T2, typename T3, typename T4>
inline void read(T1& r, T2& s, T3& t, T4& u) {
  read(r), read(s), read(t), read(u);
}
template <typename T>
inline void write(T w, const char* c = "") {
  if (w == 0)
    putchar('0');
  else {
    if (w < 0) putchar('-'), w *= -1;
    static int s[21], top;
    top = 0;
    while (w) s[top++] = w % 10, w /= 10;
    while (top--) putchar(s[top] + '0');
  }
  for (int i = 0; c[i]; i++) putchar(c[i]);
}
int n, k, qn, en;
long long p[1000];
const long long P = 1e7 + 19, mod = 1e9 + 7;
void init() {
  for (int i = p[0] = 1; i < k; i++) p[i] = p[i - 1] * P % mod;
}
struct knapsack {
  int dp[1001];
  void add(std::pair<int, int> o) {
    int v = o.first, w = o.second;
    for (int i = k - w; i >= 0; i--) umax(dp[i + w], dp[i] + v);
  }
  int getans() {
    long long ans = 0;
    for (int i = 1; i <= k; i++) (ans += dp[i] * p[i - 1]) %= mod;
    return (int)ans;
  }
} st[16];
struct perfect_binary_tree {
  struct ac {
    std::pair<int, int> to;
    int nx;
  } e[4500000];
  int L, first[65536];
  perfect_binary_tree() : L(1) {}
  inline void addedge(int u, std::pair<int, int> v) {
    e[L].to = v, e[L].nx = first[u], first[u] = L++;
  }
  void add(int L, int R, std::pair<int, int> c, int now = 1, int l = 1,
           int r = qn) {
    if (L <= l && r <= R) {
      addedge(now, c);
      return;
    }
    int m = (l + r) >> 1;
    if (L <= m) add(L, R, c, now << 1, l, m);
    if (m < R) add(L, R, c, now << 1 | 1, m + 1, r);
  }
  void getans(int depth = 1, int now = 1, int l = 1, int r = qn) {
    st[depth] = st[depth - 1];
    for (int j = first[now]; j; j = e[j].nx) st[depth].add(e[j].to);
    if (l == r) {
      write(st[depth].getans(), "\n");
      return;
    }
    int m = (l + r) >> 1;
    getans(depth + 1, now << 1, l, m);
    getans(depth + 1, now << 1 | 1, m + 1, r);
  }
} T;
std::pair<int, int> exhibit[15000], show[15000];
void solve() {
  init();
  for (int i = 0; i < n; i++)
    if (show[i].first <= qn && show[i].second >= 1)
      T.add(show[i].first, show[i].second, exhibit[i]);
  T.getans();
}
void input() {
  qn = 0, n = 0;
  int m, o;
  read(m, k);
  while (m--)
    read(exhibit[n].first, exhibit[n].second),
        show[n++] = std::pair<int, int>(0, -1);
  read(m);
  while (m--) {
    read(o);
    switch (o) {
      case 1:
        read(exhibit[n].first, exhibit[n].second),
            show[n++] = std::pair<int, int>(qn + 1, -1);
        break;
      case 2:
        read(o), show[--o].second = qn;
        break;
      case 3:
        ++qn;
        break;
    }
  }
  for (int i = 0; i < n; i++)
    if (show[i].second == -1) show[i].second = qn;
}
int main() {
  input();
  solve();
  return 0;
}
