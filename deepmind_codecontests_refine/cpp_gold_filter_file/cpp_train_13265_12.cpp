#include <bits/stdc++.h>
using namespace std;
template <class T>
const T& max(const T& a, const T& b, const T& c) {
  return max(a, max(b, c));
}
template <class T>
const T& min(const T& a, const T& b, const T& c) {
  return min(a, min(b, c));
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long poww(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = poww(a, b / 2);
  return (b & 1 ? a * tmp * tmp : tmp * tmp);
}
long long sumOfDigs(string s) {
  long long sum = 0;
  for (int i = 0; i < s.length(); i++) sum += s[i] - '0';
  return sum;
}
long long sumOfDigs(long long n) {
  return (n < 10 ? n : n % 10 + sumOfDigs(n / 10));
}
string itos(long long i) {
  string s = "";
  while (i) {
    s += char(i % 10 + '0');
    i /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
long long stoi(string& s) {
  long long tot = 0;
  for (int i = (int)s.length() - 1, j = 1; i >= 0; i--, j *= 10) {
    tot += j * (s[i] + '0');
  }
  return tot;
}
int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
using namespace std;
void t() { freopen("test.txt", "r", stdin); }
long long mod = 1000 * 1000 * 1000 + 7;
;
long long modpower(long long x, long long y, long long p) {
  x %= mod;
  if (!y) return 1;
  long long res = 1;
  if (y & 1) {
    res *= x;
    res %= p;
  }
  long long z = modpower(x, y / 2, p);
  z %= p;
  z *= z;
  z %= mod;
  res *= z;
  res %= p;
  return res;
}
int dp[15001][501];
int ncr(int n, int r) {
  if (dp[n][r] != -1) return dp[n][r];
  if (n < r) return 0;
  if (r == 0) return 1;
  int& res = dp[n][r];
  res = ncr(n - 1, r - 1) % mod + ncr(n - 1, r) % mod;
  res %= mod;
  return res;
}
int main() {
  memset(dp, -1, sizeof(dp[0][0]) * 15001 * 501);
  int n;
  cin >> n;
  map<int, int> mpp;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for (int j = 2; j * j <= x; j++) {
      while (x % j == 0) {
        x /= j;
        mpp[j]++;
      }
    }
    if (x > 1) mpp[x]++;
  }
  long long tot = 1;
  for (auto itr = mpp.begin(); itr != mpp.end(); ++itr) {
    long long k = itr->second;
    tot *= ncr(n + k - 1, n - 1);
    tot %= mod;
  }
  cout << tot % mod << endl;
  return 0;
}
