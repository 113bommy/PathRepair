#include <bits/stdc++.h>
using namespace std;
int dp[1 << 20];
int cnt[20][20];
int cost[1 << 20];
const int N = 100000 * 21;
int main() {
  int n;
  int m;
  int x;
  int y;
  int bitset;
  string str;
  cin >> n;
  cin >> m;
  cin >> str;
  for (int i = 0; i + 1 < str.length(); i++) {
    x = str[i] - 'a';
    y = str[i + 1] - 'a';
    cnt[x][y] += 1;
  }
  for (int i = 0; i < (1 << m); i++)
    for (int k = 0; k < m; k++)
      for (int l = 0; l < m; l++)
        if ((i & (1 << k)) && !(i & (1 << l)))
          cost[i] = cost[i] + cnt[k][l] + cnt[l][k];
  for (int i = 0; i < (1 << m); i++) {
    bitset = __builtin_popcount(i);
    if (bitset == 0 || bitset == 1)
      dp[i] = 0;
    else
      dp[i] = N;
  }
  for (int i = 0; i < (1 << m); i++)
    for (int j = 0; j < m; j++) {
      if (!(i & (1 << j))) {
        dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + cost[i]);
      }
    }
  cout << dp[(1 << m) - 1] << '\n';
  return 0;
}
