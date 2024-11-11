#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
const int INF = 2e9 + 5;
const long long LINF = 1e18 + 5;
const long long MOD = 1e9 + 7;
int a[1 << 5];
int dp[1 << 5][1 << 6][1 << 11];
pair<pair<int, int>, int> path[1 << 5][1 << 6][1 << 11];
int cnt[1 << 5];
pair<int, int> torneo[1 << 5];
int ad[1 << 6][1 << 6];
int go(int tipo, int k, int sum) {
  if (tipo < 0) return 0;
  if (sum * 2 < k * (k - 1)) return 0;
  if (k == 1) {
    if (tipo > 0) return 0;
    if (sum != a[0])
      return 0;
    else
      return 1;
  }
  if (dp[tipo][k][sum] != -1) return dp[tipo][k][sum];
  int value1 = 0, value2 = 0;
  value1 = go(tipo, k - 1, sum - a[tipo]);
  if (tipo > 0) value2 = go(tipo - 1, k - 1, sum - a[tipo]);
  if (value1) {
    path[tipo][k][sum] = make_pair(make_pair(tipo, k - 1), sum - a[tipo]);
  } else if (value2) {
    path[tipo][k][sum] = make_pair(make_pair(tipo - 1, k - 1), sum - a[tipo]);
  }
  return dp[tipo][k][sum] = value1 || value2;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) cin >> a[i];
  sort(a, a + m);
  for (int i = 0; i < 1 << 5; ++i)
    for (int j = 0; j < 1 << 6; ++j)
      for (int r = 0; r < 1 << 11; ++r) {
        dp[i][j][r] = -1;
        path[i][j][r] = make_pair(make_pair(0, 0), 0);
      }
  int ans = -1;
  for (int i = 62; i >= 1; --i) {
    if (go(m - 1, i, i * (i - 1) / 2)) {
      ans = i;
      break;
    }
  }
  if (ans == -1) {
    cout << "=(" << endl;
    return 0;
  }
  int sx = m - 1, sy = ans, sz = ans * (ans - 1) / 2;
  while (sy != 0) {
    cnt[sx]++;
    pair<pair<int, int>, int> tmp = path[sx][sy][sz];
    sx = tmp.first.first;
    sy = tmp.first.second;
    sz = tmp.second;
  }
  int player = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < cnt[i]; ++j) {
      torneo[player] = make_pair(a[i], player);
      ++player;
    }
  }
  assert(player == ans);
  for (int it = 0; it < ans; ++it) {
    sort(torneo + it, torneo + ans);
    int victorias = torneo[it].first;
    int id1 = torneo[it].second;
    for (int i = it + 1; i <= it + victorias; ++i) {
      int id2 = torneo[i].second;
      ad[id1][id2] = 1;
    }
    for (int i = it + victorias + 1; i < ans; ++i) {
      int id2 = torneo[i].second;
      ad[id2][id1] = 1;
      torneo[i].first--;
    }
  }
  cout << ans << endl;
  for (int i = 0; i < ans; ++i) {
    for (int j = 0; j < ans; ++j) {
      cout << ad[i][j];
    }
    cout << endl;
  }
  return 0;
}
