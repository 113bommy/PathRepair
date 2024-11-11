#include <bits/stdc++.h>
using namespace std;
vector<int> l(20);
vector<int> r(20);
char s[100005];
int n, m;
int amt[21][21];
long long mx = 1LL << 60;
int main() {
  scanf("%d %d %s", &n, &m, s);
  int sz = 1 << m;
  vector<long long> dp(sz, mx);
  dp[0] = 0;
  for (int i = 0; i < n - 1; ++i) {
    ++amt[s[i] - 'a'][s[i + 1] - 'a'];
    ++amt[s[i + 1] - 'a'][s[i] - 'a'];
  }
  for (int i = 1; i < sz; ++i) {
    long long sum = 0;
    for (int j = 0; j < m; ++j)
      if (1 << j & i)
        for (int k = 0; k < m; ++k) {
          if (!(1 << k & i)) sum += amt[j][k];
        }
    for (int j = 0; j < m; ++j)
      if (1 << j & i) dp[i] = min(dp[i], dp[i & ~(1 << j)] + sum);
  }
  printf("%lld", dp[sz - 1]);
  return 0;
}
