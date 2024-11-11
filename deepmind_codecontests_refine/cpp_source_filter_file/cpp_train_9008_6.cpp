#include <bits/stdc++.h>
using namespace std;
struct __io_dev {
  __io_dev(const bool& __fastio = false) {
    if (__fastio) ios_base::sync_with_stdio(false), cin.tie(nullptr);
    srand(time(nullptr));
    if (!string("").empty())
      freopen(
          ""
          ".in",
          "r", stdin),
          freopen(
              ""
              ".out",
              "w", stdout);
  }
  ~__io_dev() { fprintf(stderr, "%.6f ms\n", 1e3 * clock() / CLOCKS_PER_SEC); }
} __io(false);
const long long inf = (long long)1e+9 + 7ll;
const long long linf = (long long)1e+18 + 7ll;
const long double eps = (long double)1e-9;
const long double pi = acosl((long double)-1.0);
const int alph = 26;
const int sqr = 3017;
static char buff[(int)2e6 + 17];
long long __p[3] = {29ll, 31ll, 33ll};
long long __mod[3] = {inf, inf + 2ll, 14881337ll};
const int maxn = (int)2e6 + 17;
int n;
vector<int> g[maxn];
int c[maxn];
long double p[maxn];
void dfs1(int v, int pr = -1) {
  c[v] = 1;
  for (auto to : g[v])
    if (to != pr) {
      dfs1(to, v);
      c[v] += c[to];
    }
}
void dfs(int v, int pr = -1) {
  for (auto to : g[v])
    if (to != pr) {
      p[to] = p[v] + 1 + (c[v] - 1 - c[to]) / 2.0;
      dfs(to, v);
    }
}
int main() {
  scanf("%d", &n);
  for (long long i = (long long)1; i < (long long)n; ++i) {
    int a;
    scanf("%d", &a);
    g[--a].push_back(i), g[i].push_back(a);
  }
  p[0] = 1.0;
  dfs1(0);
  dfs(0);
  for (long long i = 0ll; i < (long long)n; ++i) printf("%.7Lf ", p[i]);
  return 0;
}
