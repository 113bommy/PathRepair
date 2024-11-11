#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long sign(long long x) { return (x > 0) - (x < 0); }
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
long long power(long long a, long long b, long long MOD) {
  if (b == 0) {
    return 1;
  }
  long long x = power(a, b / 2, MOD);
  x = (x * x) % MOD;
  if (b % 2) {
    x = (x * a) % MOD;
  }
  return x;
}
bool isPalindrome(string str) {
  long long l = 0;
  long long h = str.length() - 1;
  while (h > l) {
    if (str[l++] != str[h--]) {
      return false;
    }
  }
  return true;
}
void kickstart(long long test) {
  cout << "Case #" << test << ": ";
  cout << "\n";
}
long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); }
float distance(int x1, int y1, int x2, int y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}
bool isPerfectSquare(long long x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
long long factorial(long long n) {
  if (n == 0) return 1;
  int i = n, fact = 1;
  while (n / i != n) {
    fact = fact * i;
    i--;
  }
  return fact;
}
long long dp[105];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  dp[1] = 1;
  dp[2] = 5;
  long long sum = 0;
  if (n == 1) {
    cout << dp[0];
  } else if (n == 2) {
    cout << dp[1];
  } else {
    for (long long i = 3; i <= n; i++) {
      dp[i] = (dp[i - 1] + 4 * (i - 1));
    }
    cout << dp[n];
  }
  return 0;
}
