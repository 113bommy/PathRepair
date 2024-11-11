#include <bits/stdc++.h>
const int maxn = 4e5 + 10;
const int maxm = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const double eps = 1e-7;
using namespace std;
long long cnt[25][25], dp[1 << 21];
int n;
vector<int> pos[25];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    x--;
    pos[x].push_back(i);
  }
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      if (i != j) {
        if (!pos[i].size() || !pos[j].size()) continue;
        int p = 0;
        for (int k = 0; k < pos[i].size(); k++) {
          int x = pos[i][k];
          while (p < pos[j].size() && x > pos[j][p]) p++;
          cnt[i][j] += p;
        }
      }
    }
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for (int S = 0; S < (1 << 20); S++) {
    for (int i = 0; i < 20; i++) {
      if ((S & (1 << i)) == 0) {
        int sum = 0;
        for (int j = 0; j < 20; j++)
          if (S & (1 << j)) sum += cnt[j][i];
        dp[S | (1 << i)] = min(dp[S | (1 << i)], dp[S] + sum);
      }
    }
  }
  cout << dp[(1 << 20) - 1];
  return ~~(0 - 0);
}
