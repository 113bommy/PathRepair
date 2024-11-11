#include <bits/stdc++.h>
std::string Name = "<stdin>";
std::string iput = Name.substr(0, Name.length() - 4) + ".in";
std::string oput = Name.substr(0, Name.length() - 4) + ".out";
template <class T>
inline bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}
template <class T>
inline bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <class T>
inline T &read(T &x) {
  static int f;
  static char c;
  for (f = 1; !isdigit(c = getchar_unlocked());) {
    if (c == '-') f = -1;
  }
  for (x = 0; isdigit(c); c = getchar_unlocked()) {
    x = x * 10 + c - 48;
  }
  return x *= f;
}
template <class T>
inline void write(T x, const char p = '\n') {
  static int top;
  static int s[30];
  if (x < 0) {
    x = -x;
    putchar_unlocked('-');
  }
  do s[++top] = x % 10 + 48;
  while (x /= 10);
  while (top) putchar_unlocked(s[top--]);
  putchar_unlocked(p);
}
const int maxn = 1e5 + 5;
int n, m, q;
int cnt, fa[maxn * 11];
int num[maxn][11];
inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
struct node {
  int L[11], R[11], l, r, cnt;
  node() { cnt = -1; }
  node operator+(const node &a) const {
    if (cnt == -1) return a;
    if (a.cnt == -1) return *this;
    for (int i = 1; i <= n; ++i) {
      fa[L[i]] = L[i];
      fa[R[i]] = R[i];
      fa[a.L[i]] = a.L[i];
      fa[a.R[i]] = a.R[i];
    }
    node ret;
    ret.l = l;
    ret.r = a.r;
    ret.cnt = cnt + a.cnt;
    for (int i = 1; i <= n; ++i) {
      if (num[i][r] == num[i][a.l]) {
        int p = find(R[i]);
        int q = find(a.L[i]);
        if (p != q) --ret.cnt, fa[q] = p;
      }
    }
    for (int i = 1; i <= n; ++i) {
      ret.L[i] = find(L[i]);
      ret.R[i] = find(a.R[i]);
    }
    return ret;
  }
} s[maxn << 2];
void build(int x, int l, int r) {
  if (l == r) {
    s[x].cnt = 0;
    s[x].l = s[x].r = l;
    for (int i = 1; i <= n; ++i) {
      if (num[i][l] == num[i - 1][l]) {
        s[x].L[i] = s[x].R[i] = s[x].L[i - 1];
      } else {
        s[x].L[i] = s[x].R[i] = ++cnt;
        ++s[x].cnt;
      }
    }
    return;
  }
  int mid = l + r >> 1;
  build((x << 1), l, mid);
  build((x << 1 | 1), mid + 1, r);
  s[x] = s[(x << 1)] + s[(x << 1 | 1)];
}
node query(int x, int l, int r, int p, int q) {
  if (p <= l && r <= q) return s[x];
  int mid = l + r >> 1;
  if (q <= mid) return query((x << 1), l, mid, p, q);
  if (p > mid) return query((x << 1 | 1), mid + 1, r, p, q);
  return query((x << 1), l, mid, p, q) + query((x << 1 | 1), mid + 1, r, p, q);
}
void exec() {
  read(n), read(m), read(q);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) read(num[i][j]);
  build(1, 1, m);
  while (q--) {
    int l, r;
    read(l), read(r);
    write(query(1, 1, m, l, r).cnt);
  }
}
int main() {
  if (fopen(iput.c_str(), "r") != NULL) {
    freopen(iput.c_str(), "r", stdin);
    freopen(oput.c_str(), "w", stdout);
  }
  exec();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
