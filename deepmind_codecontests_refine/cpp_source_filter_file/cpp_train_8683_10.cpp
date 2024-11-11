#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
long long n;
long long dp[3][150001];
long long a[301], b[301], t[301];
long long m;
long long d;
long long minf = INF;
long long g;
void RMQ(long long p, long long l) {
  long long que[150001];
  long long s = 1;
  long long t = 0;
  for (int i = 1; i <= (l); i++) {
    while (s <= t && dp[1][que[t]] >= dp[1][i]) {
      t--;
    }
    que[++t] = i;
  }
  for (int i = 1; i <= (n); i++) {
    if (i + l <= n) {
      while (s <= t && dp[1][que[t]] >= dp[1][i + l]) {
        t--;
      }
      que[++t] = i + l;
    }
    if (i - l - 1 >= 1) {
      if (que[s] == i - l - 1) {
        s++;
      }
    }
    dp[2][i] = abs(i - a[p]) + dp[1][que[s]];
  }
}
int main() {
  cin >> n >> m >> d;
  long long pt = 1;
  for (int i = 1; i <= (m); i++) {
    cin >> a[i] >> b[i] >> t[i];
    t[i] -= pt;
    pt += t[i];
    g += b[i];
  }
  for (int i = 1; i <= (m); i++) {
    RMQ(i, t[i] * d < n ? t[i * d] : n);
    for (int j = 1; j <= (n); j++) {
      dp[1][j] = dp[2][j];
    }
  }
  for (int i = 1; i <= (n); i++) {
    minf = min(minf, dp[2][i]);
  }
  cout << g - minf;
  return 0;
}
