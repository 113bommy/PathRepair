#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
inline long long input() {
  long long n;
  cin >> n;
  return n;
}
string base2(long long n) {
  string a = "";
  while (n >= 2) {
    a += (char)(n % 2 + '0');
    n /= 2;
  }
  a += (char)(n + '0');
  reverse((a).begin(), (a).end());
  return a;
}
const int MAXN = 5e2 + 10;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const long long INF = 8e18;
long long pw(long long a, long long b, long long mod) {
  return (!b ? 1
             : (b & 1 ? (a * pw(a * a % mod, b / 2, mod)) % mod
                      : pw(a * a % mod, b / 2, mod)));
}
vector<pair<int, int> > G[MAXN];
int n, m, mark[MAXN], D[MAXN];
long long dp[MAXN][MAXN], dis[MAXN][MAXN];
pair<long long, pair<long long, long long> > E[100010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dis[i][j] = 1e18;
      if (i == j) {
        dis[i][j] = 0;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    G[a].push_back(make_pair(b, c));
    G[b].push_back(make_pair(a, c));
    dis[a][b] = dis[b][a] = min({dis[b][a], dis[a][b], c});
    E[i] = make_pair(c, make_pair(a, b));
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  for (int v = 1; v <= n; v++) {
    for (int i = 1; i <= n; i++) {
      D[i] = 0;
    }
    for (int j = 1; j <= m; j++) {
      int a = E[j].second.first, b = E[j].second.second;
      if (dis[v][a] > dis[v][b]) {
        swap(a, b);
      }
      if (dis[v][a] + E[j].first == dis[v][b]) {
        D[b]++;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int k = 1; k <= n; k++) {
        if (dis[v][i] == dis[v][k] + dis[k][i]) {
          dp[v][i] += D[k];
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cout << dp[i][j] << " ";
    }
  }
  return 0;
}
