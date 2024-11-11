#include <bits/stdc++.h>
using namespace std;
void read(int n, vector<int>& have) {
  for (int z = 0; z < n; z++) {
    int t;
    scanf("%d", &t);
    have[t]++;
  }
}
void game(vector<vector<long long> >& dp, vector<int>& have) {
  for (int z = 1; z <= 100000; z++) {
    dp[z][1] = dp[z - 1][0] + have[z] * z;
    dp[z][0] = max(dp[z - 1][0], dp[z - 1][1]);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> have(100001, 0);
  vector<vector<long long> > dp(100001, vector<long long>(2, 0));
  read(n, have);
  game(dp, have);
  cout << max(dp[100000][0], dp[100000][1]);
  return 0;
}
