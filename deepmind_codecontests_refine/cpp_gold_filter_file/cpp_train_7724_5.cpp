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
struct Node {
  int v, id;
  Node() {}
  Node(int v, int id) : v(v), id(id) {}
  friend bool operator<(Node a, Node b) { return a.v > b.v; }
} a[1010];
bitset<1010> res[1010];
int main() {
  int n = read_int(), ct = n;
  for (int i = 0; i < n; i++) a[i] = Node(read_int(), i);
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    int p = i, t = a[i].id;
    while (a[i].v--) res[p].set(t), ++p, p = p > n ? 0 : p;
    if (ct == n && p < i) ct++;
  }
  printf("%d\n", ct);
  for (int i = 0; i < ct; i++) {
    for (int j = 0; j < n; j++) putchar(48 | res[i][j]);
    puts("");
  }
  return 0;
}
