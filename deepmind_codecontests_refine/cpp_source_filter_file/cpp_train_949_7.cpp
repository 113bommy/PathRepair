#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') positive = 0;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
inline void write(long long a) {
  if (a < 0) {
    a = -a;
    putchar('-');
  }
  if (a >= 10) write(a / 10);
  putchar('0' + a % 10);
}
inline void writeln(long long a) {
  write(a);
  puts("");
}
inline void wri(long long a) {
  write(a);
  putchar(' ');
}
inline long long rnd() {
  long long ans = 0;
  for (int i = 1; i <= 5; i++) ans = ans << 15 ^ rand();
  return ans;
}
const int N = 200005, M = 520000;
struct link_cut_tree {
  int ch[N][2], fa[N], rev[N];
  long long lazy[N], w[N];
  inline int get(int x) { return ch[fa[x]][1] == x; }
  inline int isroot(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }
  inline void rever(int x) {
    rev[x] ^= 1;
    swap(ch[x][0], ch[x][1]);
  }
  inline void update(int x) {}
  inline void cao(int x, long long y) {
    w[x] ^= y;
    lazy[x] ^= y;
  }
  inline void pushdown(int x) {
    if (rev[x]) {
      if (ch[x][0]) rever(ch[x][0]);
      if (ch[x][1]) rever(ch[x][1]);
      rev[x] = 0;
    }
    if (lazy[x]) {
      if (ch[x][0]) cao(ch[x][0], lazy[x]);
      if (ch[x][1]) cao(ch[x][1], lazy[x]);
      lazy[x] = 0;
    }
  }
  inline void push(int x) {
    if (!isroot(x)) push(fa[x]);
    pushdown(x);
  }
  inline void rotate(int x) {
    int f = fa[x], g = fa[f], c = get(x);
    if (!isroot(f)) ch[g][get(f)] = x;
    fa[x] = g;
    ch[f][c] = ch[x][c ^ 1];
    fa[ch[f][c]] = f;
    ch[x][c ^ 1] = f;
    fa[f] = x;
    update(f);
    update(x);
  }
  inline void splay(int x) {
    for (push(x); !isroot(x); rotate(x))
      if (!isroot(fa[x])) rotate(get(fa[x]) == get(x) ? fa[x] : x);
  }
  void access(int x) {
    for (int y = 0; x; y = x, x = fa[x]) {
      splay(x);
      ch[x][1] = y;
      update(x);
    }
  }
  void makeroot(int x) {
    access(x);
    splay(x);
    rever(x);
  }
  int findroot(int x) {
    access(x);
    splay(x);
    while (ch[x][0]) x = ch[x][0];
    return x;
  }
  void link(int x, int y) {
    x++;
    y++;
    makeroot(x);
    fa[x] = y;
  }
  void split(int x, int y) {
    makeroot(x);
    access(y);
    splay(y);
  }
  void cut(int x, int y) {
    x++;
    y++;
    split(x, y);
    fa[x] = ch[y][0] = 0;
    update(y);
  }
  bool check(int x, int y) {
    x++;
    y++;
    int tx = findroot(x), ty = findroot(y);
    return tx == ty;
  }
} T;
pair<int, int> tr[M];
int lazy[M], v[N], pos[N];
vector<int> e[N];
pair<int, int> q[10];
pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first)
    return make_pair(a.first, a.second + b.second);
  else
    return max(a, b);
}
void push_up(int nod) { tr[nod] = tr[nod << 1] + tr[nod << 1 | 1]; }
inline void cao(int nod, int x) {
  lazy[nod] += x;
  tr[nod].first += x;
}
void pushdown(int nod) {
  if (lazy[nod]) {
    cao(nod << 1, lazy[nod]);
    cao(nod << 1 | 1, lazy[nod]);
    lazy[nod] = 0;
  }
}
pair<int, int> ask(int l, int r, int i, int j, int nod) {
  if (l == i && r == j) return tr[nod];
  pushdown(nod);
  int mid = (l + r) >> 1;
  if (j <= mid)
    return ask(l, mid, i, j, nod << 1);
  else if (i > mid)
    return ask(mid + 1, r, i, j, nod << 1 | 1);
  else
    return ask(l, mid, i, mid, nod << 1) +
           ask(mid + 1, r, mid + 1, j, nod << 1 | 1);
}
void ins(int l, int r, int i, int j, int nod) {
  if (l == i && r == j) {
    cao(nod, 1);
    return;
  }
  pushdown(nod);
  int mid = (l + r) >> 1;
  if (j <= mid)
    ins(l, mid, i, j, nod << 1);
  else if (i > mid)
    ins(mid + 1, r, i, j, nod << 1 | 1);
  else {
    ins(l, mid, i, mid, nod << 1);
    ins(mid + 1, r, mid + 1, j, nod << 1 | 1);
  }
  push_up(nod);
}
void build(int l, int r, int nod) {
  if (l == r) {
    tr[nod] = make_pair(v[l], 1);
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, nod << 1);
  build(mid + 1, r, nod << 1 | 1);
  tr[nod] = tr[nod << 1] + tr[nod << 1 | 1];
}
int main() {
  int n = read(), m = read(), nm = n * m - 1;
  for (int i = 0; i <= nm; i++) v[i] = i;
  build(0, nm, 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) pos[v[((i)*m + j)] = read() - 1] = ((i)*m + j);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i) e[v[((i)*m + j)]].push_back(v[((i - 1) * m + j)]);
      if (j) e[v[((i)*m + j)]].push_back(v[((i)*m + j - 1)]);
      if (i + 1 < n) e[v[((i)*m + j)]].push_back(v[((i + 1) * m + j)]);
      if (j + 1 < m) e[v[((i)*m + j)]].push_back(v[((i)*m + j + 1)]);
    }
  }
  long long ans = 0;
  int l = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int r = ((i)*m + j);
      while (1) {
        int f = 1, tot = 0;
        for (auto k : e[r])
          if (k < r && k >= l) q[++tot] = make_pair(k, r);
        for (int i = 1; i <= tot; i++) {
          if (T.check(q[i].first, q[i].second)) {
            for (int j = 1; j < i; j++) T.cut(q[j].first, q[j].second);
            f = 0;
            break;
          } else
            T.link(q[i].first, q[i].second);
        }
        if (f)
          break;
        else {
          for (auto k : e[l])
            if (k > l && k <= r) T.cut(k, l);
          l++;
        }
      }
      for (auto k : e[r])
        if (k < r && k >= l) {
          ins(0, nm, 0, k, 1);
        }
      pair<int, int> t = ask(0, nm, l, r, 1);
      ans += t.second;
    }
  }
  cout << ans << endl;
}
