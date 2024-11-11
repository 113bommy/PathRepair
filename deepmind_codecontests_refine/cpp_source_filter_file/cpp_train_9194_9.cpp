#include <bits/stdc++.h>
using namespace std;
void sc(char& c) {
  char temp[4];
  scanf("%s", temp);
  c = temp[0];
}
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
int testnum;
char str[105];
long long dp[3005][105];
const long long mod = 1000000007;
void preprocess() {
  memset(dp, 0, sizeof dp);
  for (int i = 0; i < 3005; i++) dp[i][0] = 1;
  for (int i = 1; i < 3000; i++)
    for (int j = 0; j <= i && j <= 100; j++)
      dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
}
long long get(int k, int n) {
  if (k < 0) return 0;
  return dp[k + n - 1][n - 1];
}
void solve() {
  int n = strlen(str);
  int k = 0;
  for (int i = 0; i < n; i++) k += str[i] - 'a';
  long long ans = mod - 1;
  for (int i = 0; i <= n; i++) {
    long long term = (dp[n][i] * get(k - 26 * i, n)) % mod;
    if (i & 1)
      ans = (ans + mod - term) % mod;
    else
      ans = (ans + term) % mod;
  }
  printf("%d\n", (int)ans);
}
bool input() {
  scanf("%s", str);
  return true;
}
int main() {
  preprocess();
  int T;
  scanf("%d", &T);
  for (testnum = 1; testnum <= T; testnum++) {
    input();
    solve();
  }
}
