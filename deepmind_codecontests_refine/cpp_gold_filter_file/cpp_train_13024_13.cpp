#include <bits/stdc++.h>
using namespace std;
int MOD(int a, int b) {
  if (a > b)
    return a - b;
  else
    return b - a;
}
long long int max3(long long int a, long long int b, long long int c) {
  return max(c, max(a, b));
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int max(long long int a, long long int b) { return (a > b) ? a : b; }
long long int min(long long int a, long long int b) { return (a < b) ? a : b; }
long long int gcd(long long int a, long long int b) {
  if (b == 1)
    return 1;
  else if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
long long int mod(long long int x) {
  if (x >= 0)
    return x;
  else
    return -x;
}
long long int dp[501][501];
void calculate(int n, int h) {
  long long int res = 0;
  for (int i = 1; i <= n; i++) {
    res += (dp[i - 1][h - 1] * dp[n - i][h - 1]) % 1000000007;
  }
  dp[n][h] = res % 1000000007;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, s;
  cin >> n >> s;
  cout << (int)ceil((float)s / n);
  return 0;
}
