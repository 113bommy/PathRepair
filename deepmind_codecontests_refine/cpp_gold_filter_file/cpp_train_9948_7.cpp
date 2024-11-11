#include <bits/stdc++.h>
using namespace std;
long long modpow(long long a, long long b,
                 long long mod = (long long)(1e9 + 7)) {
  if (!b) return 1;
  a %= mod;
  return modpow(a * a % mod, b / 2, mod) * (b & 1 ? a : 1) % mod;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mxn = 50000, T = 1000000;
int n, m;
int c[mxn], ct[T];
vector<int> adj[mxn], con[mxn];
void solve() {
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 0; i < mxn; i++) c[i] = -1;
  for (int i = 0; i < T; i++) ct[i] = uniform_int_distribution<int>(0, 1)(rng);
  for (int _ = 0; _ < m; _++) {
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    adj[--x].push_back(--y);
    adj[y].push_back(x);
  }
  int tt = 0;
  for (int i = 0; i < n; i++) {
    int sz;
    scanf("%d", &sz);
    for (int j = 0; j < sz; j++) {
      int x;
      scanf("%d", &x);
      x--;
      con[i].push_back(x);
      (tt) = max((tt), (x));
    }
  }
  for (int i = 0; i < n; i++) {
    int a = 0, b = 0;
    for (int j : adj[i]) {
      if (c[j] == 0) b++;
      if (c[j] == 1) a++;
    }
    if (b > a)
      c[i] = 1;
    else
      c[i] = 0;
  }
  stringstream ss;
  for (int i = 0; i < n; i++) {
    int ans = con[i][0];
    for (int x : con[i])
      if (c[i] == ct[x]) ans = x;
    ss << ans + 1 << " ";
  }
  ss << endl;
  for (int i = 0; i < tt + 1; i++) ss << ct[i] + 1 << " ";
  cout << ss.str() << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
