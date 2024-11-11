#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
const long long Max = 1e16;
int n, A[maxn + 1], a, b;
vector<int> B;
long long Dp[maxn + 1][4], ans;
void Init(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) B.push_back(i);
    while (x % i == 0) x /= i;
  }
  if (x > 1) B.push_back(x);
}
void DP(int x) {
  for (int i = 1; i <= n; i++) {
    long long val = 1e16;
    if (A[i] % x == 0) val = 0;
    if ((A[i] + 1) % x == 0 || (A[i] - 1) % x == 0) val = b;
    Dp[i][1] = min(Dp[i - 1][1] + val, Max);
    Dp[i][2] = min(Max, min(Dp[i - 1][1], Dp[i - 1][2]) + a);
    Dp[i][3] =
        min(Max, min(Dp[i - 1][1], min(Dp[i - 1][2], Dp[i - 1][3])) + val);
  }
  ans = min(ans, min(Dp[n][1], min(Dp[n][2], Dp[n][3])));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = -1; i <= 1; i++) Init(A[1] + i), Init(A[n] + i);
  sort(B.begin(), B.end());
  B.erase(unique(B.begin(), B.end()), B.end());
  ans = Max;
  for (int i = 0; i < B.size(); i++) DP(B[i]);
  cout << ans;
  return 0;
}
