#include <bits/stdc++.h>
using namespace std;
int n, m, k, z = 0;
char kkk[105][105];
long long s[105][105];
long long dp[101][101][12];
bool vis[101][101][12];
string l = "";
long long solve(int i, int j, long long sum) {
  if (j < 0 || j >= m) return -1e9;
  if (i == 0) {
    if (((sum + s[i][j]) % k) == 0) {
      return (s[i][j]);
    } else
      return -1e9;
  }
  if (vis[i][j][sum % k]) return dp[i][j][sum % k];
  vis[i][j][sum % k] = true;
  long long t = s[i][j] + max(solve(i - 1, j - 1, (sum + s[i][j]) % k),
                              solve(i - 1, j + 1, (sum + s[i][j]) % k));
  return dp[i][j][sum % k] = t;
}
void trace(int i, int j, long long sum) {
  if (i == 0) return;
  if (solve(i - 1, j - 1, (sum + s[i][j]) % k) >
      solve(i - 1, j + 1, (sum + s[i][j]) % k)) {
    l += "L";
    trace(i - 1, j - 1, (sum + s[i][j]) % k);
  } else {
    l += "R";
    trace(i - 1, j + 1, (sum + s[i][j]) % k);
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  k++;
  for (int i = 0; i < n; i++) cin >> kkk[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) s[i][j] = kkk[i][j] - '0';
  long long ans = -1, ind = -1;
  for (int i = 0; i < m; i++) {
    long long hamada = solve(n - 1, i, 0);
    if (hamada > ans) {
      ans = hamada;
      ind = i;
    }
  }
  if (ans < 0)
    return cout << -1, 0;
  else {
    cout << ans << endl << (ind + 1) << endl;
    trace(n - 1, ind, 0);
    cout << l << endl;
  }
  return 0;
}
