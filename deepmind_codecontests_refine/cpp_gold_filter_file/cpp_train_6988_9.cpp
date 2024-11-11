#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int arr[20][10005];
int brr[20][20];
int crr[20][20];
int n, m;
int dp[1 << 17][18][18];
int cal(int x, int y) {
  if (x == y) return 0;
  int ans = int(1000000007);
  for (int i = 1; i <= m; i++) {
    ans = min(ans, abs(arr[x][i] - arr[y][i]));
  }
  return ans;
}
int sol(int num, int st, int end) {
  if (dp[num][st][end] != -1) return dp[num][st][end];
  int bin[18] = {0};
  int bit = 0;
  int x = num / 2;
  int pos = 1;
  int ct = 0;
  while (x != 0) {
    bit = x % 2;
    ct += bit;
    bin[pos] = bit;
    x /= 2;
    pos++;
  }
  if (ct == 2) {
    return dp[num][st][end] = brr[st][end];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (bin[i] == 0 || i == end || i == st) continue;
    int inc = 1 << (st);
    ans = max(min(sol(num - inc, i, end), brr[st][i]), ans);
  }
  return dp[num][st][end] = ans;
}
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
    }
  }
  int ans = 0;
  if (n == 1) {
    ans = int(1000000007);
    for (int i = 1; i < m; i++) {
      ans = min(ans, abs(arr[1][i + 1] - arr[1][i]));
    }
    cout << ans << endl;
    return 0;
  }
  if (n == 2) {
    ans = int(1000000007);
    for (int i = 1; i <= m; i++) {
      ans = min(ans, abs(arr[1][i] - arr[2][i]));
    }
    int a1 = int(1000000007);
    int a2 = int(1000000007);
    for (int i = 1; i < m; i++) {
      a1 = min(a1, abs(arr[1][i] - arr[2][i + 1]));
    }
    for (int i = 1; i < m; i++) {
      a2 = min(a2, abs(arr[1][i + 1] - arr[2][i]));
    }
    cout << max(min(ans, a1), min(ans, a2)) << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      ans = int(1000000007);
      for (int k = 1; k < m; k++) {
        ans = min(ans, abs(arr[i][k + 1] - arr[j][k]));
      }
      crr[i][j] = ans;
    }
  }
  ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      brr[i][j] = cal(i, j);
    }
  }
  int num = 0;
  for (int i = 1; i <= n; i++) {
    num += 1 << i;
  }
  ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      ans = max(ans, min(sol(num, i, j), crr[i][j]));
    }
  }
  cout << ans << endl;
  return 0;
}
