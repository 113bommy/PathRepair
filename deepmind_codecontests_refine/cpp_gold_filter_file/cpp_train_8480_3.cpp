#include <bits/stdc++.h>
using namespace std;
long long gem[30005] = {};
long long dp[30005][505];
long long n, d;
bool used[30005][505] = {};
long long cal(long long pos, long long j) {
  long long res;
  long long jj = j - (d - 250);
  if (pos >= 30001) return 0;
  if (dp[pos][jj] != -1) return dp[pos][jj];
  used[pos][jj] = 1;
  if (j == 1)
    res = max(cal(pos + j, j), cal(pos + j + 1, j + 1));
  else
    res = max(cal(pos + j - 1, j - 1),
              max(cal(pos + j, j), cal(pos + j + 1, j + 1)));
  dp[pos][jj] = res + gem[pos];
  return dp[pos][jj];
}
int main() {
  cin >> n >> d;
  int t;
  for (long long i = 0; i <= 30004; i++)
    for (long long j = 0; j <= 502; j++) dp[i][j] = -1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t);
    gem[t]++;
  }
  cout << cal(d, d) << endl;
  return 0;
}
