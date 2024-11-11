#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
const int INF = 0x3f3f3f3f;
const long long p = 1e9 + 7;
int n, m, N, a[MAXN];
long long b[MAXN], c[MAXN];
vector<int> G[MAXN];
int dfs(int u, int fa) {
  int res = 1, x;
  for (int& v : G[u])
    if (v != fa) {
      x = dfs(v, u), res += x;
      b[++N] = 1ll * x * (n - x) % p;
    }
  return res;
}
inline void run() {
  cin >> n, N = 0;
  for (int i = (int)(1); i <= (int)(n); i++) G[i].clear();
  int u, v;
  for (int i = (int)(2); i <= (int)(n); i++) {
    cin >> u >> v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  dfs(1, 0);
  sort(b + 1, b + N + 1, greater<long long>());
  cin >> m;
  for (int i = (int)(1); i <= (int)(m); i++) cin >> a[i];
  sort(a + 1, a + m + 1, greater<int>());
  long long res = 0;
  if (N > m) {
    for (int i = (int)(1); i <= (int)(m); i++)
      res = (res + a[i] * b[i] % p) % p;
    for (int i = (int)(m + 1); i <= (int)(N); i++) res = (res + b[i]) % p;
  } else {
    for (int i = (int)(N); i >= (int)(1); i--) c[i] = a[m--];
    while (m) c[1] = c[1] * a[m--] % p;
    for (int i = (int)(1); i <= (int)(N); i++)
      res = (res + c[i] * b[i] % p) % p;
  }
  cout << (res) << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  int T;
  for (cin >> T; T--;) run();
  return 0;
}
