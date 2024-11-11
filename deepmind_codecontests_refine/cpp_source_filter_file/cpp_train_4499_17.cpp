#include <bits/stdc++.h>
using namespace std;
const int N = 80;
long long fibo[N + 5];
long long dp[N + 5][3][3];
long long arr[N + 5];
void pre() {
  fibo[0] = 1, fibo[1] = 2;
  for (int i = 2; i <= N; i++) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }
}
long long solve(int idx, int cur1, int cur2) {
  if (idx == -1) {
    if (cur1 + cur2 != 0) return 0;
    return 1;
  }
  long long &res = dp[idx][cur1][cur2];
  if (res != -1) return res;
  res = 0;
  if (cur1 + arr[idx] > 2) return 0;
  if (cur1 + arr[idx] <= 1) res += solve(idx - 1, cur2, 0);
  if (cur1 + arr[idx] == 1) res += solve(idx - 1, cur2 + 1, 1);
  if (cur1 + arr[idx] == 2) res += solve(idx - 1, cur2 + 1, 1);
  return res;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  pre();
  int ntc;
  cin >> ntc;
  while (ntc--) {
    long long x;
    cin >> x;
    for (int i = N; i >= 0; i--) {
      arr[i] = 0;
      if (x < fibo[i]) continue;
      x -= fibo[i];
      arr[i] = 1;
    }
    memset(dp, -1, sizeof dp);
    cout << solve(N, 0, 0) << endl;
  }
}
