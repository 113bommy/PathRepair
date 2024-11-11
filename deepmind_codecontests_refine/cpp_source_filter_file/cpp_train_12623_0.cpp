#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  return x * f;
}
inline void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(long long x) {
  write(x);
  putchar('\n');
}
inline void wri(long long x) {
  write(x);
  putchar(' ');
}
const int mod = 998244353;
const int maxn = 5e3 + 233;
map<pair<int, int>, int> M[maxn << 2];
vector<int> a[maxn << 2];
int ans[maxn * 20];
vector<pair<int, int> > c;
int n, q, b[maxn];
void build(int o, int l, int r) {
  for (register int i = (l); i <= int(r); ++i) a[o].push_back(b[i]);
  sort(a[o].begin(), a[o].end());
  if (l == r) return;
  build((o << 1), l, ((l + r) >> 1)),
      build((o << 1 | 1), ((l + r) >> 1) + 1, r);
}
int solve(int o, int L, int R) {
  int l = lower_bound(a[o].begin(), a[o].end(), L) - a[o].begin();
  int r = upper_bound(a[o].begin(), a[o].end(), R) - a[o].begin() - 1;
  if (l > r) return -1;
  if (l == r) return a[o][l];
  if (M[o][{l, r}]) return M[o][{l, r}];
  int x = solve((o << 1), L, R), y = solve((o << 1 | 1), L, R), res = max(x, y);
  if (x != -1 && y != -1) c.push_back({x, y}), res = c.size() + n;
  return M[o][{l, r}] = res;
}
int main() {
  n = read(), q = read();
  for (register int i = (1); i <= int(n); ++i) b[read()] = i;
  build(1, 1, n);
  for (register int i = (1); i <= int(q); ++i) {
    int l = read(), r = read();
    ans[i] = solve(1, l, r);
  }
  writeln(c.size());
  for (auto v : c) wri(v.first), writeln(v.second);
  for (register int i = (1); i <= int(q); ++i) wri(ans[i]);
  puts("");
  return 0;
}
