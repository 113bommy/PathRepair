#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int p[5001], sump[5001];
long long memo[5001][5001];
long long solve(int n, int k) {
  if (k == 0) return 0;
  if (n < k * m) return 0;
  if (memo[n][k] != -1) return memo[n][k];
  long long ans =
      max(solve(n - 1, k), solve(n - m, k - 1) + sump[n] - sump[n - m]);
  memo[n][k] = ans;
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int(i) = 1; (i) <= (n); (i)++) {
    cin >> p[i];
    sump[i] = sump[i - 1] + p[i];
  }
  memset(memo, -1, sizeof(memo));
  long long ans = solve(n, k);
  cout << ans;
  return 0;
}
