#include <bits/stdc++.h>
using namespace std;
const long long INF = (1 << 30);
const long long inf = (1LL << 60LL);
const long long maxn = 80;
int n;
string s;
int cost[maxn][maxn][maxn][3];
int dp[maxn][maxn][maxn][4];
int rek(int i, int j, int k, int last) {
  if (i == 0 && j == 0 && k == 0) {
    return 0;
  }
  if (dp[i][j][k][last] != -1) {
    return dp[i][j][k][last];
  }
  int ret = INF;
  if (i > 0) {
    ret = min(ret, rek(i - 1, j, k, 0) + cost[i][j][k][0]);
  }
  if (j > 0 && last != 0) {
    ret = min(ret, rek(i, j - 1, k, 1) + cost[i][j][k][1]);
  }
  if (k > 0) {
    ret = min(ret, rek(i, j, k - 1, 2) + cost[i][j][k][2]);
  }
  return dp[i][j][k][last] = ret;
}
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin >> n >> s;
  int V = 0, K = 0, X = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'V') {
      ++V;
    } else if (s[i] == 'K') {
      ++K;
    } else {
      ++X;
    }
  }
  int tmpV, tmpK, tmpX;
  for (int i = 0; i <= V; i++) {
    for (int j = 0; j <= K; j++) {
      for (int k = 0; k <= X; k++) {
        tmpV = i - V;
        tmpK = j - K;
        tmpX = k - X;
        for (int it = 0; it < n; it++) {
          if (s[it] == 'V') {
            if (tmpV == 0) {
              cost[i][j][k][0] = max(-tmpK, 0) + max(-tmpX, 0);
            }
            tmpV--;
          } else if (s[it] == 'K') {
            if (tmpK == 0) {
              cost[i][j][k][1] = max(-tmpV, 0) + max(-tmpX, 0);
            }
            tmpK--;
          } else {
            if (tmpX == 0) {
              cost[i][j][k][2] = max(-tmpV, 0) + max(-tmpK, 0);
            }
            tmpX--;
          }
        }
      }
    }
  }
  memset(dp, -1, sizeof dp);
  cout << rek(V, K, X, 2) << endl;
  return 0;
}
