#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 9;
const int MOD = 1e9 + 7;
long long vec[12], dp[12][12], lucky[12];
long long ans, p;
void update(int pos, int now, int maxn, long long int cur) {
  if (now >= maxn) return;
  if (pos == 7) {
    ans = (ans + cur) % MOD;
    return;
  }
  for (int i = 0; i < maxn; i++) {
    if (lucky[i]) {
      lucky[i]--;
      update(pos + 1, now + i, maxn, (cur * (lucky[i] + 1) % MOD) % MOD);
      lucky[i]++;
    }
  }
}
long long int dfs(int pos, int res, int limit) {
  long long int sum = 0;
  if (pos == 0) return res == 0;
  if (!limit && dp[pos][res] != -1) return dp[pos][res];
  int lit = limit ? vec[p] : 9;
  for (int i = 0; i <= lit; i++) {
    sum += dfs(pos - 1, res - (i == 4 || i == 7), limit && (i == lit));
  }
  if (!limit) dp[pos][res] = sum;
  return sum;
}
int main() {
  long long int N;
  while (cin >> N) {
    p = 0;
    ans = 0;
    memset(vec, 0, sizeof(vec));
    memset(dp, -1, sizeof(dp));
    while (N) {
      vec[++p] = N % 10;
      N /= 10;
    }
    for (int i = 0; i <= p; i++) {
      lucky[i] = dfs(p, i, 1);
    }
    lucky[0]--;
    for (int i = 0; i <= p; i++) {
      update(1, 0, i, lucky[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
