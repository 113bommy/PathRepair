#include <bits/stdc++.h>
using namespace std;
long long dp[55][55][55][3];
int mod = 1e9 + 7;
long long DP(int a, int b, int c, int op) {
  if (a < 0 || b < 0 || c < 0) return 0;
  if (dp[a][b][c][op] != -1) return dp[a][b][c][op];
  if (op == 0) {
    dp[a][b][c][op] = (DP(a, b - 1, c, 1) * b + DP(a, b, c - 1, 2) * c) % mod;
  } else if (op == 1) {
    dp[a][b][c][op] = (DP(a - 1, b, c, 0) * a + DP(a, b, c - 1, 2) * c) % mod;
  } else if (op == 2) {
    dp[a][b][c][op] = (DP(a - 1, b, c, 0) * a + DP(a, b - 1, c, 1) * b) % mod;
  }
  return dp[a][b][c][op];
}
int cnt[2500][24000];
int number[55][55][55];
int inv[24000][3];
vector<int> v[2500];
int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  int index = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 0; j + k <= i; k++) {
        number[j][k][i - j - k] = index;
        inv[index][0] = j;
        inv[index][1] = k;
        inv[index][2] = i - j - k;
        index++;
      }
    }
  }
  memset(cnt, -1, sizeof(cnt));
  cnt[0][0] = 1;
  v[0].push_back(0);
  int tot = 0;
  for (int i = 0; i < n; i++) {
    int first, second;
    scanf("%d %d", &first, &second);
    for (int j = tot; j >= 0; j--) {
      for (int k : v[j]) {
        int a, b, c;
        a = inv[k][0], b = inv[k][1], c = inv[k][2];
        if (a + b + c > i) break;
        if (second == 1) a++;
        if (second == 2) b++;
        if (second == 3) c++;
        int num = number[a][b][c];
        if (cnt[j + first][num] == -1) {
          v[j + first].push_back(num);
          cnt[j + first][num] = 0;
        }
        cnt[j + first][num] += cnt[j][k];
        cnt[j + first][num] %= mod;
      }
    }
    tot += first;
  }
  long long ans = 0;
  memset(dp, -1, sizeof(dp));
  dp[0][0][0][0] = dp[0][0][0][1] = dp[0][0][0][2] = 1;
  for (int k : v[t]) {
    int a, b, c;
    a = inv[k][0], b = inv[k][1], c = inv[k][2];
    ans += (long long)cnt[t][k] *
           (DP(a - 1, b, c, 0) * a % mod + DP(a, b - 1, c, 1) * b % mod +
            DP(a, b, c - 1, 2) * c % mod) %
           mod;
  }
  printf("%lld\n", ans % mod);
}
