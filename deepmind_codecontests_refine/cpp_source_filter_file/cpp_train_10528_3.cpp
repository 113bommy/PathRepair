#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
struct fastio {
  char s[100000];
  int it, len;
  fastio() { it = len = 0; }
  inline char get() {
    if (it < len) return s[it++];
    it = 0;
    len = fread(s, 1, 100000, stdin);
    if (len == 0)
      return EOF;
    else
      return s[it++];
  }
  bool notend() {
    char c = get();
    while (c == ' ' || c == '\n') c = get();
    if (it > 0) it--;
    return c != EOF;
  }
} _buff;
inline long long getnum() {
  long long r = 0;
  bool ng = 0;
  char c;
  c = _buff.get();
  while (c != '-' && (c < '0' || c > '9')) c = _buff.get();
  if (c == '-') ng = 1, c = _buff.get();
  while (c >= '0' && c <= '9') r = r * 10 + c - '0', c = _buff.get();
  return ng ? -r : r;
}
template <class T>
inline void putnum(T x) {
  if (x < 0) putchar('-'), x = -x;
  register short a[20] = {}, sz = 0;
  while (x) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
inline char getreal() {
  char c = _buff.get();
  while (c <= 32) c = _buff.get();
  return c;
}
long long qpow(long long x, long long k) {
  return k == 0 ? 1
                : 1ll * qpow(1ll * x * x % mod, k >> 1) * (k & 1 ? x : 1) % mod;
}
const int maxn = 500111;
int n, m, k;
vector<int> con[maxn];
int fa[maxn], lv[maxn];
vector<int> lf;
bool vis[maxn];
void getpath(vector<int> &v, int x, int y) {
  while (true) {
    v.push_back(x);
    if (x == y) return;
    x = fa[x];
  }
}
void dfs(int x) {
  vis[x] = 1;
  bool is_leaf = 1;
  for (auto u : con[x]) {
    if (vis[u]) continue;
    lv[u] = lv[x] + 1;
    fa[u] = x;
    dfs(u);
    is_leaf = 0;
  }
  if (is_leaf) lf.push_back(x);
}
int main() {
  n = getnum(), m = getnum(), k = getnum();
  for (int i = 1; i <= m; i++) {
    int x, y;
    x = getnum(), y = getnum();
    con[x].push_back(y);
    con[y].push_back(x);
  }
  lv[1] = 1;
  dfs(1);
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    if (1ll * lv[i] * k >= n) {
      puts("PATH");
      putnum(lv[i]), putchar(' ');
      getpath(v, i, 1);
      for (auto x : v) putnum(x), putchar(' ');
      return 0;
    }
  }
  puts("CYCLE");
  for (auto x : lf) {
    int y = -1, z = -1;
    for (auto u : con[x]) {
      if (u != fa[x]) {
        if (y == -1)
          y = u;
        else
          z = u;
      }
    }
    if (lv[y] < lv[z]) swap(y, z);
    v.clear();
    if ((lv[x] - lv[y] + 1) % 3 != 0) {
      getpath(v, x, y);
    } else if ((lv[x] - lv[z] + 1) % 3 != 0) {
      getpath(v, x, z);
    } else {
      assert((lv[y] - lv[z] + 2) % 3 != 0);
      v.push_back(x);
      getpath(v, y, z);
    }
    putnum(v.size()), putchar(' ');
    for (auto t : v) putnum(t), putchar(' ');
    puts("");
    k--;
    if (k == 0) break;
  }
  return 0;
}
