#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e6 + 100;
const long long inf = 0x3f3f3f3f;
const long long iinf = 1 << 30;
const long long linf = 2e18;
const long long mod = 998244353;
const double eps = 1e-7;
template <class T = long long>
T chmin(T &a, T b) {
  return a = min(a, b);
}
template <class T = long long>
T chmax(T &a, T b) {
  return a = max(a, b);
}
template <class T = long long>
inline void red(T &x) {
  x -= mod, x += x >> 31 & mod;
}
template <class T = long long>
T read() {
  T f = 1, a = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    a = (a << 3) + (a << 1) + ch - '0';
    ch = getchar();
  }
  return a * f;
}
long long n;
long long a[maxn], b[maxn], deg[maxn];
vector<pair<long long, long long> > edge[maxn];
long long stk[maxn], vis[maxn], top, head[maxn];
long long tim;
void dfs(long long now) {
  for (long long i = (head[now]); i <= (((long long)edge[now].size()) - 1);
       ++i) {
    while (i < ((long long)edge[now].size()) && vis[abs(edge[now][i].second)])
      ++i;
    head[now] = i;
    if (i >= ((long long)edge[now].size())) return;
    vis[abs(edge[now][i].second)] = 1;
    dfs(edge[now][i].first);
    stk[++top] = edge[now][i].second;
    i = head[i];
  }
}
signed main() {
  n = read();
  for (long long i = (1); i <= (n); ++i) a[i] = read(), b[i] = read();
  for (long long i = (20); i >= (0); --i) {
    long long lim = (1 << i) - 1;
    for (long long j = (0); j <= (lim); ++j)
      deg[j] = 0, vector<pair<long long, long long> >().swap(edge[j]),
      head[j] = 0;
    for (long long j = (1); j <= (n); ++j) {
      vis[j] = 0;
      long long u = a[j] & lim, v = b[j] & lim;
      deg[u]++, deg[v]++, edge[u].push_back(make_pair(v, j)),
          edge[v].push_back(make_pair(u, -j));
    }
    long long flag = 0;
    for (long long j = (0); j <= (lim); ++j) flag |= deg[j] & 1;
    if (flag) continue;
    top = 0;
    dfs(a[1] & lim);
    if (top < n) continue;
    printf("%lld\n", i);
    for (long long j = (n); j >= (1); --j) {
      if (stk[j] > 0)
        printf("%lld %lld ", stk[j] * 2 - 1, stk[j] * 2);
      else
        printf("%lld %lld ", -stk[j] * 2, -stk[j] * 2 - 1);
    }
    puts("");
    return 0;
  }
  return 0;
}
