#include <bits/stdc++.h>
using namespace std;
const int mod97 = 100000000;
long long expo(long long p, long long q) {
  long long z = 1;
  while (q > 0) {
    if (q % 2 == 1) z = (z * p) % mod97;
    p = (p * p) % mod97;
    q >>= 1;
  }
  return z;
}
long long int k1, k2;
long long int dp[101][101][11][11];
long long int getAns(long long int f, long long int h, long long int remk1,
                     long long int remk2) {
  if (f + h == 0) return 1;
  if (dp[f][h][remk1][remk2] != -1) return dp[f][h][remk1][remk2];
  long long int x = 0;
  if (f > 0 && remk1 > 0) x = getAns(f - 1, h, remk1 - 1, k2);
  long long int y = 0;
  if (h > 0 && remk2 > 0) y = getAns(f, h - 1, k1, remk2 - 1);
  dp[f][h][remk1][remk2] = (x + y) % mod97;
  return (x + y) % mod97;
}
int main() {
  int t;
  t = 1;
  while (t--) {
    long long int n1, n2;
    memset(dp, -1, sizeof(dp));
    cin >> n1 >> n2 >> k1 >> k2;
    cout << getAns(n1, n2, k1, k2) << "\n";
  }
  return 0;
}
