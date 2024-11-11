#include <bits/stdc++.h>
using namespace std;
const int sz = 2e3 + 9;
int n, k;
string str;
int a[sz];
int dp[sz][sz][10], t2;
bool done[sz][sz];
string val[10] = {"1110111", "0010010", "1011101", "1011011", "0111010",
                  "1101011", "1101111", "1010010", "1111111", "1111011"};
int vi[10];
int who[sz];
string tmp = "0";
void print_sol(int idx, int rem, int V) {
  if (idx == n) return;
  cout << V;
  int d = vi[V] ^ a[idx];
  int cost = __builtin_popcount(d);
  for (int i = 9; i >= 0; i--) {
    if (dp[idx][rem][V] == V + dp[idx + 1][rem - cost][i]) {
      print_sol(idx + 1, rem - cost, i);
      return;
    }
  }
}
int main() {
  scanf("%d %d ", &n, &k);
  for (int i = 0; i < n; i++) {
    cin >> str;
    for (int j = 0; j < 7; j++) {
      if (str[j] == '1') a[i] += (1 << j);
    }
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 7; j++) {
      if (val[i][j] == '1') vi[i] += (1 << j);
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int I = 0; I < 10; I++) {
        dp[i][j][I] = -1e7;
      }
    }
  }
  for (int i = 0; i < 10; i++) {
    dp[n][0][i] = i;
  }
  for (int idx = n - 1; idx >= 0; idx--) {
    for (int j = 0; j <= k; j++) {
      for (int i = 0; i < 10; i++) {
        int d = vi[i] ^ a[idx];
        if (d & a[idx]) continue;
        int cost = __builtin_popcount(d);
        if (cost > j) continue;
        for (int I = 9; I >= 0; I--) {
          dp[idx][j][i] = max(dp[idx][j][i], i + dp[idx + 1][j - cost][I]);
          if (dp[idx][j][i] > 0) break;
        }
      }
    }
  }
  for (int i = 9; i >= 0; i--) {
    if (dp[0][k][i] >= 0) {
      print_sol(0, k, i);
      return 0;
    }
  }
  cout << -1;
  return 0;
}
