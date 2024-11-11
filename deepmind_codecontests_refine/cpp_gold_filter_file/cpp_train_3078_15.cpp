#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
struct T {
  int a, b, i;
  T() {}
  T(int a, int b, int i) : a(a), b(b), i(i) {}
  bool operator<(const T &other) const { return a > other.a; }
};
const int inf = 1e9;
int n, m, k, dp[N][N], f[N][N];
T a[N];
vector<int> ga, gb;
int fsolve(int i, int j) {
  if (f[i][j] != -1) return f[i][j];
  if (i > n) {
    if (j == k)
      f[i][j] = 0;
    else
      f[i][j] = -inf;
    return f[i][j];
  }
  f[i][j] = fsolve(i + 1, j);
  if (j < k) f[i][j] = max(f[i][j], fsolve(i + 1, j + 1) + a[i].b);
  if (f[i][j] < 0) f[i][j] = -inf;
  return f[i][j];
}
int solve(int i, int j) {
  if (dp[i][j] != -1) return dp[i][j];
  if (i > n) {
    if (j == m)
      dp[i][j] = 0;
    else
      dp[i][j] = -inf;
    return dp[i][j];
  }
  int p = i - 1 - j;
  if (j == m) {
    dp[i][j] = fsolve(i, p);
    return dp[i][j];
  }
  dp[i][j] = solve(i + 1, j + 1) + a[i].a;
  if (p != k) dp[i][j] = max(dp[i][j], solve(i + 1, j) + a[i].b);
  if (dp[i][j] < 0) dp[i][j] = -inf;
  return dp[i][j];
}
void fsolve1(int i, int j) {
  if (i > n) {
    return;
  }
  if (f[i][j] == f[i + 1][j])
    fsolve1(i + 1, j);
  else {
    gb.push_back(a[i].i);
    fsolve1(i + 1, j + 1);
  }
}
void solve1(int i, int j) {
  if (i > n) {
    return;
  }
  int p = i - 1 - j;
  if (j == m) {
    fsolve1(i, p);
    return;
  }
  if (dp[i][j] == dp[i + 1][j + 1] + a[i].a) {
    ga.push_back(a[i].i);
    solve1(i + 1, j + 1);
  } else {
    gb.push_back(a[i].i);
    solve1(i + 1, j);
  }
}
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) cin >> a[i].a;
  for (int i = 1; i <= n; i++) cin >> a[i].b;
  for (int i = 1; i <= n; i++) a[i].i = i;
  sort(a + 1, a + n + 1);
  memset(f, -1, sizeof(f));
  memset(dp, -1, sizeof(dp));
  cout << solve(1, 0) << endl;
  solve1(1, 0);
  for (int i = 0; i < ga.size(); i++) cout << ga[i] << " ";
  cout << endl;
  for (int i = 0; i < gb.size(); i++) cout << gb[i] << " ";
  cout << endl;
  return 0;
}
