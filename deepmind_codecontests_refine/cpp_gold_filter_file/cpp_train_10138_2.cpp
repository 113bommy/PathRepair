#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int M = 1e6 + 20;
const int N = 2e5 + 20;
long long n, y, ans;
long long a[N], dp[N][2];
bool flag;
long long dfs(long long x, long long c) {
  if (x <= 0 || x > n) return 0;
  if (dp[x][c]) return dp[x][c];
  dp[x][c] = -1;
  long long tmp;
  if (c == 1)
    tmp = dfs(x + a[x], 0);
  else
    tmp = dfs(x - a[x], 1);
  if (tmp == -1) return -1;
  return dp[x][c] = a[x] + tmp;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> a[i];
  }
  for (long long i = 1; i < n; i++) {
    a[1] = i;
    dp[1][1] = 0;
    cout << dfs(1, 1) << endl;
  }
  return 0;
}
