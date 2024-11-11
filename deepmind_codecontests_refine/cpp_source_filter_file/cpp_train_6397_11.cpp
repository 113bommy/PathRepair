#include <bits/stdc++.h>
using namespace std;
namespace Elaina {
template <class T>
inline T Max(const T x, const T y) {
  return x < y ? y : x;
}
template <class T>
inline T Min(const T x, const T y) {
  return x < y ? x : y;
}
template <class T>
inline T fab(const T x) {
  return x < 0 ? -x : x;
}
template <class T>
inline void getMax(T& x, const T y) {
  x = Max(x, y);
}
template <class T>
inline void getMin(T& x, const T y) {
  x = Min(x, y);
}
template <class T>
T gcd(const T x, const T y) {
  return y ? gcd(y, x % y) : x;
}
template <class T>
inline T readin(T x) {
  x = 0;
  int f = 0;
  char c;
  while ((c = getchar()) < '0' || '9' < c)
    if (c == '-') f = 1;
  for (x = (c ^ 48); '0' <= (c = getchar()) && c <= '9';
       x = (x << 1) + (x << 3) + (c ^ 48))
    ;
  return f ? -x : x;
}
template <class T>
void fwrit(const T x) {
  if (x < 0) return putchar('-'), fwrit(-x);
  if (x > 9) fwrit(x / 10);
  putchar(x % 10 ^ 48);
}
}  // namespace Elaina
using namespace Elaina;
const int maxn = 3e5;
const int mod = 1e9 + 7;
int trie[maxn * 2 + 5][26];
int fa[maxn * 2 + 5], len[maxn * 2 + 5];
int cnt = 1, lst;
int sz[maxn * 2 + 5][3];
inline void add(const int c, const int col) {
  int p = lst, u, q, nq;
  if (trie[p][c]) {
    q = trie[p][c];
    if (len[q] == len[p] + 1)
      lst = q;
    else {
      int nq = lst = ++cnt;
      for (int i = 0, i_end_ = 25; i <= i_end_; ++i) trie[nq][i] = trie[q][i];
      fa[nq] = fa[q], len[nq] = len[p] + 1;
      fa[q] = nq;
      for (; p && trie[p][c] == q; p = fa[p]) trie[p][c] = nq;
    }
    ++sz[lst][col];
    return;
  }
  u = lst = ++cnt;
  len[u] = len[p] + 1, ++sz[u][col];
  for (; p && !trie[p][c]; p = fa[p]) trie[p][c] = u;
  if (!p)
    fa[u] = 1;
  else {
    q = trie[p][c];
    if (len[q] == len[p] + 1)
      fa[u] = q;
    else {
      nq = ++cnt;
      for (int i = 0, i_end_ = 25; i <= i_end_; ++i) trie[nq][i] = trie[q][i];
      fa[nq] = fa[q], len[nq] = len[p] + 1;
      fa[q] = fa[u] = nq;
      for (; p && trie[p][c] == q; p = fa[p]) trie[p][c] = nq;
    }
  }
}
char s[maxn + 5];
int n, ans[maxn + 5];
int a[maxn + 5], c[maxn + 5];
signed main() {
  n = maxn + 5;
  for (int t = 0, t_end_ = 2; t <= t_end_; ++t) {
    scanf("%s", s + 1);
    lst = 1;
    int l = strlen(s + 1);
    n = Min(n, l);
    for (int i = 1, i_end_ = l; i <= i_end_; ++i) add(s[i] - 'a', t);
  }
  for (int i = 1, i_end_ = cnt; i <= i_end_; ++i) ++c[len[i]];
  for (int i = 1, i_end_ = maxn; i <= i_end_; ++i) c[i] += c[i - 1];
  for (int i = cnt, i_end_ = 1; i >= i_end_; --i) a[c[len[i]]--] = i;
  for (int i = cnt, i_end_ = 2; i >= i_end_; --i)
    for (int j = 0, j_end_ = 2; j <= j_end_; ++j)
      sz[fa[a[i]]][j] += sz[a[i]][j];
  for (int i = 2, i_end_ = cnt; i <= i_end_; ++i) {
    (ans[len[fa[i]] + 1] += 1ll * sz[i][0] * sz[i][1] % mod * sz[i][2] % mod) %=
        mod;
    (ans[len[i] + 1] +=
     mod - 1ll * sz[i][0] * sz[i][1] % mod * sz[i][2] % mod) %= mod;
  }
  for (int i = 1, i_end_ = n; i <= i_end_; ++i)
    ans[i] = (ans[i] + ans[i - 1]) % mod;
  for (int i = 1, i_end_ = n; i <= i_end_; ++i) fwrit(ans[i]), putchar(' ');
  return 0;
}
