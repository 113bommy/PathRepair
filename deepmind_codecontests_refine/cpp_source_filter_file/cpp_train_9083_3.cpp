#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long long int MOD = 1e9 + 7;
const int N = 6e3 + 6;
int dp[N][N];
bool ase[N][N];
vector<int> edg[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> l(n + 1), r(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
      cin >> l[i] >> r[i];
      mp[l[i]] = 1;
      mp[r[i]] = 1;
    }
    int cnt = 0;
    for (auto &x : mp) x.second = ++cnt;
    for (int i = 0; i <= cnt; i++) {
      for (int j = 0; j <= cnt; j++) {
        dp[i][j] = 0;
        ase[i][j] = 0;
      }
      edg[i].clear();
    }
    for (int i = 1; i <= n; i++) {
      l[i] = mp[l[i]];
      r[i] = mp[r[i]];
      edg[l[i]].push_back(r[i]);
      ase[l[i]][r[i]] = 1;
    }
    for (int i = 0; i <= n; i++) sort(edg[i].begin(), edg[i].end());
    for (int len = 1; len <= cnt; len++) {
      for (int frm = 1; frm + len - 1 <= cnt; frm++) {
        int to = frm + len - 1;
        dp[frm][to] = ase[frm][to] + dp[frm + 1][to];
        for (auto x : edg[frm]) {
          if (x >= to) break;
          dp[frm][to] =
              max(dp[frm][to], ase[frm][to] + dp[frm][x] + dp[x + 1][to]);
        }
      }
    }
    cout << dp[1][cnt] << '\n';
  }
  return 0;
}
