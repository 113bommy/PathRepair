#include <bits/stdc++.h>
using namespace std;
namespace fastIO {
bool IOerror = 0;
inline char nc() {
  static char buf[100000], *p1 = buf + 100000, *pend = buf + 100000;
  if (p1 == pend) {
    p1 = buf;
    pend = buf + fread(buf, 1, 100000, stdin);
    if (pend == p1) {
      IOerror = 1;
      return -1;
    }
  }
  return *p1++;
}
inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline long long read() {
  bool sign = 0;
  char ch = nc();
  long long x = 0;
  for (; blank(ch); ch = nc())
    ;
  if (IOerror) return 0;
  if (ch == '-') sign = 1, ch = nc();
  for (; ch >= '0' && ch <= '9'; ch = nc()) x = x * 10 + ch - '0';
  if (sign) x = -x;
  return x;
}
};  // namespace fastIO
using namespace fastIO;
long long dep[1000010], maxx[1000010], fa[1000010], fa1[1000010];
vector<long long> e[1000010], v;
void dfs(long long x) {
  maxx[x] = dep[x];
  for (auto i : e[x]) {
    dep[i] = dep[x] + 1;
    dfs(i);
    maxx[x] = max(maxx[x], maxx[i]);
  }
}
vector<long long> op;
long long pos[1000010], id[1000010];
bool cmp(long long x, long long y) { return maxx[x] < maxx[y]; }
void dfss(long long x) {
  v.push_back(x);
  sort(e[x].begin(), e[x].end(), cmp);
  for (auto i : e[x]) dfss(i);
}
bool cmpp(long long x, long long y) {
  return (dep[x] == dep[y]) ? (pos[x] < pos[y]) : (dep[x] > dep[y]);
}
signed main() {
  long long n = read();
  for (long long i = 2; i <= n; i++)
    fa[i] = read(), fa[i]++, e[fa[i]].push_back(i);
  dep[1] = 1;
  dfs(1);
  dfss(1);
  long long nn = 0;
  for (auto i : v) cout << i - 1 << ' ', pos[i] = ++nn;
  cout << '\n';
  for (long long i = 1; i < v.size(); i++) fa1[v[i]] = v[i - 1];
  cout << n - maxx[1] << '\n';
  for (long long i = 1; i <= n; i++) id[i] = i;
  sort(id + 1, id + 1 + n, cmpp);
  for (long long i = 1; i <= n; i++) {
    while (fa[id[i]] != fa1[id[i]]) {
      op.push_back(id[i]);
      fa1[id[i]] = fa1[fa1[id[i]]];
    }
  }
  for (auto i : op) cout << i - 1 << ' ';
  return 0;
}
