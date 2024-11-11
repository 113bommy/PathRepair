#include <bits/stdc++.h>
using namespace std;
inline char nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  if (p1 == p2) {
    p2 = (p1 = buf) + fread(buf, 1, 100000, stdin);
    if (p1 == p2) return EOF;
  }
  return *p1++;
}
inline int getint() {
  int x;
  char c = nc(), b = 1;
  if (c == -1) return 0;
  for (; !(c >= '0' && c <= '9'); c = nc())
    if (c == '-') b = -1;
  for (x = 0; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = nc())
    ;
  x *= b;
  return x;
}
inline void putint(int x) {
  static int a[11], i;
  i = 0;
  if (x < 0) putchar('-'), x = -x;
  do {
    a[i++] = x % 10 ^ 48;
    x /= 10;
  } while (x);
  while (i) putchar(a[--i]);
}
template <class T>
bool chkmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
bool chkmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
const int inf = 1e9;
const long long linf = 1e18;
const int mod = 1e9 + 7;
const double eps = 1e-7;
int n, timp;
vector<int> v[1000005];
int dt[1000005], ft[1000005], ver[1000005], sz[1000005], hs[1000005],
    dep[1000005], ans[1000005];
void dfs(int first, int par = 0) {
  dt[first] = ++timp;
  ver[timp] = first;
  hs[first] = -1;
  sz[first] = 1;
  dep[first] = dep[par] + 1;
  int mx = 0;
  for (int i = 0; i < v[first].size(); i++) {
    int second = v[first][i];
    if (second == par) continue;
    dfs(second, first);
    sz[first] += sz[second];
    if (chkmax(mx, sz[second])) hs[first] = second;
  }
  ft[first] = timp;
}
map<int, int> mp;
int ps, mx;
void push_bag(int first) {
  mp[dep[first]]++;
  int cnt = mp[dep[first]];
  if (mx < cnt)
    ps = dep[first], mx = cnt;
  else if (mx == cnt && dep[first] < ps)
    ps = dep[first];
}
void dsu(int first, int par = 0, int keep = 1) {
  for (int i = 0; i < v[first].size(); i++) {
    int second = v[first][i];
    if (second == par || second == hs[first]) continue;
    dsu(second, first, 0);
  }
  if (hs[first] != -1) dsu(hs[first], first, 1);
  push_bag(first);
  for (int i = 0; i < v[first].size(); i++) {
    int second = v[first][i];
    if (second == par || second == hs[first]) continue;
    for (int j = dt[second]; j <= ft[second]; j++) {
      push_bag(ver[j]);
    }
  }
  ans[first] = ps - dep[first];
  if (keep) return;
  mp.clear();
  mx = 0;
}
int main() {
  n = getint();
  memset(hs, -1, sizeof hs);
  for (int i = 1; i < n; i++) {
    int first, second;
    first = getint(), second = getint();
    v[first].push_back(second), v[second].push_back(first);
  }
  dfs(1);
  dsu(1);
  for (int i = 1; i <= n; i++) {
    putint(ans[i]), putchar('\n');
  }
  return 0;
}
