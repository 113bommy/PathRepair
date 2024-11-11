#include <bits/stdc++.h>
using namespace std;
int shift = 1e5 + 2;
const int N = 101;
long long int dp[N][100001];
long long int n, k;
long long int *taste, *cal;
long long int Dimaandsalad(long long int i, long long int sum) {
  if (i == n) {
    if (sum == 0) return 0;
    return -1e12;
  }
  if (dp[i][sum + shift] != -1) {
    return dp[i][sum + shift];
  }
  long long int op1 =
      taste[i] + Dimaandsalad(i + 1, (taste[i] - k * cal[i]) + sum);
  long long int op2 = 0 + Dimaandsalad(i + 1, sum);
  dp[i][sum + shift] = max(op1, op2);
  return max(op1, op2);
}
int main() {
  cin >> n >> k;
  taste = new long long int[n];
  cal = new long long int[n];
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < n; i++) cin >> taste[i];
  for (int i = 0; i < n; i++) cin >> cal[i];
  long long int ans = Dimaandsalad(0, 0);
  if (ans <= 0)
    cout << -1;
  else
    cout << ans;
  cout << endl;
}
