#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 1;
const int MOD = 1e9 + 7;
inline int sum(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}
inline int sub(int a, int b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}
int dp[N];
int last[26];
int main() {
  int n, m, k;
  string t;
  cin >> n >> k >> t;
  m = (int)t.size();
  for (int c = 0; c < k; ++c) last[c] = 0;
  dp[0] = 1;
  for (int i = 1, c; i <= m; ++i) {
    c = t[i - 1] - 'a';
    dp[i] = sum(dp[i - 1], dp[i - 1]);
    if (last[c]) dp[i] = sub(dp[i], dp[last[c] - 1]);
    last[c] = i;
  }
  multiset<int> S;
  for (int i = 0; i < k; ++i) S.insert(last[i]);
  for (int i = m + 1, lst; i <= n + m; ++i) {
    lst = *S.begin();
    S.erase(S.begin());
    dp[i] = sum(dp[i - 1], dp[i - 1]);
    if (lst) dp[i] = sub(dp[i], dp[lst - 1]);
    S.insert(i);
  }
  printf("%d", dp[n + m]);
}
