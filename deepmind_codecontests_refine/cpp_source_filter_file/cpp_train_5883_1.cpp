#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int lgput(int a, int b) {
  int ans = 1;
  for (int i = 0; (1 << i) <= b; ++i) {
    if ((1 << i) & b) ans = 1LL * ans * a % MOD;
    a = 1LL * a * a % MOD;
  }
  return ans;
}
void add(int &a, int b) {
  a += b;
  while (a >= MOD) a -= MOD;
  while (a < 0) a += MOD;
}
int main() {
  int n;
  cin >> n;
  vector<int> ways(n + 1, 0);
  ways[0] = 1;
  vector<vector<int>> Comb(n + 1, vector<int>(n + 1, 0));
  for (int i = 0; i <= n; ++i) {
    Comb[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      Comb[i][j] = (Comb[i - 1][j] + Comb[i - 1][j - 1]) % MOD;
  }
  vector<vector<int>> e(n + 1, vector<int>(n + 1, 0));
  e[1][1] = 1;
  for (int i = 2; i <= n; ++i)
    for (int j = 1; j <= i; ++j)
      e[i][j] = (e[i - 1][j - 1] + 1LL * e[i - 1][j] * j % MOD) % MOD;
  ways[0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= i; ++j) add(ways[i], e[i][j]);
  int ans = 0;
  for (int i = 1; i <= n; ++i) add(ans, (Comb[n][i] * ways[n - i] % MOD));
  cout << ans << "\n";
}
