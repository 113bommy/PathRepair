#include <bits/stdc++.h>
using namespace std;
const int N = 80;
vector<int> V;
vector<int> K;
vector<int> X;
int dp[N][N][N][2];
int cnt(int v, int k, int x, int lim) {
  int res = 0;
  for (int i = v; i < V.size() && V[i] < lim; i++) res++;
  for (int i = k; i < K.size() && K[i] < lim; i++) res++;
  for (int i = x; i < X.size() && X[i] < lim; i++) res++;
  return res;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        for (int w = 0; w < 2; w++) {
          dp[i][j][k][w] = 2e9;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == 'V')
      V.push_back(i);
    else if (c == 'K')
      K.push_back(i);
    else
      X.push_back(i);
  }
  dp[0][0][0][0] = 0;
  for (int v = 0; v <= V.size(); v++) {
    for (int k = 0; k <= K.size(); k++) {
      for (int x = 0; x <= X.size(); x++) {
        for (int w = 0; w < 2; w++) {
          int a = dp[v][k][x][w];
          if (v < V.size())
            dp[v + 1][k][x][1] =
                min(dp[v + 1][k][x][1], a + cnt(v, k, x, V[v]));
          if (k < K.size() && w == 0)
            dp[v][k + 1][x][0] =
                min(dp[v][k + 1][x][0], a + cnt(v, k, x, K[k]));
          if (x < X.size())
            dp[v][k][x + 1][0] =
                min(dp[v][k][x + 1][0], a + cnt(v, k, x, X[x]));
        }
      }
    }
  }
  cout << min(dp[V.size()][K.size()][X.size()][0],
              dp[V.size()][K.size()][X.size()][1]);
  return 0;
}
