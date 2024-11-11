#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;
using VI = vector<int>;
using VVI = vector<VI>;
const ll MOD = 1e9 + 7;
VVI G;
VI V;
VVL M;
ll f(int i, int j) {
  if (j < 0 or j > i) return 0;
  ll& res = M[i][j];
  if (res != -1) return res;
  if (j == 0) return res = 1;
  return res = (f(i - 1, j) + V[i - 1] * f(i - 1, j - 1)) % MOD;
}
void dfs(int x, int p, int d, VI& V) {
  if (d >= (int)V.size())
    V.push_back(1);
  else
    ++V[d];
  for (int y : G[x])
    if (y != p) dfs(y, x, d + 1, V);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    G = VVI(n);
    for (int r = 0; r < n - 1; ++r) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    if (k == 2)
      cout << n * (n - 1) / 2 << endl;
    else {
      ll res = 0;
      for (int x = 0; x < n; ++x) {
        int m = G[x].size();
        VVI T(m);
        int mx = 0;
        for (int i = 0; i < m; ++i) {
          dfs(G[x][i], x, 0, T[i]);
          mx = max(mx, (int)T[i].size());
        }
        for (int d = 0; d < mx; ++d) {
          V.clear();
          for (int i = 0; i < m; ++i)
            if (d < (int)T[i].size()) V.push_back(T[i][d]);
          int q = V.size();
          if (q >= k) {
            M = VVL(q + 1, VL(k + 1, -1));
            res = (res + f(q, k)) % MOD;
          }
        }
      }
      cout << res << endl;
    }
  }
}
