#include <bits/stdc++.h>
using namespace std;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
int gcd(int x, int y) {
  while (y) {
    int t = x % y;
    x = y;
    y = t;
  }
  return x;
}
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
namespace FastIO {
bool IOError = 0;
inline char NextChar() {
  static char buf[100000], *p1 = buf + 100000, *pend = buf + 100000;
  if (p1 == pend) {
    p1 = buf;
    pend = buf + fread(buf, 1, 100000, stdin);
    if (pend == p1) {
      IOError = 1;
      return -1;
    }
  }
  return *p1++;
}
inline bool Blank(char c) {
  return c == ' ' || c == '\n' || c == '\r' || c == '\t';
}
inline void read(int &x) {
  bool sign = 0;
  char ch = NextChar();
  x = 0;
  for (; Blank(ch); ch = NextChar())
    ;
  if (IOError) return;
  if (ch == '-') sign = 1, ch = NextChar();
  for (; ch >= '0' && ch <= '9'; ch = NextChar()) x = x * 10 + ch - '0';
  if (sign) x = -x;
}
inline void read(long long &x) {
  bool sign = 0;
  char ch = NextChar();
  x = 0;
  for (; Blank(ch); ch = NextChar())
    ;
  if (IOError) return;
  if (ch == '-') sign = 1, ch = NextChar();
  for (; ch >= '0' && ch <= '9'; ch = NextChar()) x = x * 10 + ch - '0';
  if (sign) x = -x;
}
inline void read(double &x) {
  bool sign = 0;
  char ch = NextChar();
  x = 0;
  for (; Blank(ch); ch = NextChar())
    ;
  if (IOError) return;
  if (ch == '-') sign = 1, ch = NextChar();
  for (; ch >= '0' && ch <= '9'; ch = NextChar()) x = x * 10 + ch - '0';
  if (ch == '.') {
    double tmp = 1;
    ch = NextChar();
    for (; ch >= '0' && ch <= '9'; ch = NextChar())
      tmp /= 10.0, x += tmp * (ch - '0');
  }
  if (sign) x = -x;
}
inline void read(char *s) {
  char ch = NextChar();
  for (; Blank(ch); ch = NextChar())
    ;
  if (IOError) return;
  for (; !Blank(ch) && !IOError; ch = NextChar()) *s++ = ch;
  *s = 0;
}
inline void read(char &c) {
  for (c = NextChar(); Blank(c); c = NextChar())
    ;
  if (IOError) {
    c = -1;
    return;
  }
}
}  // namespace FastIO
using namespace FastIO;
int q[601000], l[601000], r[601000], in[601000];
vector<int> g[601000], f[601000];
set<pair<int, int> > al;
int vis[601000], ans[601000];
int main() {
  int n, m, k;
  read(n), read(m), read(k);
  for (int i = 1; i <= n; i++) {
    int x;
    read(x);
    if (x)
      l[i] = r[i] = ans[i] = x;
    else
      l[i] = 1, r[i] = k;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    read(u), read(v);
    g[u].push_back(v);
    in[v]++;
  }
  int head = 0, tail = 1;
  for (int i = 1; i <= n; i++)
    if (!in[i]) q[tail++] = i;
  while (head < tail) {
    int u = q[++head];
    for (int v : g[u]) {
      in[v]--;
      if (!in[v]) q[tail++] = v;
    }
  }
  if (tail != n + 1) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    int u = q[i];
    for (int v : g[u]) chkmin(r[v], r[u] - 1);
  }
  for (int i = n; i; i--) {
    int u = q[i];
    for (int v : g[u]) chkmax(l[u], l[v] + 1);
  }
  for (int i = 1; i <= n; i++) {
    f[l[i]].push_back(i);
    if (l[i] > r[i]) {
      puts("-1");
      return 0;
    }
  }
  for (int i = 1; i <= k; i++) {
    for (int j : f[i]) al.insert(pair<int, int>(r[j], j));
    if (al.empty()) {
      puts("-1");
      return 0;
    }
    set<pair<int, int> >::iterator it = al.begin();
    ans[(*it).second] = i;
    al.erase(it);
    while (!al.empty()) {
      set<pair<int, int> >::iterator it = al.begin();
      if ((*it).first > i) break;
      al.erase(it);
    }
  }
  for (int i = n; i; i--) {
    int u = q[i];
    int k = ans[u];
    for (int v : g[u]) {
      if (k && ans[v] >= ans[u]) {
        puts("-1");
        return 0;
      }
      if (!k) chkmax(ans[u], ans[v] + 1);
    }
    if (!ans[u]) ans[u] = 1;
  }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
