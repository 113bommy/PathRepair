#include <bits/stdc++.h>
using namespace std;
vector<long long> tab;
int n, k;
bitset<60> dp[60];
bool check(long long val) {
  for (int i = 0; i <= n; ++i) dp[i].reset();
  dp[0][0] = 1;
  for (int i = 1; i <= k; ++i) {
    for (int s = 1; s <= n; ++s) {
      if (!dp[s - 1][i - 1]) continue;
      for (int j = s; j <= n; ++j) {
        long long sum = tab[j] - tab[s - 1];
        if ((sum & val) == val) dp[j][i] = 1;
      }
    }
  }
  return dp[n][k];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  tab.resize(n + 1);
  for (int i = 1; i <= n; ++i) {
    long long a;
    cin >> a;
    tab[i] = tab[i - 1] + a;
  }
  long long res = 0;
  for (int i = 60; i >= 0; --i) {
    if (check(res + (1LL << i))) res |= 1LL << i;
  }
  cout << res;
  return 0;
}
