#include <bits/stdc++.h>
using namespace std;
const int __SIZE = 1 << 18;
char ibuf[__SIZE], *iS, *iT;
template <typename T>
inline void read(T &x) {
  char ch, t = 0;
  x = 0;
  while (!isdigit(ch = (iS == iT
                            ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                               (iS == iT ? EOF : *iS++))
                            : *iS++)))
    t |= ch == '-';
  while (isdigit(ch))
    x = x * 10 + (ch ^ 48),
    ch = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                      (iS == iT ? EOF : *iS++))
                   : *iS++);
  x = t ? -x : x;
}
inline char read_alpha() {
  char c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                        (iS == iT ? EOF : *iS++))
                     : *iS++);
  while (!isalpha(c) && c != EOF)
    c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                     (iS == iT ? EOF : *iS++))
                  : *iS++);
  return c;
}
inline int read_int() {
  int x;
  return read(x), x;
}
inline long long read_ll() {
  long long x;
  return read(x), x;
}
template <typename T>
inline void chkmin(T &a, T b) {
  a = a < b ? a : b;
}
template <typename T>
inline void chkmax(T &a, T b) {
  a = a > b ? a : b;
}
const int MAXN = 100010;
int n, m, k, p;
int h[MAXN];
int d[MAXN];
struct Node {
  long long d;
  int r, id;
  Node() {}
  Node(long long h, int p, int id) : id(id) { d = h / p, r = h % p; }
  inline long long C() { return ::d[id] * d + r; }
  friend bool operator<(Node a, Node b) { return a.d < b.d; }
  friend bool operator>(Node a, Node b) { return a.d > b.d; }
};
priority_queue<Node, vector<Node>, greater<Node> > q;
inline bool chk(long long x) {
  while (!q.empty()) q.pop();
  for (int i = 1; i <= n; i++)
    if (x - 1LL * d[i] * m < h[i]) q.push(Node(x, d[i], i));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= k; j++) {
      if (q.empty()) return 1;
      Node x = q.top();
      q.pop();
      if (x.d < i) return 0;
      if (x.C() + p - 1LL * d[x.id] * m < h[i])
        q.push(Node(x.C() + p, d[x.id], x.id));
    }
  }
  return q.empty();
}
int main() {
  n = read_int(), m = read_int(), k = read_int(), p = read_int();
  long long l = 0, r = 0, res = 0;
  for (int i = 1; i <= n; i++) {
    h[i] = read_int(), d[i] = read_int(), chkmax(l, (long long)d[i]);
    chkmax(r, h[i] + 1LL * m * d[i]);
  }
  res = l;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (chk(mid))
      res = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << res << endl;
  return 0;
}
