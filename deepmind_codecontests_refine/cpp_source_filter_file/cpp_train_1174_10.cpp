#include <bits/stdc++.h>
using namespace std;
const int iinf = 1e9 + 10;
const long long inf = 1ll << 60;
const long long mod = 1e9 + 7;
void GG() {
  cout << "0\n";
  exit(0);
}
long long mpow(long long a, long long n, long long mo = mod) {
  long long re = 1;
  while (n > 0) {
    if (n & 1) re = re * a % mo;
    a = a * a % mo;
    n >>= 1;
  }
  return re;
}
long long inv(long long b, long long mo = mod) {
  if (b == 1) return b;
  return (mo - mo / b) * inv(mo % b, mo) % mo;
}
const int maxn = 2e6 + 5;
int V[maxn];
vector<int> g[maxn];
int dp[maxn][2];
int re = 0;
inline void upd(int &f1, int &f2, int nw) {
  if (nw > f1) {
    f2 = f1;
    f1 = nw;
  } else if (nw > f2) {
    f2 = nw;
  }
}
int LIM = 0;
void dfs(int v, int p) {
  dp[v][0] = dp[v][1] = 0;
  int f01 = 0, f02 = 0, f11 = 0, f12 = 0;
  for (int u : g[v]) {
    if (u != p) {
      dfs(u, v);
      if (V[v] & 1) {
        dp[v][0] =
            max(dp[v][0], (__typeof__(dp[v][0]))(min(dp[u][0], dp[u][1] + 1)));
        upd(f01, f02, min(dp[u][0], dp[u][1] + 1));
      }
      if (V[v] & 2) {
        dp[v][1] =
            max(dp[v][1], (__typeof__(dp[v][1]))(min(dp[u][1], dp[u][0] + 1)));
        upd(f11, f12, min(dp[u][1], dp[u][0] + 1));
      }
    }
  }
  if (!(V[v] & 1) || f01 + f02 > LIM) {
    dp[v][0] = 10000000;
  }
  if (!(V[v] & 2) || f01 + f02 > LIM) {
    dp[v][1] = 10000000;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> V[i], V[i] += !V[i] ? 3 : 0;
    for (int i = 0; i < n; ++i) g[i].clear();
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    int l = 0, r = n - 1;
    while (l != r) {
      LIM = (l + r) / 2;
      dfs(0, -1);
      if (dp[0][0] < n || dp[0][1] < n) {
        r = LIM;
      } else {
        l = LIM + 1;
      }
    };
    cout << (l + 1) / 2 + 1 << '\n';
  }
}
