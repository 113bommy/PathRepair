#include <bits/stdc++.h>
using namespace std;
int BIT(int i, long long x) { return (x & (1 << i)); }
long long ONBIT(int i, long long x) { return (x | (1 << i)); }
long long OFFBIT(int i, long long x) { return (x & ~(1 << i)); }
long long FLIPBIT(int i, long long x) { return (x ^ (1 << i)); }
long long NUMBIT(long long x) { return __builtin_popcount(x); }
template <class T>
T gcd(T a, T b) {
  T r;
  int dem = 0;
  while (b != 0) {
    r = a % b;
    dem++;
    a = b;
    b = r;
  }
  cout << dem << endl;
  return a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
const int maxv = 1100;
const int maxe = maxv * maxv;
const int inf = (int)1e9 + 5;
const long long linf = (long long)1e17 + 5;
const int dr[] = {-1, 0, +1, 0};
const int dc[] = {0, +1, 0, -1};
const long double eps = 1e-9;
const char IN[] = "_.in";
const char OUT[] = "_.out";
const int maxn = 5011;
const int base = 1e9 + 7;
long long test, n, m, res;
long long sl[maxn], fx[maxn], c[maxn];
vector<pair<int, int> > ke[maxn];
struct canh {
  int x, y, z;
} e[maxn];
void dfs1(int u, int fa) {
  sl[u] = 1;
  c[u] = 0;
  for (__typeof(ke[u].begin()) i = ke[u].begin(); i != ke[u].end(); i++) {
    int v = (*i).first;
    int w = (*i).second;
    if (v != fa) {
      dfs1(v, u);
      sl[u] += sl[v];
      c[u] = c[u] + c[v] + w * sl[v] * (n - sl[v]);
    }
  }
}
void dfs2(int u, int fa, int k) {
  fx[u] = c[u];
  for (__typeof(ke[u].begin()) i = ke[u].begin(); i != ke[u].end(); i++) {
    int v = (*i).first;
    int w = (*i).second;
    if (v != fa) {
      dfs2(v, u, k);
      fx[u] = min(fx[u], c[u] - sl[v] * (n - sl[v]) * w +
                             (k - sl[v]) * (n - k + sl[v]) * w);
      fx[u] = min(fx[u], c[u] - c[v] + fx[v] - sl[v] * (n - sl[v]) * w +
                             (k - sl[v]) * (n - k + sl[v]) * w);
    }
  }
}
void solve(int x, int y, int w) {
  dfs1(x, y);
  dfs2(x, y, sl[x]);
  dfs1(y, x);
  dfs2(y, x, sl[y]);
  res = min(res, fx[x] + fx[y] + w * sl[x] * sl[y]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  srand(time(NULL));
  cin >> n;
  for (int i = (1); i <= (n - 1); i++) {
    int u, v, w;
    cin >> u >> v >> w;
    ke[u].push_back(make_pair(v, w));
    ke[v].push_back(make_pair(u, w));
    e[i].x = u;
    e[i].y = v;
    e[i].z = w;
  }
  res = linf;
  for (int i = (1); i <= (n - 1); i++) {
    solve(e[i].x, e[i].y, e[i].z);
  }
  cout << res << endl;
}
