#include <bits/stdc++.h>
using namespace std;
const int N = 1100;
long long dp[N], c[N];
long long cal(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return x / i;
  }
  return 1;
}
int main() {
  for (int i = 1; i < N; i++) c[i] = cal(i);
  memset(dp, 0x3f, sizeof dp);
  dp[0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 2; j + i < N; j++) {
      dp[i + j] = min(dp[i + j], dp[i] + c[j]);
    }
  }
  int n;
  cin >> n;
  long long res = cal(n);
  for (int i = 2; n - i >= 2 && i < N; i++) {
    res = min(res, cal(n - i) + dp[i]);
  }
  cout << res;
}
