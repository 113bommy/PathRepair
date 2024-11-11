#include <bits/stdc++.h>
using namespace std;
int t, n, k, ans1, ans2;
char x;
int a[2222];
int f[300][300];
int c[12];
int b[12];
int d[300];
int need[2222];
void dfs(int u) {
  for (int i = 0; i < 7; i++)
    if (((u >> i) & 1) == 0 && d[u ^ (1 << i)] == -1) {
      d[u ^ (1 << i)] = d[u] + 1;
      dfs(u ^ (1 << i));
    }
}
int dp[2222][2222];
int dequy(int stt, int conlai) {
  if (dp[stt][conlai] != -2) return dp[stt][conlai];
  if (stt == n + 1) {
    if (conlai == 0) return 0;
    return -1;
  }
  dp[stt][conlai] = -1;
  for (int i = 9; i >= 0; i--)
    if (f[a[stt]][i] != -1 && conlai >= f[a[stt]][i]) {
      if (dequy(stt + 1, conlai - f[a[stt]][i]) != -1) {
        dp[stt][conlai] = i;
        break;
      }
    }
  return dp[stt][conlai];
};
void in(int i, int k) {
  if (i == n + 1) return;
  cout << dp[i][k];
  in(i + 1, k - f[a[i]][dp[i][k]]);
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    a[i] = 0;
    for (int j = 0; j < 7; j++) {
      cin >> x;
      if (x == '1') a[i] ^= (1 << j);
    }
  }
  for (int i = 0; i <= 200; i++)
    for (int j = 0; j <= 200; j++) f[i][j] = -1;
  for (int i = 1; i < 128; i++) d[i] = -1;
  d[0] = 0;
  dfs(0);
  b[0] = 119;
  b[1] = (1 << 2) ^ (1 << 5);
  b[2] = (1 << 0) ^ (1 << 2) ^ (1 << 3) ^ (1 << 4) ^ (1 << 6);
  b[3] = (1 << 0) ^ (1 << 2) ^ (1 << 3) ^ (1 << 5) ^ (1 << 6);
  b[4] = (1 << 1) ^ (1 << 2) ^ (1 << 3) ^ (1 << 5);
  b[5] = (1 << 0) ^ (1 << 1) ^ (1 << 3) ^ (1 << 5) ^ (1 << 6);
  b[6] = (1 << 0) ^ (1 << 1) ^ (1 << 3) ^ (1 << 4) ^ (1 << 5) ^ (1 << 6);
  b[7] = (1 << 0) ^ (1 << 2) ^ (1 << 5);
  b[8] = b[6] ^ (1 << 2);
  b[9] = b[4] ^ 1 ^ (1 << 6);
  c[0] = 6;
  c[1] = 2;
  c[2] = 5;
  c[3] = 5;
  c[4] = 4;
  c[5] = 5;
  c[6] = 6;
  c[7] = 3;
  c[8] = 7;
  c[9] = 6;
  for (int i = 0; i < 128; i++) {
    for (int j = 0; j <= 9; j++)
      if ((i | b[j]) == b[j]) {
        f[i][j] = c[j] - d[i];
      }
  }
  for (int i = 0; i <= 2000; i++)
    for (int j = 0; j <= 2000; j++) dp[i][j] = -2;
  if (dequy(1, k) == -1)
    cout << "-1";
  else
    in(1, k);
  return 0;
}
