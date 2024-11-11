#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long dx[4] = {-1, 1, 0, 0};
const long long dy[4] = {0, 0, -1, 1};
const long long MAX = 3e5;
const long long oo = 1e16;
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long n, m, k, Q, l, x, y, ans;
string second;
long long a[MAX];
typedef struct Vehicule {
  int from;
  int to;
  long long cons;
  int refuel;
};
Vehicule v[MAX];
long long dp[500][500];
vector<vector<int> > st;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  st.clear();
  st.resize(n + 1);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) {
    cin >> v[i].from >> v[i].to >> v[i].cons >> v[i].refuel;
    v[i].from--;
    v[i].to--;
    st[v[i].from].push_back(i);
  }
  ans = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) dp[i][j] = oo;
  for (int l = 0; l < n; ++l) {
    for (int r = l; r < n; ++r) dp[r][1] = a[r] - a[l];
    for (int r = l + 1; r < n; ++r)
      for (int k = 2; k < n + 5; ++k) {
        long long best = oo;
        int j = r;
        while (j >= l && max(dp[j][k - 1], a[r] - a[j]) <= best)
          best = max(dp[j][k - 1], a[r] - a[j]), --j;
        dp[r][k] = best;
      }
    for (auto u : st[l])
      ans = max(ans, dp[v[u].to][v[u].refuel + 1] * 1LL * v[u].cons);
  }
  cout << ans << '\n';
  return 0;
}
