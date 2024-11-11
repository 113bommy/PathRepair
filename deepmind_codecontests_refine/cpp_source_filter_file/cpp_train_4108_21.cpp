#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 5;
long long n, cnt[N], dp[N];
int solve() {
  scanf("%I64d", &n);
  vector<long long> a(n);
  for (long long& x : a) scanf("%I64d", &x), cnt[x]++;
  dp[0] = 0, dp[1] = 1;
  for (long long i = 2; i < N; i++)
    dp[i] = max(dp[i - 1], dp[i - 2] + i * cnt[i]);
  printf("%I64d", dp[N - 1]);
  return 0;
}
int main() { solve(); }
