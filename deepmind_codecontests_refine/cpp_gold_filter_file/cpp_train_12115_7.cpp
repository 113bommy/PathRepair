#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  while (b) {
    int c = a;
    a = b;
    b = c % b;
  }
  return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
const int M = 360400;
int dp[M], ep[M];
int main() {
  long long a, b;
  int k;
  cin >> a >> b >> k;
  int m = 2;
  for (int i = 3; i <= k; ++i) {
    m = lcm(m, i);
  }
  dp[0] = 0;
  for (int i = 1; i < m; ++i) {
    dp[i] = i;
    for (int j = 2; j <= k; ++j) {
      int u = i % j;
      dp[i] = min(dp[i], dp[i - u] + 1);
    }
  }
  long long u = b / m;
  b -= u * m;
  a -= u * m;
  ep[b] = 0;
  for (int i = b + 1; i < m; ++i) {
    ep[i] = i - b;
    for (int j = 2; j <= k; ++j) {
      int u = i % j;
      if (i - u >= b) ep[i] = min(ep[i], ep[i - u] + 1);
    }
  }
  long long ret;
  if (a < m) {
    ret = ep[a];
  } else {
    ret = dp[a % m] + (a - m) / m * (dp[m - 1] + 1) + 1 + ep[m - 1];
  }
  cout << ret << endl;
  return 0;
}
