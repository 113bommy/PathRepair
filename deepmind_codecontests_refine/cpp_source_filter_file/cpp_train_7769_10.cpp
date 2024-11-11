#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
const long long P = 1000000000 + 7;
long long deg(long long x, long long d) {
  if (d < 0) d += P - 1;
  long long y = 1;
  while (d) {
    if (d & 1) (y *= x) %= P;
    (x *= x) %= P;
    d /= 2;
  }
  return y;
}
const int maxn = 1100;
long long dp[maxn][maxn];
long long A, B;
int k;
long long get_dp(int a, int b) {
  if (a + b >= k) {
    return (1 - deg(B, -1) + a) % P;
  }
  if (dp[a][b] >= 0) return dp[a][b];
  return dp[a][b] = (A * get_dp(a + 1, b) + B * (get_dp(a, a + b) + a)) % P;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  int pa, push_back;
  cin >> k >> pa >> push_back;
  A = pa * deg(pa + push_back, -1) % P;
  B = (P + 1 - A) % P;
  for (int i = 0; i < (int)(k + 1); ++i)
    for (int j = 0; j < (int)(k + 1); ++j) dp[i][j] = -1;
  cout << get_dp(1, 0) << '\n';
  return 0;
}
