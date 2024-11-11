#include <bits/stdc++.h>
using namespace std;
const int MN = 10000010;
vector<int> pr;
int pchk[MN];
void sieve() {
  for (int i = 2; i < MN; i++) {
    if (!pchk[i]) {
      pr.push_back(i);
      pchk[i] = i;
    }
    for (int j = 0; j < pr.size() && i * pr[j] < MN; j++) {
      pchk[i * pr[j]] = pr[j];
      if (i % pr[j] == 0) break;
    }
  }
}
int N;
long long dp[MN], ans;
int C[MN];
int main() {
  sieve();
  cin >> N;
  for (int i = N; i >= 1; i--) {
    dp[i] = 1LL * (N / i) * (N / i);
    for (int j = 2; i * j <= N; j++) {
      dp[i] -= dp[i * j];
    }
  }
  ans += (1LL * N * (N - 1) / 2) - dp[1] / 2;
  ans += dp[1] / 2 * 3;
  int cnt = 0;
  for (int i = 0; i < pr.size(); i++) {
    if (pr[i] > N) break;
    if (pr[i] > N / 2) cnt++;
  }
  ans -= 3LL * (N - 2) * cnt - 3LL * cnt * (cnt - 1) / 2;
  ans -= 3 * (N - 1);
  for (int i = 2; i <= N; i++) {
    if (pchk[i]) C[pchk[i]]++;
  }
  long long x = 0;
  for (int i = 0; i < pr.size(); i++) {
    for (int j = i; j < pr.size(); j++) {
      if (1LL * pr[i] * pr[j] > N) break;
      if (i == j)
        x += 1LL * C[pr[i]] * (C[pr[i]] - 1) / 2;
      else
        x += 1LL * C[pr[i]] * C[pr[j]];
    }
  }
  ans -= x - (1LL * N * (N - 1) / 2 - dp[1] / 2);
  printf("%lld", ans);
}
