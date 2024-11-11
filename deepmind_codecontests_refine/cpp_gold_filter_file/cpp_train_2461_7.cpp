#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int a[708];
long long sum[708];
long long dp[708][708][10][2];
void add(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
}
long long dfs(int pos, int num, int digit, int limit) {
  if (num < 0) return 0;
  if (pos == 0) return (num == 0);
  if (dp[pos][num][digit][limit] != -1) return dp[pos][num][digit][limit];
  long long ans = 0;
  int top = limit ? a[pos] : 9;
  for (int i = 0; i <= top; i++) {
    add(ans, dfs(pos - 1, num - (i >= digit), digit, limit & (i == top)));
  }
  return dp[pos][num][digit][limit] = ans;
}
int main() {
  string s;
  cin >> s;
  int len = s.size();
  long long cnt = 0;
  for (int i = 0; s[i]; i++) {
    a[len - i] = s[i] - '0';
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= 700; i++) {
    sum[i] = (sum[i - 1] * 10 + 1) % mod;
  }
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= len; j++) {
      add(cnt, dfs(len, j, i, 1) * sum[j] % mod);
    }
  }
  printf("%lld\n", cnt);
}
