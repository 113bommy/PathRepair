#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int MAXK = 50;
const int mod = (int)1e9 + 7;
int n, k;
vector<int> g[MAXN];
int dp[MAXN][MAXK][MAXK];
int f[MAXN][MAXK][2];
int NN;
void calc(int v, int p = -1) {
  for (int i = 0; i < (int)g[v].size(); i++) {
    if (g[v][i] == p) {
      g[v].erase(find(g[v].begin(), g[v].end(), p));
      break;
    }
  }
  for (int i = 0; i < (int)g[v].size(); i++) {
    int to = g[v][i];
    calc(to, v);
  }
  for (int up = 0; up <= NN; up++) {
    for (int down = 0; down <= NN; down++) {
      if (up > k && down > k) continue;
      if (down == 0) {
        dp[v][up][down] = 1;
        for (int i = 0; i < (int)g[v].size(); i++) {
          int to = g[v][i];
          int sum = 0;
          for (int j = 0; j <= NN; j++) {
            sum = (sum + dp[to][1][j]) % mod;
          }
          dp[v][up][down] = (1ll * dp[v][up][down] * sum) % mod;
        }
      } else if (down == NN) {
        dp[v][up][down] = 1;
        for (int i = 0; i < (int)g[v].size(); i++) {
          int to = g[v][i];
          dp[v][up][down] =
              (1ll * dp[v][up][down] * dp[to][up + 1][down]) % mod;
        }
      } else {
        memset(f, 0, sizeof(f));
        int en = (int)g[v].size();
        int nup = min(up + 1, down + 1);
        f[en][down - 1][1] = 1;
        for (int i = en - 1; i >= 0; i--) {
          int to = g[v][i];
          for (int j = NN; j >= down - 1; j--) {
            for (int l = 0; l <= 1; l++) {
              int go = (j == down - 1) || l;
              f[i][j][l] = 1ll * dp[to][nup][j] * f[i + 1][down - 1][go] % mod;
              f[i][j][l] = (f[i][j][l] + f[i][j + 1][l]) % mod;
            }
          }
        }
        dp[v][up][down] = f[0][down - 1][0];
      }
    }
  }
}
int main() {
  scanf("%d %d", &n, &k);
  NN = k + 1;
  for (int i = 1; i < n; i++) {
    int from, to;
    scanf("%d %d", &from, &to);
    g[from].push_back(to);
    g[to].push_back(from);
  }
  calc(1);
  int ans = 0;
  for (int i = 0; i <= NN; i++) {
    ans = (ans + dp[1][NN][i]) % mod;
  }
  cout << ans << endl;
  return 0;
}
