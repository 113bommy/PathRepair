#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7, INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long n) {
  long long r = 1 % P;
  for (a %= P; n; a = a * a % P, n >>= 1)
    if (n & 1) r = r * a % P;
  return r;
}
long long inv(long long first) {
  return first <= 1 ? 1 : inv(P % first) * (P - P / first) % P;
}
inline int rd() {
  int first = 0;
  char p = getchar();
  while (p < '0' || p > '9') p = getchar();
  while (p >= '0' && p <= '9') first = first * 10 + p - '0', p = getchar();
  return first;
}
const int N = 1e6 + 50;
int n, m, dep[N];
pair<int, int> fa[N];
long long ans[N], c[N];
vector<pair<int, int> > g[N], v;
void get(int first, int second, int id) {
  if (dep[first] < dep[second] || dep[first] - dep[second] & 1 || v.size())
    return;
  v.push_back({second, id});
  while (first != second)
    v.push_back({first, fa[first].second}), first = fa[first].first;
}
void dfs(int first, int d) {
  dep[first] = d;
  for (auto e : g[first])
    if (e.first != fa[first].first) {
      int second = e.first;
      if (!dep[second])
        fa[second] = {first, e.second}, dfs(second, d + 1),
        c[first] -= ans[e.second];
      else
        get(first, second, e.second);
    }
  ans[fa[first].second] = c[first];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%lld", c + i);
  for (int i = 1; i <= m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[a].push_back({b, i});
    g[b].push_back({a, i});
  }
  dfs(1, 1);
  if (ans[0] & 1 || ans[0] && v.empty()) return puts("NO"), 0;
  puts("YES");
  if (ans[0]) {
    long long w = ans[0] / 2;
    int first = fa[v.back().first].first;
    if (dep[first] % 2 != dep[1] % 2) w = -w;
    for (auto &e : v) ans[e.second] += w, w = -w;
    while (first != 1)
      ans[fa[first].second] += 2 * w, w = -w, first = fa[first].first;
  }
  for (int i = 1; i <= m; ++i) printf("%lld\n", ans[i]);
}
