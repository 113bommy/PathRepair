#include <bits/stdc++.h>
using namespace std;
inline char gc() { return getchar(); }
template <class T>
int read(T &ans) {
  ans = 0;
  char ch = gc();
  T f = 1;
  while (!isdigit(ch)) {
    if (ch == EOF) return -1;
    if (ch == '-') f = -1;
    ch = gc();
  }
  while (isdigit(ch)) ans = ans * 10 + ch - '0', ch = gc();
  ans *= f;
  return 1;
}
template <class T1, class T2>
int read(T1 &a, T2 &b) {
  return read(a) != EOF && read(b) != EOF ? 2 : EOF;
}
template <class T1, class T2, class T3>
int read(T1 &a, T2 &b, T3 &c) {
  return read(a, b) != EOF && read(c) != EOF ? 3 : EOF;
}
const int Maxn = 1100;
const int inf = 0x3f3f3f3f;
int a[Maxn], b[Maxn], r[Maxn], c[Maxn];
int n, x, tot;
pair<pair<int, int>, pair<int, int> > ans[Maxn];
void work(int x) {
  if (x == n) return;
  if (a[x] == r[x] && b[x] == c[x])
    work(x + 1);
  else {
    int y, z;
    for (int i = x; i <= n; i++)
      if (a[i] == r[x]) {
        y = i;
        break;
      }
    for (int i = x; i <= n; i++)
      if (a[i] == c[x]) {
        z = i;
        break;
      }
    swap(a[y], a[x]);
    swap(b[z], b[x]);
    ans[++tot] = make_pair(make_pair(y, x), make_pair(x, z));
    work(x + 1);
  }
}
signed main() {
  read(n);
  for (int i = 1; i <= n; i++) read(x), r[x] = i;
  for (int i = 1; i <= n; i++) read(x), c[x] = i;
  for (int i = 1; i <= n; i++) a[i] = b[i] = i;
  work(1);
  printf("%d\n", tot);
  for (int i = 1; i <= tot; i++) {
    printf("%d %d %d %d\n", ans[i].first.first, ans[i].first.second,
           ans[i].second.first, ans[i].second.second);
  }
  return 0;
}
