#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592653689793238460;
const long long inf = 0x3f3f3f3f3f3f;
const int N = 2e5 + 5;
const int pr = 31;
using ld = long double;
int mod = 1e9 + 7;
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int fact(int n) {
  int res = 1;
  for (int i = 2; i <= n; i++) res = res * i % mod;
  return res % mod;
}
int ncr(int n, int r) { return fact(n) / (fact(r) * fact(n - r)); }
int power(long long x, unsigned int y, int p) {
  int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long nCr(long long n, long long k) {
  long long C[105][1005];
  long long i, j;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= min(i, k); j++) {
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
    }
  }
  return C[n][k];
}
unsigned int setbit(long long n) {
  unsigned long long count = 0;
  while (n) {
    n &= (n - 1);
    count++;
  }
  return count;
}
int sub(string s1, string s2) {
  int M = s1.length();
  int N = s2.length();
  for (int i = 0; i <= N - M; i++) {
    int j;
    for (j = 0; j < M; j++)
      if (s2[i + j] != s1[j]) break;
    if (j == M) return i;
  }
  return -1;
}
unsigned P2(unsigned x) {
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  return x ^ (x >> 1);
}
int dp[1000005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  ;
  {
    for (auto &qwertyuiop : a) cin >> qwertyuiop;
  };
  for (int i = 0; i < (int)n; i++) dp[a[i]] = 1;
  for (int i = (int)1; i <= (int)1000000; ++i) {
    if (dp[i] != 0) {
      for (int j = 2 * i; j < 1000000; j += i) {
        if (dp[j] != 0) {
          dp[j] = max(dp[j], dp[i] + 1);
        }
      }
    }
  }
  int ans = 0;
  for (int i = (int)1; i <= (int)1000000; ++i) {
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
}
