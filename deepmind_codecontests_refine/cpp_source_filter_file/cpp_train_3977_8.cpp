#include <bits/stdc++.h>
using namespace std;
const int max_n = 205;
const int inf = 1e9;
const long long mx = LLONG_MAX;
int n, m;
long long k;
int a[max_n][max_n];
int md[max_n];
long long dp[max_n][max_n][2], mdp[max_n][max_n], rdp[max_n][max_n][2],
    mrdp[max_n][max_n];
pair<int, int> P[max_n];
bool b[max_n], s[max_n];
int dx[2] = {-1, 1};
char res[max_n][max_n];
int main() {
  scanf("%d%d", &n, &m);
  cin >> k;
  int N = n + m - 1;
  for (int i = 0; i < N; i++) md[i] = inf;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
      md[i + j] = min(md[i + j], a[i][j]);
    }
  for (int i = 0; i < N; i++) P[i] = make_pair(md[i], i);
  sort(P, P + N);
  for (int z = 0; z < N; z++) {
    int ind = P[z].second + 1;
    for (int i = 0; i <= N; i++)
      for (int j = 0; j <= N; j++) {
        mdp[i][j] = 0;
        mrdp[i][j] = 0;
        dp[i][j][0] = 0;
        dp[i][j][1] = 0;
        rdp[i][j][0] = 0;
        rdp[i][j][1] = 0;
      }
    mdp[0][0] = 1;
    mrdp[N + 1][0] = 1;
    for (int i = 1; i <= N; i++)
      for (int j = 0; j <= i; j++) {
        if (b[i] and j + dx[s[i]] >= 0 and j + dx[s[i]] < i)
          dp[i][j][s[i]] = mdp[i - 1][j + dx[s[i]]];
        else if (!b[i]) {
          dp[i][j][0] = ((j > 0) ? mdp[i - 1][j - 1] : 0);
          dp[i][j][1] = ((j < i - 1) ? mdp[i - 1][j + 1] : 0);
        }
        long long t1 = rdp[i][j][0], t2 = rdp[i][j][1];
        mdp[i][j] = (mx - t1 < t2) ? mx : dp[i][j][0] + dp[i][j][1];
      }
    for (int i = N; i >= 1; i--)
      for (int j = 0; j <= N - i + 1; j++) {
        if (b[i] and j - dx[s[i]] >= 0 and j - dx[s[i]] < N - i + 1)
          rdp[i][j][s[i]] = mrdp[i + 1][j - dx[s[i]]];
        else if (!b[i]) {
          rdp[i][j][1] = ((j > 0) ? mrdp[i + 1][j - 1] : 0);
          rdp[i][j][0] = ((j < N - i) ? mrdp[i + 1][j + 1] : 0);
        }
        long long t1 = rdp[i][j][0], t2 = rdp[i][j][1];
        mrdp[i][j] = (mx - t1 < t2) ? mx : rdp[i][j][0] + rdp[i][j][1];
      }
    long long nways = 0ll;
    bool overflow = 0;
    for (int j = 1; j <= ind; j++) {
      long long t1 = dp[ind][j][0], t2 = rdp[ind][j - 1][0];
      if (t1 > 0 and (mx / t1 < t2 or mx - t1 * t2 < nways)) {
        overflow = 1;
        break;
      }
      nways += dp[ind][j][0] * rdp[ind][j - 1][0];
    }
    if (overflow or nways >= k)
      s[ind] = 0;
    else {
      s[ind] = 1;
      k -= nways;
    }
    b[ind] = 1;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) res[i][j] = (s[i + j + 1] == 0) ? '(' : ')';
  for (int i = 0; i < n; i++) printf("%s\n", res[i]);
  return 0;
}
