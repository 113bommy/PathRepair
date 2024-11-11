#include <bits/stdc++.h>
using namespace std;
const long long size = 1400002;
const long long mod = 1000000007;
void PLL(initializer_list<long long> li) {
  for (auto beg = li.begin(); beg != li.end(); beg++) {
    if (beg != li.begin()) cout << ' ';
    cout << *beg;
  }
  cout << endl;
}
const long long Inf = ~0ull >> 2;
long long dp[101][21][21], tt[21][21];
int n, k;
vector<int> vi[101];
long long add(long long a, long long b) { return (a + b) % mod; }
long long mul(long long a, long long b) { return (a * b) % mod; }
void dfs(int u, int f) {
  dp[u][k][k] = 1;
  for (auto v : vi[u]) {
    if (v == f) continue;
    dfs(v, u);
    memset(tt, 0, sizeof(tt));
    for (int ui = 0; ui <= k; ui++)
      for (int uj = 0; uj <= k; uj++)
        for (int vi = 0; vi <= k; vi++)
          for (int vj = 0; vj <= k; vj++) {
            int uu = min(ui, vi);
            int vv = max(uj, vj);
            if (vv == k) vv = min(uj, vj);
            tt[uu][vv] = add(tt[uu][vv], mul(dp[u][ui][uj], dp[v][vi][vj]));
          }
    memcpy(dp[u], tt, sizeof(tt));
  }
  memset(tt, 0, sizeof(tt));
  for (int i = 0; i <= k; i++)
    for (int j = 0; j <= k; j++) {
      tt[0][k] = add(tt[0][k], dp[u][i][j]);
      if (j == k - 1) continue;
      int nu = min(k, i + 1), nv;
      if (j == k) {
        if (i == k)
          nv = 0;
        else
          nv = k;
      } else {
        if (j + 2 + i <= k)
          nv = k;
        else
          nv = j + 1;
      }
      tt[nu][nv] = add(tt[nu][nv], dp[u][i][j]);
    }
  memcpy(dp[u], tt, sizeof(tt));
}
int main() {
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    vi[a].push_back(b);
    vi[b].push_back(a);
  }
  dfs(1, 0);
  long long ans = 0;
  for (int i = 0; i <= k; i++) ans = add(ans, dp[1][i][k]);
  if (k == 0) ans = 1;
  cout << ans << endl;
}
