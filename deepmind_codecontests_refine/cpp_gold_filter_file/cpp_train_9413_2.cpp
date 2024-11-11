#include <bits/stdc++.h>
using namespace std;
bool debug = true;
template <typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> ptt) {
  os << ptt.first << "," << ptt.second;
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> vt) {
  os << "{";
  for (int i = 0; i < vt.size(); i++) {
    os << vt[i] << " ";
  }
  os << "}";
  return os;
}
int n, m;
int d[55][55];
int mx[55], mn[55];
int g1, g2, s1, s2;
int gp[55], bp[55], sp[55];
long long dp[55][55][55];
int main(int argc, char* argv[]) {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      d[i][j] = 1e9;
    }
  }
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    d[a][b] = min(d[a][b], c);
    d[b][a] = min(d[b][a], c);
  }
  cin >> g1 >> g2 >> s1 >> s2;
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    mx[i] = 0;
    mn[i] = 1e9;
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      d[i][j] = d[i][j] * 100 + i;
      mx[i] = max(mx[i], d[i][j]);
      mn[i] = min(mn[i], d[i][j]);
    }
  }
  long long ans = 0;
  for (int gold = 0; gold < n; gold++) {
    for (int bronze = 0; bronze < n; bronze++) {
      if (gold == bronze) {
        continue;
      }
      if (mn[gold] >= mx[bronze]) {
        continue;
      }
      for (int i = 0; i < n; i++) {
        gp[i] = (mn[i] <= mn[gold]);
        bp[i] = (mx[i] >= mx[bronze]);
        sp[i] = false;
        for (int j = 0; j < n; j++) {
          if (i != j && d[i][j] > mn[gold] && d[i][j] < mx[bronze]) {
            sp[i] = true;
            break;
          }
        }
      }
      gp[gold] = true;
      bp[gold] = sp[gold] = false;
      gp[bronze] = sp[bronze] = false;
      bp[bronze] = true;
      memset(dp, 0, sizeof(dp));
      dp[0][0][0] = 1;
      for (int i = 0; i < n; i++) {
        for (int j = n; j >= 0; j--) {
          for (int k = n; k >= 0; k--) {
            if (dp[j][k]) {
              if (gp[i]) {
                dp[i + 1][j + 1][k] += dp[i][j][k];
              }
              if (sp[i]) {
                dp[i + 1][j][k + 1] += dp[i][j][k];
              }
              if (bp[i]) {
                dp[i + 1][j][k] = dp[i][j][k];
              }
            }
          }
        }
      }
      for (int i = g1; i <= g2; i++) {
        for (int j = s1; j <= s2; j++) {
          ans += dp[n][i][j];
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
