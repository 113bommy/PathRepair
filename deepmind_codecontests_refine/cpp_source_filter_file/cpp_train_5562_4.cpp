#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int k, ans, dp[35][35][2];
void Add(int &x, int y) { x = (x + y) % p; }
void Del(int &x, int y) { x = (x - y) % p; }
void Mul(int &x, int y) { x = (long long)x * y % p; }
int add(int x, int y) { return (x + y) % p; }
int del(int x, int y) { return (x - y) % p; }
int mul(int x, int y) { return (long long)x * y % p; }
int main() {
  scanf("%d", &k);
  dp[30][0][1] = 1;
  for (int i = 30; i >= 0; --i)
    for (int j = 0; j <= 30; ++j) {
      Add((!i) ? ans : dp[i - 1][j + 1][0], dp[i][j][0]);
      Add((!i) ? ans : dp[i - 1][j][0], mul(dp[i][j][0], 1 << j));
      int e = (!j) ? 1 : (1 << j - 1);
      int o = (!j) ? 0 : (1 << j - 1);
      if (!((k >> i) & 1))
        Add((!i) ? ans : dp[i - 1][j][1], mul(e, dp[i][j][1]));
      else {
        Add((!i) ? ans : dp[i - 1][j][0], mul(e, dp[i][j][1]));
        Add((!i) ? ans : dp[i - 1][j + 1][1], mul(e, dp[i][j][1]));
        Add((!i) ? ans : dp[i - 1][j][1], mul(o, dp[i][j][1]));
      }
    }
  ans = (ans % p + p) % p;
  printf("%d\n", ans);
  return 0;
}
