#include <bits/stdc++.h>
using namespace std;
std::mt19937 rng(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
const double EPS = 1e-9;
const double PI = acos(-1);
const int MOD = 1000000007;
const int MAXN = 12;
int mat[MAXN][MAXN];
int mat2[MAXN][MAXN];
int jump[110];
double dp[110][2];
bool calc[110][2];
double solve(int u, bool p) {
  if (u == 100) return 0;
  if (calc[u][p]) return dp[u][p];
  if (jump[u] and p) {
    double ans = 0;
    for (int i = 1; i <= 6; i++) ans += (solve(u + i, true) + 1) / 6.0;
    dp[u][p] = min(ans, solve(jump[u], false) + 1.0);
    calc[u][p] = true;
    return dp[u][p];
  } else {
    double ans = 0;
    int k = 0;
    for (int i = 1; i <= 6; i++) {
      if (u + i <= 100)
        ans += (solve(u + i, true) + 1) / 6.0;
      else {
        k++;
        if (!p)
          ans += (solve(u, true) + 1) / 6.0;
        else
          ans += 1 / 6.0;
      }
    }
    if (!p)
      dp[u][p] = ans;
    else
      dp[u][p] = ans / (1.0 - (k / 6.0));
    calc[u][p] = true;
    return dp[u][p];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> mat[i][j];
    }
  }
  int v = 100;
  for (int i = 0; i < 10; i++) {
    if (i & 1)
      for (int j = 9; j >= 0; j--) mat2[i][j] = v--;
    else
      for (int j = 0; j < 10; j++) mat2[i][j] = v--;
  }
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      if (mat[i][j]) jump[mat2[i][j]] = mat2[i - mat[i][j]][j];
  cout << fixed << setprecision(12) << solve(1, true) << '\n';
  return 0;
}
