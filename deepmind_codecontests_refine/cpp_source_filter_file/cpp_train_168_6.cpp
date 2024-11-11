#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <typename T>
constexpr int infValue =
    std::is_same<T, int>::value ? 2000000007 : 8600000000000000007ll;
template <typename T>
constexpr int maxValue =
    std::is_same<T, int>::value ? 1000000007 : 1000000000000000001ll;
const int INF = infValue<int>;
const int MOD = 1000000007ll;
const double EPS = 1e-6;
const int MAX = maxValue<int>;
int n, m, h;
int ut[101001];
vector<int> g[101001], gr[101001];
char u[101001], cv = 1;
vector<int> p;
void dfs1(int v) {
  u[v] = cv;
  for (int to : g[v]) {
    if (!u[to]) dfs1(to);
  }
  p.push_back(v);
}
bool use;
vector<int> cmp, acmp;
void dfs2(int v) {
  u[v] = cv;
  cmp.push_back(v);
  for (int to : gr[v])
    if (u[to] == 1) dfs2(to);
}
void dfs3(int v) {
  for (int to : g[v])
    if (u[to] != cv) use = false;
}
int c0, c1;
int main(void) {
  scanf("%d %d %d", &n, &m, &h);
  for (register int i = 1; i <= n; ++i) scanf("%d", ut + i);
  while (m--) {
    scanf("%d %d", &c0, &c1);
    if ((ut[c0] + 1) % h == ut[c1]) g[c0].push_back(c1), gr[c1].push_back(c0);
    if ((ut[c1] + 1) % h == ut[c0]) g[c1].push_back(c0), gr[c0].push_back(c1);
  }
  for (register int i = 1; i <= n; ++i)
    if (!u[i]) dfs1(i);
  for (register int i = p.size() - 1; i >= 0; --i) {
    if (u[p[i]] == 1) {
      ++cv, use = true, cmp.clear();
      dfs2(p[i]);
      for (int v : cmp) {
        dfs3(v);
      }
      if (use && (acmp.empty() || cmp.size() <= acmp.size())) swap(cmp, acmp);
    }
  }
  printf("%d\n", acmp.size());
  for (int v : acmp) printf("%d ", v);
  putc('\n', stdout);
  return 0;
}
