#include <bits/stdc++.h>
using namespace std;
void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readc(char &x) {
  char c;
  while ((c = getchar()) == ' ')
    ;
  x = c;
}
void writes(string s) { puts(s.c_str()); }
void writeln() { writes(""); }
void writei(int x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
void writell(long long x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
inline long long inc(int &x) { return ++x; }
inline long long inc(long long &x) { return ++x; }
inline long long inc(int &x, long long y) { return x += y; }
inline long long inc(long long &x, long long y) { return x += y; }
inline double inc(double &x, double y) { return x += y; }
inline long long dec(int &x) { return --x; }
inline long long dec(long long &x) { return --x; }
inline long long dec(int &x, long long y) { return x -= y; }
inline long long dec(long long &x, long long y) { return x -= y; }
inline double dec(double &x, double y) { return x -= y; }
inline long long mul(int &x) { return x = ((long long)x) * x; }
inline long long mul(long long &x) { return x = x * x; }
inline long long mul(int &x, long long y) { return x *= y; }
inline long long mul(long long &x, long long y) { return x *= y; }
inline double mul(double &x, double y) { return x *= y; }
inline long long divi(const int &x) {
  long long ans, l, r, mid;
  ans = 0;
  l = 0;
  r = 0x3fffffff;
  while (l < r) {
    mid = (l + r) / 2;
    if (mid * mid <= x) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid;
  }
  return ans;
}
inline long long divi(const long long &x) {
  long long ans, l, r, mid;
  ans = 0;
  l = 0;
  r = 0x3fffffff;
  while (l < r) {
    mid = (l + r) / 2;
    if (mid * mid <= x) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid;
  }
  return ans;
}
inline long long divi(int &x, long long y) { return x /= y; }
inline long long divi(long long &x, long long y) { return x /= y; }
inline double divi(double &x, double y) { return x /= y; }
inline long long mod(int &x, long long y) { return x %= y; }
inline long long mod(long long &x, long long y) { return x %= y; }
int n, m, i, j, a[200005], ans, fa[200005][19], dep[200005], x, y, op;
vector<int> e[200005];
void dfs(int x, int p) {
  fa[x][0] = p;
  for (__typeof((e[x]).begin()) it = (e[x]).begin(); it != (e[x]).end(); it++) {
    if (*it == p) continue;
    dep[*it] = dep[x] + 1;
    dfs(*it, x);
  }
}
int lca(int x, int y) {
  if (dep[x] > dep[y]) swap(x, y);
  int i, t = dep[y] - dep[x];
  if ((0) <= (18))
    for ((i) = (0); (i) <= (18); (i)++)
      if ((t >> i) & 1) y = fa[y][i];
  if (x == y) return x;
  if ((18) >= (0))
    for ((i) = (18); (i) >= (0); (i)--)
      if (fa[x][i] != fa[y][i]) {
        x = fa[x][i];
        y = fa[y][i];
      }
  return fa[x][0];
}
int dis(int x, int y) { return dep[x] + dep[y] - dep[lca(x, y)] * 2; }
struct nd {
  int l, r;
  pair<int, int> f;
} tr[800005];
pair<int, int> merge(int x, int y, int z) {
  if (!x || !y || !z) return make_pair(0, 0);
  int d1 = dis(x, y), d2 = dis(x, z), d3 = dis(y, z);
  if (d1 + d2 == d3) return make_pair(y, z);
  if (d1 + d3 == d2) return make_pair(x, z);
  if (d3 + d2 == d1) return make_pair(x, y);
  return make_pair(0, 0);
}
pair<int, int> merge(pair<int, int> x, pair<int, int> y) {
  if (x == make_pair(-1, -1)) return y;
  pair<int, int> ans;
  ans = merge(x.first, x.second, y.first);
  ans = merge(ans.first, ans.second, y.second);
}
void pushup(int x) { tr[x].f = merge(tr[x * 2].f, tr[x * 2 + 1].f); }
void build(int x, int l, int r) {
  tr[x].l = l;
  tr[x].r = r;
  tr[x].f = make_pair(0, 0);
  if (l == r) return;
  build(x * 2, l, (l + r) / 2);
  build(x * 2 + 1, (l + r) / 2 + 1, r);
}
void update(int x, int y, int c) {
  if (tr[x].l > y || tr[x].r < y) return;
  if (tr[x].l == tr[x].r) {
    tr[x].f = make_pair(c, c);
    return;
  }
  update(x * 2, y, c);
  update(x * 2 + 1, y, c);
  pushup(x);
}
int query(int x, pair<int, int> f) {
  if (tr[x].l == tr[x].r) return tr[x].l;
  pair<int, int> t = merge(f, tr[x * 2].f);
  if (t != make_pair(0, 0)) {
    return query(x * 2 + 1, t);
  } else {
    return query(x * 2, f);
  }
}
int main() {
  read(n);
  if ((1) <= ((n)))
    for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
      read(a[i]);
      a[i]++;
    }
  if ((1) <= ((n - 1)))
    for (((i)) = (1); ((i)) <= ((n - 1)); ((i))++) {
      read(x);
      e[x].push_back(i + 1);
      e[i + 1].push_back(x);
    }
  dfs(1, 0);
  if ((1) <= ((17)))
    for (((j)) = (1); ((j)) <= ((17)); ((j))++)
      if ((1) <= ((n)))
        for (((i)) = (1); ((i)) <= ((n)); ((i))++)
          fa[i][j] = fa[fa[i][j - 1]][j - 1];
  build(1, 1, n + 1);
  if ((1) <= ((n)))
    for (((i)) = (1); ((i)) <= ((n)); ((i))++) update(1, a[i], i);
  read(m);
  if ((1) <= ((m)))
    for (((i)) = (1); ((i)) <= ((m)); ((i))++) {
      read(op);
      if (op == 2)
        printf("%d\n", query(1, make_pair(-1, -1)) - 1);
      else {
        read(x);
        read(y);
        swap(a[x], a[y]);
        update(1, a[x], x);
        update(1, a[y], y);
      }
    }
  return 0;
}
