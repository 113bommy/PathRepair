#include <bits/stdc++.h>
using namespace std;
namespace Base {
const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
const long long infll = 0x3f3f3f3f3f3f3f3fll, INFll = 0x7fffffffffffffffll;
template <typename T>
void read(T &x) {
  x = 0;
  int fh = 1;
  double num = 1.0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  if (ch == '.') {
    ch = getchar();
    while (isdigit(ch)) {
      num /= 10;
      x = x + num * (ch - '0');
      ch = getchar();
    }
  }
  x = x * fh;
}
template <typename T>
void chmax(T &x, T y) {
  x = x < y ? y : x;
}
template <typename T>
void chmin(T &x, T y) {
  x = x > y ? y : x;
}
}  // namespace Base
using namespace Base;
const int K = 19, N = (1 << K) + 10;
int n, rt, k, place, cnt;
struct Trie {
  int lmax, rmax, l, r, width;
  int ans;
} T[N];
int num[N], a[N], ans[N];
void upd(int pos) {
  if (T[pos].l == 0)
    T[pos].lmax = T[pos].width / 2 + T[T[pos].r].lmax;
  else
    T[pos].lmax = T[T[pos].l].lmax;
  if (T[pos].r == 0)
    T[pos].rmax = T[T[pos].l].rmax;
  else
    T[pos].rmax = T[pos].width / 2 + T[T[pos].r].rmax;
  T[pos].ans = inf;
  if (T[pos].l != 0) chmin(T[pos].ans, T[T[pos].l].ans);
  if (T[pos].r != 0) chmin(T[pos].ans, T[T[pos].r].ans);
  if (T[pos].l != 0 && T[pos].r != 0)
    chmin(T[pos].ans, T[T[pos].r].lmax - T[T[pos].l].rmax + T[pos].width / 2);
}
void insert(int &pos, int dep, int x) {
  if (pos == 0) pos = ++place, T[pos].width = (1 << dep);
  if (dep == 0) {
    T[pos].lmax = T[pos].rmax = 0;
    T[pos].ans = inf;
    return;
  }
  if ((x & (1 << (dep - 1))) == 0)
    insert(T[pos].l, dep - 1, x);
  else
    insert(T[pos].r, dep - 1, x);
  upd(pos);
}
void rebuild(int &pos, int dep, int x) {
  if (pos == 0) return;
  if ((1 << dep) == x * 2) {
    swap(T[pos].l, T[pos].r);
    upd(pos);
    return;
  }
  rebuild(T[pos].l, dep - 1, x);
  rebuild(T[pos].r, dep - 1, x);
  upd(pos);
}
int main() {
  read(n);
  read(k);
  for (int i = 1; i <= n; i++) {
    read(num[i]);
    insert(rt, k, num[i]);
  }
  a[0] = 0;
  cnt = 1;
  for (int i = k - 1; i >= 0; i--) {
    for (int j = 0; j < cnt; j++) a[2 * cnt - j - 1] = a[j] + (1 << i);
    cnt = cnt * 2;
  }
  for (int i = 0; i < cnt; i++) {
    ans[a[i]] = T[rt].ans;
    if (i != cnt - 1) {
      int x = a[i] ^ a[i + 1];
      rebuild(rt, k, x);
    }
  }
  for (int i = 0; i < cnt; i++)
    printf("%d%c", ans[i], (i == cnt - 1) ? '\n' : ' ');
  return 0;
}
