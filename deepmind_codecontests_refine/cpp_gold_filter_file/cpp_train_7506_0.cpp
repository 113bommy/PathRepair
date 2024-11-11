#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long Inf = 1e18;
const int N = 5e5 + 10;
const int mod = 998244353;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
template <typename T>
bool chkmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
};
template <typename T>
bool chkmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
};
int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
void inc(int &a, int b) { a = (a + b >= mod ? a + b - mod : a + b); }
void dec(int &a, int b) { a = (a - b < 0 ? a - b + mod : a - b); }
int n;
vector<int> E[N];
pair<int, int> f[N][2];
pair<int, int> operator*(pair<int, int> a, pair<int, int> b) {
  return make_pair(
      add(1ll * a.first * b.second % mod, 1ll * a.second * b.first % mod),
      1ll * a.second * b.second % mod);
}
pair<int, int> operator*(pair<int, int> a, int b) {
  return make_pair(1ll * a.first * b % mod, 1ll * a.second * b % mod);
}
pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
  return make_pair(add(a.first, b.first), add(a.second, b.second));
}
void dfs(int u, int fa) {
  f[u][0] = make_pair(0, 1);
  for (int v : E[u])
    if (v != fa) {
      dfs(v, u);
      f[u][1] = f[u][1] * (f[v][0] + f[v][1]) * 2 + f[u][0] * f[v][0] +
                make_pair(1ll * f[u][0].second * f[v][0].second % mod, 0);
      f[u][0] = f[u][0] * (f[v][0] + f[v][1] * 2);
    }
}
int main() {
  n = gi();
  for (int i = 1, u, v; i < n; i++)
    u = gi(), v = gi(), E[u].push_back(v), E[v].push_back(u);
  dfs(1, 0);
  printf("%lld\n", 2ll * (f[1][0].first + f[1][1].first) % mod);
  return 0;
}
