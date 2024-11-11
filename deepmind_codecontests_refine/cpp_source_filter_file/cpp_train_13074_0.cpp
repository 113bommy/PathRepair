#include <bits/stdc++.h>
using namespace std;
template <class X, class Y>
void amax(X& x, const Y& y) {
  if (x < y) x = y;
}
template <class X, class Y>
void amin(X& x, const Y& y) {
  if (x > y) x = y;
}
const int INF = 1e9 + 10;
const long long INFL = 1e18 + 10;
const int MAX = 2e5 + 10;
int n, m;
bool forbid[MAX], mark[MAX];
vector<int> g[MAX];
int f[MAX], nxt[MAX];
void visit(int u) {
  f[u] = g[u].size();
  int vmax = 0;
  mark[u] = true;
  for (int i = 2; i <= m / u; i++) {
    if (!mark[i * u] && g[i * u].size() > 0) visit(i * u);
    if (f[i * u] > vmax) {
      vmax = f[i * u];
      nxt[u] = i * u;
    }
  }
  f[u] += vmax;
}
int gcd(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}
pair<int, int> revmod(int a, int b) {
  int x0 = 1, x1 = 0;
  while (b != 0) {
    int q = a / b;
    int t = x0;
    x0 = x1;
    x1 = t - q * x1;
    t = a;
    a = b;
    b = t - q * b;
  }
  return make_pair(a, x0);
}
int findx(int a, int b) {
  a %= m;
  b %= m;
  pair<int, int> x = revmod(a, m);
  int res = ((long long)x.second * (b / x.first)) % m;
  if (res < 0) res += m;
  return res;
}
void process() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    forbid[a] = true;
  }
  for (int i = 1; i <= m; i++)
    if (!forbid[i % m]) g[gcd(i, m)].push_back(i);
  for (int i = 1; i <= m; i++)
    if (!mark[i] && g[i].size() > 0) visit(i);
  int vmax = 0, pmax = 0;
  for (int i = 1; i <= m; i++) {
    if (f[i] > vmax) {
      vmax = f[i];
      pmax = i;
    }
  }
  vector<int> res;
  while (pmax != 0) {
    for (auto x : g[pmax]) res.push_back(x);
    pmax = nxt[pmax];
  }
  cout << res.size() << '\n';
  for (int i = 0; i < (int)res.size(); i++) {
    if (i == 0) {
      cout << res[i] << " ";
      continue;
    }
    cout << findx(res[i - 1], res[i]) << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  process();
}
