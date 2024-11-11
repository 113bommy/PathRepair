#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e13;
long long dp[5100][60], go[5100][60], n, can[60];
pair<long long, long long> ar[5010];
long long rec(long long i) {
  if (ar[i].first != ar[i + 1].first)
    return i;
  else
    return rec(i + 1);
}
int main() {
  ios::sync_with_stdio(false);
  int sum = 0;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> ar[i].first;
  for (long long i = 1; i <= n; i++) cin >> ar[i].second, sum += ar[i].second;
  sort(ar + 1, ar + n + 1,
       [](pair<long long, long long> x, pair<long long, long long> y) {
         if (x.first == y.first)
           return x.second > y.second;
         else
           return x.first > y.first;
       });
  for (long long i = 1; i <= n; i++) can[i] = rec(i);
  for (long long i = 0; i <= sum + 1; i++) {
    for (long long j = 0; j <= 60 - 1; j++) {
      go[i][j] = dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 0; j <= sum + 1; j++) {
      for (long long k = 0; k <= 51; k++) {
        long long v = (can[i] - i) + 1, np = 0, nc = 0, tim = 0;
        if (k >= v)
          go[j + np][k + nc - v] = min(go[j + np][k + nc - v], dp[j][k] + tim);
        for (long long l = i; l <= can[i]; l++) {
          np += ar[l].second;
          nc++;
          tim += ar[l].first;
          v--;
          if (k >= v)
            go[j + np][k + nc - v] =
                min(go[j + np][k + nc - v], dp[j][k] + tim);
        }
      }
    }
    for (long long i = 0; i <= sum + 1; i++) {
      for (long long j = 0; j <= 51; j++) {
        dp[i][j] = go[i][j];
        go[i][j] = INF;
      }
    }
    i = can[i];
  }
  long long prin = INF;
  for (long long i = 1; i <= sum + 1; i++) {
    for (long long j = 0; j <= 51; j++) {
      double ck = (double)dp[i][j] / i;
      ck *= 1000;
      long long ok = ck;
      if (ck != (double)ok) ok++;
      if (dp[i][j] != INF) prin = min(prin, ok);
    }
  }
  cout << prin << endl;
  return 0;
}
