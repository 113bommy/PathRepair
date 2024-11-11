#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return b * a / gcd(a, b);
}
long long int abs1(long long int a) {
  if (a < 0)
    return -1 * a;
  else
    return a;
}
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int fast_pow(long long base, long long n, long long M) {
  if (n == 0) return 1;
  if (n == 1) return base;
  long long halfn = fast_pow(base, n / 2, M);
  if (n % 2 == 0)
    return (halfn * halfn) % M;
  else
    return (((halfn * halfn) % M) * base) % M;
}
long long int findMMI_fermat(long long int n, long long int M) {
  return fast_pow(n, M - 2, M);
}
const double PI = 3.14159265358979323846;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int s, x;
  cin >> s >> x;
  long long int dp[61][3];
  if (s & 1 == 1) {
    if (x & 1 == 1) {
      dp[0][0] = 2ll;
      dp[0][1] = 0;
    } else {
      dp[0][0] = 0ll;
      dp[0][1] = 0ll;
    }
  } else {
    if (x & 1 == 1) {
      dp[0][0] = 0ll;
      dp[0][1] = 0ll;
    } else {
      dp[0][0] = 1ll;
      dp[0][1] = 1ll;
    }
  }
  for (int i = 1; i <= 60; i++) {
    if ((s >> i) & 1) {
      if ((x >> i) & 1) {
        dp[i][0] = 2ll * dp[i - 1][0];
        dp[i][1] = 0;
      } else {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = dp[i - 1][1];
      }
    } else {
      if ((x >> i) & 1) {
        dp[i][0] = 0;
        dp[i][1] = 2ll * dp[i - 1][1];
      } else {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
      }
    }
  }
  if (x == s) dp[60][0] -= 2;
  cout << dp[60][0];
  return 0;
}
