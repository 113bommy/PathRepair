#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &x, T y) {
  return (y < x) ? (x = y, 1) : 0;
}
template <typename T>
inline bool chkmax(T &x, T y) {
  return (y > x) ? (x = y, 1) : 0;
}
inline int read() {
  int x;
  char c;
  int f = 1;
  while ((c = getchar()) != '-' && (c > '9' || c < '0'))
    ;
  if (c == '-') f = -1, c = getchar();
  x = c ^ '0';
  while ((c = getchar()) >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ '0');
  return x * f;
}
inline long long readll() {
  long long x;
  char c;
  int f = 1;
  while ((c = getchar()) != '-' && (c > '9' || c < '0'))
    ;
  if (c == '-') f = -1, c = getchar();
  x = c ^ '0';
  while ((c = getchar()) >= '0' && c <= '9')
    x = (x << 1ll) + (x << 3ll) + (c ^ '0');
  return x * f;
}
const int maxn = 2e5 + 10;
int n, q, mp[500];
struct szsz {
  int c[maxn];
  inline int lowbit(int x) { return x & (-x); }
  int sum(int x) {
    int res = 0;
    while (x) {
      res += c[x];
      x -= lowbit(x);
    }
    return res;
  }
  inline void add(int x, int y) {
    while (x <= n) {
      c[x] += y;
      x += lowbit(x);
    }
  }
  int query(int l, int r) {
    if (l > r) return 0;
    return sum(r) - sum(l - 1);
  }
} bit[3];
set<int> st[3];
char s[maxn], ch[10];
int Fir[3], Lst[3];
inline void work() {
  for (register int i = 0, iend = 2; i <= iend; ++i) {
    if (!st[i].empty())
      Fir[i] = *st[i].begin(), Lst[i] = *st[i].rbegin();
    else
      Fir[i] = -1, Lst[i] = -1;
  }
  int ans = 0;
  for (register int i = 0, iend = 2; i <= iend; ++i)
    if (Fir[i] != -1) {
      int u = (i + 1) % 3, v = (i + 2) % 3;
      if (Fir[u] == -1)
        ans += bit[i].query(1, n);
      else if (Fir[v] != -1) {
        ans += bit[i].query(Fir[v], Lst[v]);
        if (Fir[i] <= Fir[u]) ans += bit[i].query(1, min(Fir[u], Fir[v]));
        if (Lst[i] >= Lst[u]) ans += bit[i].query(max(Lst[u], Lst[v]), Lst[i]);
      }
    }
  printf("%d\n", ans);
}
int main() {
  n = read(), q = read();
  mp['R'] = 0, mp['P'] = 1, mp['S'] = 2;
  scanf("%s", s + 1);
  for (register int i = 1, iend = n; i <= iend; ++i) {
    int u = mp[s[i]];
    st[u].insert(i);
    bit[u].add(i, 1);
  }
  work();
  while (q--) {
    int x = read();
    scanf("%s", ch + 1);
    int u = mp[s[x]];
    st[u].erase(x);
    bit[u].add(x, -1);
    s[x] = ch[1];
    u = mp[s[x]];
    st[u].insert(x);
    bit[u].add(x, 1);
    work();
  }
  return 0;
}
