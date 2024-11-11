#include <bits/stdc++.h>
using namespace std;
long long d[111111];
long long sum[111111];
int q[111111];
long long cat[111111];
long long dp[101][100001];
long long getDP(int i, int j, int k) {
  return (long long)j * cat[j] + dp[i - 1][k] - j * cat[k];
}
long long getUP(int i, int j, int k) {
  return (long long)dp[i - 1][j] - dp[i - 1][k];
}
long long getDOWN(int j, int k) { return (long long)cat[j] - cat[k]; }
int main() {
  int i, j, k, n, m, p, h;
  cin >> n >> m >> p;
  for (i = 2; i <= n; i++) {
    cin >> d[i];
    d[i] += d[i - 1];
  }
  for (i = 1; i <= m; i++) {
    cin >> h >> cat[i];
    cat[i] -= d[h];
  }
  sort(cat + 1, cat + 1 + m);
  for (i = 1; i <= m; i++) sum[i] = sum[i - 1] + cat[i];
  for (i = 1; i <= p; i++)
    for (j = 1; j <= m; j++) dp[i][j] = 999999999;
  dp[1][m] = (long long)m * cat[m] - sum[m];
  for (i = 2; i <= p; i++) {
    int head, tail;
    head = tail = 0;
    q[tail++] = m;
    for (j = m; j >= 1; j--) {
      while (head + 1 < tail && (getUP(i, q[head + 1], q[head]) <=
                                 j * getDOWN(q[head + 1], q[head])))
        head++;
      dp[i][j] = min(dp[i][j], getDP(i, j, q[head]));
      while (head + 1 < tail &&
             getUP(i, j, q[tail - 1]) * getDOWN(q[tail - 1], q[tail - 2]) >
                 getUP(i, q[tail - 1], q[tail - 2]) * getDOWN(j, q[tail - 1]))
        tail--;
      q[tail++] = j;
    }
  }
  long long ans = dp[p][1];
  for (i = 1; i <= m; i++) ans = min(ans, dp[p][i]);
  cout << ans << endl;
}
