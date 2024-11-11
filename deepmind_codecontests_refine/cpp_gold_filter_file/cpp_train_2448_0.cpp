#include <bits/stdc++.h>
using namespace std;
inline void R(int &v) {
  v = 0;
  char c = 0;
  int p = 1;
  while (c < '0' || c > '9') {
    if (c == '-') p = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    v = (v << 3) + (v << 1) + c - '0';
    c = getchar();
  }
  v *= p;
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
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
inline int getint() {
  int _b = 0;
  char _c;
  for (_c = getchar(); _c < '0' || _c > '9'; _c = getchar())
    ;
  for (; _c >= '0' && _c <= '9'; _c = getchar()) {
    _b = (_b << 3) + (_b << 1);
    _b += _c - '0';
  }
  return _b;
}
inline int exgetint() {
  int _b = 0;
  char _c;
  int _p = 1;
  for (_c = getchar(); (_c < '0' || _c > '9') && _c != '-'; _c = getchar())
    ;
  if (_c == '-') {
    _c = getchar();
    _p = -1;
  }
  for (; _c >= '0' && _c <= '9'; _c = getchar()) {
    _b = (_b << 3) + (_b << 1);
    _b += _c - '0';
  }
  return _p * _b;
}
inline int Read() {
  int p = 1, x;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') p = -1;
  x = c - '0';
  while ((c = getchar()) > '0' && c <= '9') x = x * 10 + c - '0';
  x *= p;
  return x;
}
inline int READ() {
  char ch;
  bool flag = false;
  int a = 0;
  while (!((((ch = getchar()) >= '0') && (ch <= '9')) || (ch == '-')))
    ;
  if (ch != '-') {
    a *= 10;
    a += ch - '0';
  } else {
    flag = true;
  }
  while (((ch = getchar()) >= '0') && (ch <= '9')) {
    a *= 10;
    a += ch - '0';
  }
  if (flag) {
    a = -a;
  }
  return a;
}
void WRITE(int a) {
  if (a < 0) {
    putchar('-');
    a = -a;
  }
  if (a >= 10) {
    WRITE(a / 10);
  }
  putchar(a % 10 + '0');
}
long long num[2][200010];
char s[200010];
char c[200010];
long long S, T;
long long ans;
void pre() {
  for (long long i = 1; i <= S; i++) {
    num[0][i] = num[0][i - 1];
    num[1][i] = num[1][i - 1];
    if (s[i] - '0' == 0)
      num[0][i]++;
    else
      num[1][i]++;
  }
}
void work() {
  for (long long i = 1; i <= T; i++) {
    long long l = 1, r = S;
    r = min(r, i);
    l = max(l, i + S - T);
    ans += (num[0][r] - num[0][l - 1]) * abs(0 - (c[i] - '0'));
    ans += (num[1][r] - num[1][l - 1]) * abs(1 - (c[i] - '0'));
  }
}
void print() { cout << ans; }
template <typename T>
class Treap {
 public:
  int tot;
  int root;
  int ls[300010], rs[300010], fa[300010], priority[300010], size[300010],
      num[300010];
  T val[300010];
  Treap() {
    tot = 2;
    root = 1;
    val[1] = 1000000000 + 1;
    val[2] = -1000000000 - 1;
    ls[1] = 2;
    fa[2] = 1;
    size[1] = 2;
    size[2] = 1;
    priority[1] = priority[2] = 1000000000 + 1;
    num[1] = num[2] = 1;
  }
  int newnode() {
    ++tot;
    priority[tot] = rand();
    size[tot] = 1;
    num[tot] = 1;
    return tot;
  }
  int begin() { return 2; }
  int end() { return 1; }
  int next(int now) {
    if (rs[now] != 0) {
      int x = rs[now];
      while (ls[x] != 0) x = ls[x];
      return x;
    }
    while (rs[fa[now]] == now) now = fa[now];
    return fa[now];
  }
  int prev(int now) {
    if (ls[now] != 0) {
      int x = ls[now];
      while (rs[x] != 0) x = rs[x];
      return x;
    }
    while (ls[fa[now]] == now) now = fa[now];
    return fa[now];
  }
  void _dfs(int now) {
    if (ls[now] != 0) _dfs(ls[now]);
    cout << val[now] << endl;
    if (rs[now] != 0) _dfs(rs[now]);
  }
  void update(int now) { size[now] = size[ls[now]] + size[rs[now]] + num[now]; }
  void left_rotate(int now) {
    if (now == root) return;
    int f = fa[now], ff = fa[fa[now]], b = ls[now];
    if (f == root) {
      root = now;
      ls[now] = f;
      fa[f] = now;
      rs[f] = b;
      if (b != 0) fa[b] = f;
    } else {
      fa[now] = ff;
      if (ls[ff] == f)
        ls[ff] = now;
      else
        rs[ff] = now;
      ls[now] = f;
      fa[f] = now;
      rs[f] = b;
      if (b != 0) fa[b] = f;
    }
    update(f), update(now);
  }
  void right_rotate(int now) {
    if (now == root) return;
    int f = fa[now], ff = fa[fa[now]], b = rs[now];
    if (f == root) {
      root = now;
      rs[now] = f;
      fa[f] = now;
      ls[f] = b;
      if (b != 0) fa[b] = f;
    } else {
      fa[now] = ff;
      if (ls[ff] == f)
        ls[ff] = now;
      else
        rs[ff] = now;
      rs[now] = f;
      fa[f] = now;
      ls[f] = b;
      if (b != 0) fa[b] = f;
    }
    update(f), update(now);
  }
  void _insert(int now, T x) {
    if (x == val[now]) {
      num[now]++;
      update(now);
      return;
    }
    if (x < val[now]) {
      if (ls[now] != 0)
        _insert(ls[now], x);
      else {
        ls[now] = newnode();
        fa[tot] = now;
        val[tot] = x;
      }
      if (priority[now] > priority[ls[now]]) right_rotate(ls[now]);
    } else {
      if (rs[now] != 0)
        _insert(rs[now], x);
      else {
        rs[now] = newnode();
        fa[tot] = now;
        val[tot] = x;
      }
      if (priority[now] > priority[rs[now]]) left_rotate(rs[now]);
    }
    update(now);
  }
  void down(int now) {
    while (ls[now] != 0 || rs[now] != 0) {
      if (ls[now] == 0)
        left_rotate(rs[now]);
      else if (rs[now] == 0)
        right_rotate(ls[now]);
      else {
        if (priority[ls[now]] < priority[rs[now]])
          right_rotate(ls[now]);
        else
          left_rotate(rs[now]);
      }
    }
    int f = fa[now];
    if (ls[f] == now) ls[f] = 0;
    if (rs[f] == now) rs[f] = 0;
    while (f != root) update(f), f = fa[f];
  }
  void _erase(int now, T x) {
    if (now == 0) return;
    if (val[now] == x) {
      num[now]--;
      if (num[now] == 0)
        down(now);
      else
        update(now);
      return;
    }
    if (x < val[now])
      _erase(ls[now], x);
    else
      _erase(rs[now], x);
    update(now);
  }
  T _findkth(int now, int kth) {
    if (size[ls[now]] >= kth) return _findkth(ls[now], kth);
    int s = kth - size[ls[now]] - num[now];
    if (s <= 0) return val[now];
    return _findkth(rs[now], s);
  }
  int _calc(int now, T x) {
    if (now == 0) return 0;
    if (x < val[now]) return _calc(ls[now], x);
    if (x == val[now]) return size[ls[now]];
    return _calc(rs[now], x) + size[ls[now]] + num[now];
  }
  int _find(int now, T x) {
    if (now == 0) return -1;
    if (x < val[now]) {
      int ret = _find(ls[now], x);
      if (ret == -1) return prev(now);
      return ret;
    }
    if (x == val[now]) return now;
    if (x > val[now]) {
      int ret = _find(rs[now], x);
      if (ret == -1) return now;
      return ret;
    }
  }
  void insert(T x) { _insert(root, x); }
  void erase(T x) { _erase(root, x); }
  T findkth(int x) {
    if (x < 0) return -1;
    if (x > size[root] - 2) return -1;
    return _findkth(root, x + 1);
  }
  int calc(T x) { return _calc(root, x) - 1; }
  T findmin(T x) {
    int s = _find(root, x);
    if (val[s] == x) s = prev(s);
    if (val[s] <= -1000000000) return -1;
    return val[s];
  }
  T findmax(T x) {
    int s = _find(root, x);
    if (val[s] <= x) s = next(s);
    if (val[s] >= 1000000000) return -1;
    return val[s];
  }
  int find(T x) { return _find(root, x); }
  void sort() { _dfs(root); }
};
int main() {
  scanf("%s%s", s + 1, c + 1);
  S = strlen(s + 1), T = strlen(c + 1);
  pre();
  work();
  print();
}
