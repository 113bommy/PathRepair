#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, ki;
  scanf("%d %d %d", &n, &m, &ki);
  string bins;
  long long int dp[505][505];
  long long int weight[505][505];
  for (int i = 0; i < 505; i++) {
    for (int j = 0; j < 505; j++) {
      weight[i][j] = 10000000;
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> bins;
    vector<long long int> indices;
    for (int j = 0; j < m; j++) {
      if (bins[j] == '1') indices.push_back(j);
    }
    weight[i][m] = 0;
    for (int x = 0; x < ki + 1; x++) {
      if (x >= (int)indices.size() || (int)indices.size() == 0) break;
      int iright = (int)indices.size() - 1;
      for (int y = 0; y <= x; y++) {
        weight[i][x] =
            min(weight[i][x], indices[iright - y] - indices[x - y] + 1);
      }
    }
  }
  for (int i = 0; i < 505; i++) {
    if (weight[0][i] == 10000000) weight[0][i] = 0;
    dp[0][i] = weight[0][i];
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < ki + 1; j++) {
      dp[i][j] = 10000000;
      if (weight[i][j] == 10000000) weight[i][j] = 0;
      for (int k = j; k >= 0; k--) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + weight[i][k]);
      }
    }
  }
  cout << dp[n - 1][ki] << endl;
}
