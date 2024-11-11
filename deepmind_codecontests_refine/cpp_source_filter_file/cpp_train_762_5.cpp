#include <bits/stdc++.h>
const int N = 1000100;
const long long mod = 1000000007;
char s[N];
long long DPnB[N][3], DPnW[N][3], DP[N];
int sumX[N];
bool okB[N], okW[N];
long long pow(int a) {
  long long ans = 1, tmp = 2;
  while (a) {
    if (a & 1) ans = (ans * tmp) % mod;
    tmp = (tmp * tmp) % mod;
    a >>= 1;
  }
  return ans;
}
long long rpow(int a) { return pow(mod - 1 - a); }
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  scanf("%s", &s[1]);
  if (k * 2 > n) {
    puts("0");
    return 0;
  }
  for (int i = 1; i <= n; i++)
    if (s[i] == 'X')
      sumX[i] = sumX[i - 1] + 1;
    else
      sumX[i] = sumX[i - 1];
  for (int i = 1; i + k - 1 <= n; i++) {
    bool fail = false;
    for (int j = i; j < k + i; j++)
      if (s[i] == 'W') {
        fail = true;
        i = j;
        break;
      }
    if (fail) continue;
    while (i + k - 1 <= n && s[i + k - 1] != 'W') okB[i++] = true;
    i = i + k - 1;
  }
  for (int i = n; i - k + 1 >= 1; i--) {
    bool fail = false;
    for (int j = i; j >= i - k + 1; j--)
      if (s[i] == 'B') {
        fail = true;
        i = j;
        break;
      }
    if (fail) continue;
    while (i - k + 1 >= 1 && s[i - k + 1] != 'B') okW[i--] = true;
    i = i - k + 1;
  }
  DPnB[0][0] = DPnB[0][1] = DPnB[0][2] = 1;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'B') {
      DPnB[i][1] = 0;
      if (i >= k && okB[i - k + 1])
        DPnB[i][0] = (DPnB[i - 1][2] - DPnB[i - k][1] + mod) % mod;
      else
        DPnB[i][0] = DPnB[i - 1][2];
    } else if (s[i] == 'W') {
      DPnB[i][0] = 0;
      DPnB[i][1] = DPnB[i - 1][2];
    } else {
      if (i >= k && okB[i - k + 1])
        DPnB[i][0] = (DPnB[i - 1][2] - DPnB[i - k][1] + mod) % mod;
      else
        DPnB[i][0] = DPnB[i - 1][2];
      DPnB[i][1] = DPnB[i - 1][2];
    }
    DPnB[i][2] = (DPnB[i][0] + DPnB[i][1]) % mod;
  }
  DPnW[n + 1][0] = DPnW[n + 1][1] = DPnW[n + 1][2] = 1;
  for (int i = n; i >= 1; i--) {
    if (s[i] == 'W') {
      DPnW[i][0] = 0;
      if (i + k - 1 <= n && okW[i + k - 1])
        DPnW[i][1] = (DPnW[i + 1][2] - DPnW[i + k][0] + mod) % mod;
      else
        DPnW[i][1] = DPnW[i + 1][2];
    } else if (s[i] == 'B') {
      DPnW[i][0] = DPnW[i + 1][2];
      DPnW[i][1] = 0;
    } else {
      if (i + k - 1 <= n && okW[i + k - 1])
        DPnW[i][1] = (DPnW[i + 1][2] - DPnW[i + k][0] + mod) % mod;
      else
        DPnW[i][1] = DPnW[i + 1][2];
      DPnW[i][0] = DPnW[i + 1][2];
    }
    DPnW[i][2] = (DPnW[i][0] + DPnW[i][1]) % mod;
  }
  long long ans = 0;
  for (int j = n; j >= k; j--)
    if (okW[j])
      DP[j] = (DP[j + 1] + DPnW[j + 1][0] * pow(sumX[j - k])) % mod;
    else
      DP[j] = DP[j + 1];
  for (int i = 1; i + k + k - 1 <= n; i++)
    if (okB[i])
      ans = (((DPnB[i - 1][1] * rpow(sumX[i + k - 1])) % mod) *
                 DP[i + k + k - 1] +
             ans) %
            mod;
  printf("%I64d\n", ans);
  scanf(" ");
}
