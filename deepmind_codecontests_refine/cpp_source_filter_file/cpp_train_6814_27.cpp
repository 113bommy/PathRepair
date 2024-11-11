#include <bits/stdc++.h>
using namespace std;
int base = 10;
string s;
long long dp[22][200][2];
long long call(int pos, int sum, bool alreadySmall) {
  if (pos == (int)s.size()) return sum;
  if (dp[pos][sum][alreadySmall] != -1) return dp[pos][sum][alreadySmall];
  long long ret = 0;
  for (int i = 0; i < base; i++) {
    if (alreadySmall == false && i > s[pos] - '0') continue;
    int npos = pos + 1;
    bool nalreadySmall = alreadySmall | (i < s[pos] - '0');
    int nsum = sum + i;
    ret += call(npos, nsum, nalreadySmall);
  }
  return dp[pos][sum][alreadySmall] = ret;
}
string To_string(long long x) {
  string ret;
  while (x) {
    ret.push_back(x % base + '0');
    x /= base;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}
long long sum_of_digits(long long x) {
  long long ret = 0;
  while (x) {
    ret += x % base;
    x /= base;
  }
  return ret;
}
long long f(long long n) {
  s = To_string(n);
  memset(dp, -1, sizeof dp);
  return call(0, 0, 0);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long a;
  cin >> a;
  for (int k = 1; k <= 9; k++) {
    long long lo = 1, hi = 1.2e17;
    while (hi > lo) {
      long long mid = (hi + lo) / 2;
      if (f(mid) >= k * a) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    long long x = f(lo) % a;
    long long bal = lo;
    lo = 1, hi = 1.2e17;
    while (hi > lo) {
      long long mid = (hi + lo) / 2;
      if (f(mid) >= x) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    if (f(lo) == x) {
      cout << lo + 1 << " " << bal << "\n";
      return 0;
    }
  }
  return 0;
}
